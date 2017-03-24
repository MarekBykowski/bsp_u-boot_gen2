#!/usr/bin/perl -w
################################################################################
################################################################################
# convert.pl
#
# Convert the trace to a C function...
################################################################################
################################################################################

use Carp;
use English;
use Getopt::Long;
use File::Copy;

sub convert 
{
    my ($output, @input) = @ARG;

    open OUTPUT, ">$output" . ".c" or croak "Couldn't open $output";

    # Header
    print OUTPUT
	"static ncr_command_t $output" . "[] = {\n";

    foreach $line (@input) 
    {
		my $command;
		my $options;

		# skip blank lines
		if($line =~ '^$')
		{
			next;
		}

        # write comments out
		if($line =~ /^#/)
		{
		    # remove hash
		    $line =~ s/^#+//g;
		    
		    # remove space
		    $line =~ s/^\s+//g;
		    
		    # remove newline
		    $line =~ s/\n//g;

		    if($line ne '')
		    {
		        print OUTPUT "\n\t/* " . $line . " */\n";
		    }
		}
		elsif ($line =~ /([\w]+)\s+(.*)/x) 
		{
		    $command = $1;
		    $options = $2;

		    if ("ncpWrite" eq $command) 
		    {
				if ($2 =~ /([^\.]*)\.([^\.]*)\.([^\.]*)\.([^\s]*)\s+(.*)/x) 
				{
			    	my $node = sprintf("%d", $2);
				    my $target = sprintf("%d", $3);
				    my $offset = hex($4);
				    my @values = split(/ /, $5);
				    my $skip = 0;

			    	if ((31 == $node && 16 == $target) ||
						(23 == $node && 16 == $target)) 
					{
						my @skip_offsets =
				    		(160, 164, 168, 172, 176, 180, 184, 188);

						foreach $skip_offset (@skip_offsets) 
						{
				    		if ($offset == $skip_offset) 
				    		{
								$skip = 1;
				    		}
						}
			    	}

			    	if ((31 == $node && 18 == $target) ||
						(23 == $node && 18 == $target)) 
					{
						my @skip_offsets =
						    (772, 776, 836, 840, 844, 848, 852, 964, 968,
						     1028, 1032, 1036, 1040, 1044, 1156, 1160, 1220,
						     1224, 1228, 1232, 1236, 1348, 1352, 1412, 1416,
						     1420, 1424, 1428);
						my $skip_offset;

						foreach $skip_offset (@skip_offsets) 
						{
						    if ($offset == $skip_offset) 
						    {
								$skip = 1;
				    		}
						}
			    	}

			    	if (1 != $skip) 
			    	{
						foreach $value (@values) 
						{
						    print OUTPUT
							"\t{NCR_COMMAND_WRITE, " .
							"NCP_REGION_ID($node, $target), " .
							sprintf("{.offset = 0x%08x}, 0x%08x, 0},\n",
								$offset, hex($value));
						    $offset += 4;
						}
			    	}
				} 
				else 
				{
			    	croak "Unable to parse $2";
				}
		    } 
		    elsif ("ncpRead" eq $command) 
		    {
				if ($2 =~ /
					([^\.]*)\.([^\.]*)\.([^\.]*)\.([^\s]*)/x) 
				{
					my $node = sprintf("%d", $2);
					my $target = sprintf("%d", $3);
					my $offset = hex($4);

					print OUTPUT
					"\t{NCR_COMMAND_USLEEP, 0, {.offset = 0}, 1000, 0},\n";

					print OUTPUT
					"\t{NCR_COMMAND_READ, " .
					"NCP_REGION_ID($node, $target), " .
					sprintf("{.offset = 0x%08x}, 0, 0},\n", $offset);
				}
		    } 
		    elsif ("ncpModify" eq $command) 
		    {
				if ($2 =~ /
				    ([^\.]*)\.([^\.]*)\.([^\.]*)\.([^\s]*)\s+([\S]*)\s+([\S]*)
				    /x) 
				{
				    my $node = sprintf("%d", $2);
				    my $target = sprintf("%d", $3);
				    my $offset = hex($4);
				    my $mask = hex($5);
				    my $value = hex($6);

				    print OUTPUT
					"\t{NCR_COMMAND_MODIFY, " .
					"NCP_REGION_ID($node, $target), " .
					sprintf("{.offset = 0x%08x}, 0x%08x, 0x%08x},\n",
						$offset, $value, $mask);
				} 
				else 
				{
			    	croak "Unable to parse $2";
				}
		    } 
		    elsif ("ncpUsleep" eq $command) 
		    {
				my $value = sprintf("%d", $2);

				print OUTPUT
				    "\t{NCR_COMMAND_USLEEP, 0, {.offset = 0}, $value, 0},\n";
		    } 
		    elsif ("ncpPoll" eq $command) 
		    {
				if ($2 =~ /
				    \-l\s+([\S]+)\s+                          # Loops
				    \-t\s+([\S]+)\s+                          # Timeout
				    ([^\.]*)\.([^\.]*)\.([^\.]*)\.([^\.]*)\s+ # d.n.t.o
				    ([\S]+)\s+	                              # Mask
				    ([\S]+)	                              # Value
				    /x) 
				{
				    my $node = sprintf("%d", $4);
				    my $target = sprintf("%d", $5);
				    my $offset = hex($6);
				    my $mask = hex($7);
				    my $value = hex($8);
				    print OUTPUT
					"\t{NCR_COMMAND_POLL, " .
					"NCP_REGION_ID($node, $target), " .
					sprintf("{.offset = 0x%08x}, 0x%08x, 0x%08x},\n",
						$offset, $mask, $value);
				} 
				else
				{
				    croak "Unable to parse $2";
				}
		    }
		} 
		else 
		{
		    croak "Unable to Parse $line";
		    close OUTPUT;
		    exit 1;
		}
    }

    # Footer
    print OUTPUT
	"\t{NCR_COMMAND_NULL, 0, {.offset = 0}, 0, 0}\n" .
	"};\n";

    close OUTPUT;
}

GetOptions("input=s" => \$input);
open INPUT, $input or croak "Couldn't open $input";
@input = <INPUT>;
close INPUT;

open TRACE, ">all.trace" or croak "Couldn't open all.trace";
print TRACE @input;
close TRACE;
convert("all", @input);

exit 0;
