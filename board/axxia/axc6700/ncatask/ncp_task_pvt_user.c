/**************************************************************************
 **                                                                       *
 **    Copyright (c) 2001-2015, Intel Corporation.                        *
 **                                                                       *
 **************************************************************************/

#include <common.h>
#include "uboot/ncp_sal_types_linux.h"
#include "uboot/ncp_status.h"
#include "uboot/ncp_task_basetypes.h"

#include "uboot/ncp.h"
#include "uboot/ncp_pvt.h"

#include "uboot/ncp_cow_ext.h"
#undef  NCP_TASK_NCA_GLOBALS
#include "uboot/ncp_dev_pvt.h"
#include "uboot/ncp_task_pvt.h"
#include "uboot/ncp_ncav3_pvt.h"

#if defined(NCP_DEV_SOCKET)
#include "uboot/ncp_task_socket.h"
#else
#include "uboot/ncp_task_hw.h"
#endif

#if !defined(NCP_DEV_SOCKET) && !defined(NCP_DEV_FBRS) && !defined(NCP_DEV_FBDEV)
#include "uboot/ncp_task_inline_funcs.h"
#endif


ncp_st_t
ncp_task_os_pid_match_check(ncp_task_process_info_t *pProcess, ncp_bool_t expectedResult, ncp_st_t specificError)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_pid_t myPid = 0;
    
    NCP_CALL(ncp_task_getpid(&myPid));
    
    /* Caller specified wheth pid should match or not */
    if (expectedResult != (myPid == pProcess->osPid))
    {
        NCP_CALL(specificError);
    }        
    
NCP_RETURN_LABEL
    return(ncpStatus);        
}    

ncp_st_t
ncp_task_os_pid_store(ncp_task_process_info_t *pProcess)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    
    NCP_CALL(ncp_task_getpid(&pProcess->osPid));
    
NCP_RETURN_LABEL
    return(ncpStatus);    
}    



/*
 * This function is a debug-only hook that allows gdb to read MMAPed memory,   which is otherwise
 * not accessable by GDB,  as gdb runs as a separate process.
 *
 * when debugging with gdb,   use "call ncp_task_gdb_read(<addr>, <len>)"
 *
 * Example: (gdb)call ncp_task_gdb_read(0x3001d130, 100)
 *
 */

void ncp_r64(ncp_uint64_t *addr, int len)
{
    int i=0;

    printf("ADDR=%p:\r\n", addr);

    while(len)
    {
        printf("0x%llx ", (long long unsigned int) *addr++);
        len--;
        i++;
        if (8 == i)
        {
            i = 0;
            printf("\r\n");
        }
    }
    printf("\r\n");
    return;
}

/*
 * This function is a debug-only hook that allows gdb to read MMAPed memory,   which is otherwise
 * not accessable by GDB,  as it runs as a separate process.
 *
 * when debugging with gdb,   use "call ncp_task_gdb_read(<addr>, <len>)"
 *
 * Example: (gdb)call ncp_task_gdb_read(0x3001d130, 100)
 *
 */
void ncp_r32(ncp_uint32_t *addr, int len)
{
    int i=0;

    printf("ADDR=%p:\r\n", addr);

    while(len)
    {
        printf("%8X ", *addr++);
        len--;
        i++;
        if (16 == i)
        {
            i = 0;
            printf("\r\n");
        }
    }
    printf("\r\n");
    return;
}

/*
 * This function is a debug-only hook that allows gdb to read MMAPed memory,   which is otherwise
 * not accessable by GDB,  as it runs as a separate process.
 *
 * when debugging with gdb,   use "call ncp_task_gdb_read(<addr>, <len>)"
 *
 * Example: (gdb)call ncp_task_gdb_read(0x3001d130, 100)
 *
 */
void ncp_r16(ncp_uint16_t *addr, int len)
{
    int i=0;

    printf("ADDR=%p:\r\n", addr);

    while(len)
    {
        printf("%8X ", *addr++);
        len--;
        i++;
        if (32 == i)
        {
            i = 0;
            printf("\r\n");
        }
    }
    printf("\r\n");
    return;
}

void ncp_r8(ncp_uint8_t *addr, int len)
{
    int i=0;

    printf("ADDR=%p:\r\n", addr);

    while(len)
    {
        printf("%2X ", *addr++);
        len--;
        i++;
        if (32 == i)
        {
            i = 0;
            printf("\r\n");
        }
    }
    printf("\r\n");
    return;
}


/*
 * The following functions provide a debug-only hook that allows gdb to write MMAPed memory,   which is otherwise
 * not accessable by GDB,  as it runs as a separate process.
 *
 * when debugging with gdb,   use "call ncp_task_gdb_mmio_writeXX(<addr>, <data>)"
 *
 * Example: (gdb)call ncp_task_gdb_read(0x3001d130, 100)
 *
 */
void ncp_w8(ncp_uint8_t *addr, ncp_uint8_t data)
{
    *addr = data;
    printf("Addr 0x%p now contains data=0x%hhx\r\n",addr, *addr);
    return;
}

void ncp_w16(ncp_uint16_t *addr, ncp_uint16_t data)
{
    *addr = data;
    printf("Addr 0x%p now contains data=0x%hx\r\n",addr, *addr);
    return;
}

void ncp_w32(ncp_uint32_t *addr, ncp_uint32_t data)
{
    *addr = data;
    printf("Addr 0x%p now contains data=0x%x\r\n",addr, *addr);
    return;
}

void ncp_w64(ncp_uint64_t *addr, ncp_uint64_t data)
{
    *addr = data;
    printf("Addr 0x%p now contains data=0x%llx\r\n",addr, (long long unsigned int) *addr);
    return;
}

#if 0 /* Add swap macros and enable only if required */
void ncp_r32_swap(ncp_uint32_t *addr, int len)
{
    int i=0;

    printf("ADDR=%p:\r\n", addr);

    while(len)
    {
        printf("%8X ", SWAP_32(*addr));
        addr++;
        len--;
        i++;
        if (16 == i)
        {
            i = 0;
            printf("\r\n");
        }
    }
    printf("\r\n");
    return;
}

void ncp_r64_swap(ncp_uint64_t *addr, int len)
{
    int i=0;

    printf("ADDR=%p:\r\n", addr);

    while(len)
    {
        printf("%8llX ", (long long unsigned int)SWAP_64(*addr));
        addr++;
        len--;
        i++;
        if (8 == i)
        {
            i = 0;
            printf("\r\n");
        }
    }
    printf("\r\n");
    return;
}

void ncp_r16_swap(ncp_uint16_t *addr, int len)
{
    int i=0;

    printf("ADDR=%p:\r\n", addr);

    while(len)
    {
        printf("%8X ", SWAP_16(*addr));
        addr++;
        len--;
        i++;
        if (32 == i)
        {
            i = 0;
            printf("\r\n");
        }
    }
    printf("\r\n");
    return;
}
#endif /* #if 0 Add swap macros and enable only if required */
 

