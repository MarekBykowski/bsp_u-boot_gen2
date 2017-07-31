#
# (C) Copyright 2000, 2001, 2002
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

ifndef CONFIG_SPL_BUILD

################################################################################
## Normal Build

obj-y += qos.o 

ifdef CONFIG_AXXIA_EIOA
ccflags-y += -D_GNU_SOURCE -DNCP_USE_NVM -DNCP_MULTI_THREAD -DNCP_LINUX -DUSE_NCAV3 -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-int -Wno-unused-label -I$(srctree)/board/axxia/axc6700/ncatask/include -I$(srctree)/board/axxia/axc6700/ncatask/include/uboot/
#CFLAGS_eioa.o += -I$(src)/ncatask/include
obj-y += ncatask/
obj-y += mdio.o eioa.o
endif

else

################################################################################
## SPL Build

obj-y += secure.o ncp_l3lock_region_init.o

ifdef CONFIG_AXXIA_EMU
obj-y += sysmem_emulation.o
endif

endif

################################################################################
## All Builds

obj-y += failure.o version.o spi.o
