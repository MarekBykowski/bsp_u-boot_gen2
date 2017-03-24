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
				# Reads are ignored for all but hss. They introduce necessary delays. 
				if("hss" eq $architecture)
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
    				else 
    				{
    			    	croak "Unable to parse $2";
    				}
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

$architecture = "3400";

GetOptions("input=s" => \$input,
	       "architecture=s" => \$architecture,
	       "output=s" => \$outfile);

open INPUT, $input or croak "Couldn't open $input";
@input = <INPUT>;
close INPUT;

@mmb = ();
@vp = ();
@nca = ();
@timer = ();
@tdmioa = ();
@eioa = ();
@hss = ();

# MMB is "# Begin: Engines.MMB" to "# End:   Engines.MMB"
# VP is "# Begin: VirtualPipelines" to "# End:   VirtualPipelines"
# NCA is "# Begin: Engines.NCA" to "# End:   Engines.NCA"

## If target is 2500
# TIMER is "# Begin: Engines.Timer" to "# End:   Engines.Timer"
# TDMIOA is "# Begin: Engines.TDMIOA" to "# End:   Engines.TDMIOA"

## If target is 3400, EIOA will contain EIOA0 and EIOA1 as follows.
# EIOA0 is "# Begin: Engines.EIOA0" to "# End:   Engines.EIOA0"
# EIOA1 is "# Begin: Engines.EIOA1" to "# End:   Engines.EIOA1"

## If target is 2500, EIOA will contain the EIOA section.
# EIOA is "# Begin: Engines.EIOA" to "# End:   Engines.EIOA"

if ("hss" eq $architecture)
{
    $state = "hss";
}
elsif ("5500" eq $architecture) 
{
    $state = "looking for mme";
}
else
{
    $state = "looking for mmb";
}

