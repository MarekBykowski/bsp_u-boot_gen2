################################################################################
#
# Copyright (C) 2015 Intel (john.jacques@intel.com)
#
# This program is free software;you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation;either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY;without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program;if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#
################################################################################

ifndef CONFIG_SPL_BUILD

################################################################################
## Normal Build

obj-y += axxia.o extmemmpr.o

ifdef CONFIG_AXXIA_PCI
obj-y += pei.o
endif

else

################################################################################
## SPL Build

obj-y += sysmem_reset.o spl.o axxia_initialize.o sysmem_bist.o cmem_bist.o

ifndef CONFIG_AXXIA_EMU
obj-y += ncp_sm_denali_2041_init_56xx.o ncp_sysmem_init_synopphy.o
obj-y += ncp_cm_ctrl_init_56xx.o ncp_treemem_init_synopphy.o ncp_elm.o
obj-y += sysmem_asic.o voltage.o
endif

ifdef CONFIG_AXXIA_SPL_DIAGNOSTICS
obj-y += spl_diagnostics.o
endif

endif

################################################################################
## All Builds

obj-y += lsi.o ncr.o sysmem_size.o parameters.o sbb.o axxia_clocks.o
obj-y += cache.o outer_cache.o gpdma.o lowlevel.o

ifdef CONFIG_HW_WATCHDOG
obj-y += watchdog.o
endif
