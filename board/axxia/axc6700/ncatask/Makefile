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
ccflags-y += -I$(srctree)/board/axxia/axc6700/ncatask/include -I$(srctree)/board/axxia/axc6700/ncatask/include/uboot/
#ccflags-y += -Wno-unused-but-set-variable -Wno-unused-variable -Wno-maybe-uninitialized -Wno-error=int-conversion
obj-y += ncatask/ncp.o ncatask/ncp_vpm.o
endif

