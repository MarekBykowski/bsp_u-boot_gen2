#!/bin/bash

set -x

#Mareks ATF and Uboot
ATF_DIR=/workspace/sw/mbykowsx/lionfish/axxia_atf_private
UBOOT_DIR=/workspace/sw/mbykowsx/lionfish/axxia_u-boot_private
#ATF_DIR=
#UBOOT_DIR=
MKIMAGE=${UBOOT_DIR}/tools/mkimage

test -n "$ATF_DIR" || { echo "Tell me ATF directory"; exit -1; }
test -n "$UBOOT_DIR" || { echo "Tell me Uboot directory"; exit -1; }

atf_nokia() {
		echo "Building atf"
        test -n $1 || { return 127; }
        set -x
        BOARD="${1}=1"
        test -z $2 && TYPE="" || TYPE="${2}=1"
        pushd .
        local rc=0
        # clean uboot
        { cd $UBOOT_DIR && make distclean; } 
        # create spl dir in uboot for copying bl31 onto
        test -d $UBOOT_DIR || { rm -rf $UBOOT_DIR; mkdir -p $UBOOT_DIR; }
        cd $ATF_DIR
        if make distclean && make -j 24 PLAT=axxia USE_COHERENT_MEM=0 DEBUG=1 bl31; then
                ${CROSS_COMPILE}objcopy -I binary -O elf64-littleaarch64 -B aarch64 \
                    --rename-section .data=.monitor  \
					build/axxia/debug/bl31.bin build/axxia/debug/bl31.o
        else
                rc=127
        fi
        popd
        set +x
        return $rc
}

uboot_nokia() {
		echo "Building Uboot and SPL"
        test -n "$1" || { return 127; }
        local rc=0
        UBOOT=$1
        pushd .
        set +x
        cd $UBOOT_DIR
        if make distclean && cp ${ATF_DIR}/build/axxia/debug/bl31.o . && make ${UBOOT}_defconfig && make -j 24; then
                # for emulation -e 0x00027001. For simulation or hardware, -e 0x00197001
                $MKIMAGE -A arm64 -T firmware -C none -a 0 -e 0x00197001 -n XLOADER -d spl/u-boot-spl.bin spl/u-boot-spl.img
                $MKIMAGE -A arm64 -T firmware -C none -a 0 -e 0 -n XLOADER -d u-boot.bin u-boot.img

#: << EOM
tftp aus-labsrv2 << TFTP
put u-boot.img mbu-boot.img
put spl/u-boot-spl.img mbu-boot-spl.img
TFTP
#EOM

        else
               return 127
        fi
        set +x
        popd
        return 0

}

if [[ $1 == AXC6700 || $1 == axc6700 ]]; then
	atf_nokia AXC6700 && uboot_nokia axc6700
elif [[  $1 == AXM5600 || $1 == axm5600 ]]; then
	atf_nokia AXM5600 && uboot_nokia axm5600
else 
	echo "Unsupported architecture. Give AXC6700 or AXM5600"
fi