foreach $line (@input) 
{
    #print "Processing: ($state) $line";

    if ("hss" eq $state) 
    {
#		if ($line !~ '^#' && $line !~ '^$') 
        if ($line !~ '^$') 
		{
	    	push @hss, $line;
		}
		next;
    } 
    elsif ("looking for mmb" eq $state) 
    { # MMB
		next if $line !~ '^# Begin: Engines.MMB';
		$state = "mmb";
    } 
    elsif ("mmb" eq $state) 
    {
		if ($line =~ '^# End:   Engines.MMB') 
		{
	    	$state = "looking for vp";
	    	next;
		}

#		if ($line !~ '^#' && $line !~ '^$') 
        if ($line !~ '^$') 
		{
	    	push @mmb, $line;
		}
    } 
    elsif ("looking for mme" eq $state) 
    { # MMB
		next if $line !~ '^# Begin: Engines.MME';
		$state = "mme";
    } 
    elsif ("mme" eq $state) 
    {
		if ($line =~ '^# End:   Engines.MME') 
		{
	    	$state = "looking for pbm";
	    	next;
		}

#		if ($line !~ '^#' && $line !~ '^$') 
		if ($line !~ '^$') 
		{
	    	push @mme, $line;
		}
    } 
    elsif ("looking for pbm" eq $state) 
    { # MMB
		next if $line !~ '^# Begin: PBM';
		$state = "pbm";
    } 
    elsif ("pbm" eq $state) 
    {
		if ($line =~ '^# End:   PBM') 
		{
	    	$state = "looking for vp";
	    	next;
		}

#		if ($line !~ '^#' && $line !~ '^$') 
		if ($line !~ '^$') 
		{
	    	push @pbm, $line;
		}
    } 
    elsif ("looking for vp" eq $state) 
    { # VP
		next if $line !~ '^# Begin: VirtualPipelines';
		$state = "vp";
    } 
    elsif ("vp" eq $state) 
    {
		if ($line =~ '^# End:   VirtualPipelines') 
		{
	    	$state = "looking for nca";
	    	next;
		}

#		if ($line !~ '^#' && $line !~ '^$') 
		if ($line !~ '^$') 
		{
	    	push @vp, $line;
		}
    } 
    elsif ("looking for nca" eq $state) 
    { # NCA
		next if $line !~ '^# Begin: Engines.NCA';
		$state = "nca";
    } 
    elsif ("nca" eq $state) 
    {
		if ($line =~ '^# End:   Engines.NCA') 
		{
	    	if ("3400" eq $architecture) 
	    	{
				$state = "looking for eioa0";
	    	} 
	    	elsif ("2500" eq $architecture) 
	    	{
				$state = "looking for timer";
	    	}
	    	elsif ("5500" eq $architecture) 
	    	{
				$state = "looking for eioa";
	    	}

	    	next;
		}

#		if ($line !~ '^#' && $line !~ '^$') 
		if ($line !~ '^$') 
		{
	    	push @nca, $line;
		}
    } 
    elsif ("looking for eioa0" eq $state) 
    { # EIOA0 (3400 only)
		next if $line !~ '^# Begin: Engines.EIOA0';

		$state = "eioa0";
    } 
    elsif ("eioa0" eq $state) 
    {
		if ($line =~ '^# End:   Engines.EIOA0') 
		{
	    	$state = "looking for eioa1";
	    	next;
		}

#		if ($line !~ '^#' && $line !~ '^$') 
		if ($line !~ '^$') 
		{
	    	push @eioa, $line;
		}
    } 
    elsif ("looking for eioa1" eq $state) 
    { # EIOA1 (3400 only)
		next if $line !~ '^# Begin: Engines.EIOA1';

		$state = "eioa1";
    } 
    elsif ("eioa1" eq $state) 
    {
		if ($line =~ '^# End:   Engines.EIOA1') 
		{
	    	$state = "done";
		    next;
		}

#		if ($line !~ '^#' && $line !~ '^$') 
		if ($line !~ '^$') 
		{
	    	push @eioa, $line;
		}
    } 
    elsif ("looking for timer" eq $state) 
    { # TIMER (2500 only)
		next if $line !~ '^# Begin: Engines.Timer';

		$state = "timer";
    } 
    elsif ("timer" eq $state) 
    {
		if ($line =~ '^# End:   Engines.Timer') 
		{
	    	$state = "looking for tdmioa";
	    	next;
		}

#		if ($line !~ '^#' && $line !~ '^$') 
		if ($line !~ '^$') 
		{
	    	push @timer, $line;
		}
    } 
    elsif ("looking for tdmioa" eq $state) 
    { # TDMIOA (2500 only)
		next if $line !~ '^# Begin: Engines.TDMIOA';

		$state = "tdmioa";
    } 
    elsif ("tdmioa" eq $state) 
    {
		if ($line =~ '^# End:   Engines.TDMIOA') 
		{
	    	$state = "looking for eioa";
	    	next;
		}

#		if ($line !~ '^#' && $line !~ '^$') 
		if ($line !~ '^$') 
		{
	    	push @tdmioa, $line;
		}
    } 
    elsif ("looking for eioa" eq $state) 
    { # EIOA (2500 and 5500 only)
		next if $line !~ '^# Begin: Engines.EIOA';

		$state = "eioa";
    } 
    elsif ("eioa" eq $state)
    {
		if ($line =~ '^# End:   Engines.EIOA') 
		{
	    	$state = "done";
	    	next;
		}

#		if ($line !~ '^#' && $line !~ '^$') 
		if ($line !~ '^$') 
		{
	    	push @eioa, $line;
		}
    } 
    else 
    {
		last;
    }
}

## Handle 0.465.0 Accesses

if ("2500" eq $architecture) 
{
    @new_eioa = ();
    $polling = 0;

    for ($i = 0; $i < scalar(@eioa); ++$i) 
    {
		my $line = $eioa[$i];

		if ($line !~ '465\.0\.') 
		{
		    if (0 == $polling) 
		    {
				push @new_eioa, $line;
		    }

		    next;
		}

		my @command = ();
		my @offset = ();
		my @value = ();

		$line =~ /(ncp\w+)\W+0\.465\.0\.(\w+)\W(\w+)\n/m;
		$command[0] = $1;
		$offset[0] = $2;
		$value[0] = $3;

		++$i;
		$line = $eioa[$i];
		$line =~ /(ncp\w+)\W+0\.465\.0\.(\w+)\W(\w+)\n/m;
		$command[1] = $1;
		$offset[1] = $2;
		$value[1] = $3;

		++$i;
		$line = $eioa[$i];
		$line =~ /(ncp\w+)\W+0\.465\.0\.(\w+)\W(\w+)\n/m;
		$command[2] = $1;
		$offset[2] = $2;
		$value[2] = $3;

		++$i;
		$line = $eioa[$i];
		$line =~ /(ncp\w+)\W+0\.465\.0\.(\w+)\W(\w+)\n/m;
		$command[3] = $1;
		$offset[3] = $2;
		$value[3] = $3;

#    	print "--> " .
#		$command[0] . ":" . $command[1] . ":" . $command[2] . ":" . $command[3] .
#			"\n\t" .
#			$offset[0] . ":" . $offset[1] . ":" . $offset[2] . ":" . $offset[3] .
#			"\n\t" .
#			$value[0] . ":" . $value[1] . ":" . $value[2] . ":" . $value[3] .
#			"\n";

		if ("ncpWrite" eq $command[1]) 
		{
		    #print "--> Simple Write\n";
		    my $target = hex($offset[0]) / 16;
		    my $offset = hex($value[1]) & hex("0xffff");
		    my $command = sprintf("ncpWrite   0.465.%d.0x%08x 0x%08x\n",
					  $target, $offset, hex($value[0]));
		    #printf "offset=$offset\n";
		    push @new_eioa, $command;
		    $polling = 0;
		} 
		else 
		{
		    ##
		    # Should poll for pll lock, and phy ready...
		    #
		    # For pll lock, wait for
		    #   (value>>28 & 0x1) == 0x1
		    #
		    # For phy ready, wait for
		    #   (value>>16 & 0xff) == 0xff
		    ##

		    next if 0 != $polling;

		    #print "--> Read...\n";
		    if (84 == hex($offset[0])) 
		    {
				push @new_eioa,
				"ncpPoll -l 100 -t 100 0.465.5.0x0000000030 0x10000000 0x10000000\n";
				push @new_eioa,
				"ncpPoll -l 100 -t 100 0.465.5.0x0000000030 0x00ff0000 0x00ff0000\n";
				++$i;
				$polling = 1;
		    } 
		    elsif (116 == hex($offset[0])) 
		    {
				push @new_eioa,
				"ncpPoll -l 100 -t 100 0.465.7.0x0000000030 0x10000000 0x10000000\n";
				push @new_eioa,
				"ncpPoll -l 100 -t 100 0.465.7.0x0000000030 0x00ff0000 0x00ff0000\n";
				++$i;
				$polling = 1;
		    } 
		    elsif (148 == hex($offset[0])) 
		    {
				push @new_eioa,
				"ncpPoll -l 100 -t 100 0.465.9.0x0000000030 0x10000000 0x10000000\n";
				push @new_eioa,
				"ncpPoll -l 100 -t 100 0.465.9.0x0000000030 0x00330000 0x00330000\n";
				++$i;
				$polling = 1;
		    }
		}
    }

    @eioa = @new_eioa;
}

############################
## Save the stripped traces.

if("hss" eq $architecture)
{
    convert($outfile, @hss);
}
else
{
    if("5500" eq $architecture)
    {
        # MME
        open TRACE, ">mme.trace" or croak "Couldn't open mme.trace";
        print TRACE @mme;
        close TRACE;
        convert("mme", @mme);

        # PBM
        open TRACE, ">pbm.trace" or croak "Couldn't open pbm.trace";
        print TRACE @pbm;
        close TRACE;
        convert("pbm", @pbm);
    }
    else
    {
        # MMB
        open TRACE, ">mmb.trace" or croak "Couldn't open mmb.trace";
        print TRACE @mmb;
        close TRACE;
        convert("mmb", @mmb);
    }

    # VP
    open TRACE, ">vp.trace" or croak "Couldn't open vp.trace";
    print TRACE @vp;
    close TRACE;
    convert("vp", @vp);

    # NCA
    open TRACE, ">nca.trace" or croak "Couldn't open nca.trace";
    print TRACE @nca;
    close TRACE;
    convert("nca", @nca);

    if ("2500" eq $architecture) 
    {
        # TIMER
        open TRACE, ">timer.trace" or croak "Couldn't open timer.trace";
        print TRACE @timer;
        close TRACE;
        convert("timer", @timer);

        # TDMIOA
        open TRACE, ">tdmioa.trace" or croak "Couldn't open tdmioa.trace";
        print TRACE @tdmioa;
        close TRACE;
        convert("tdmioa", @tdmioa);
    }

    # EIOA
    open TRACE, ">eioa.trace" or croak "Couldn't open eioa.trace";
    print TRACE @eioa;
    close TRACE;
    convert("eioa", @eioa);
}

exit 0;
