/**************************************************************************
 **                                                                       *
 **    Copyright (c) 2001-2015, Intel Corporation.                        *
 **                                                                       *
 **************************************************************************/

#include "uboot/ncp_sal_types_linux.h"
#include "uboot/ncp_status.h"
#include "uboot/axxia.h"
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

/*
 * ======================================================================================================
 * Start of PMU Support funtions
 * ====================================================================================================== 
 */

#ifdef NCP_NCA_ARM_PMU_PROFILING_ENABLED

/*
 * Returns number of counters available for use
 * Note: There appears to be a bug in the coretil express where
 * only the first 3 counters work,   event though the h/w advertises
 * 6 and the A15 documentation specifies 6 as well.
 */
 
extern ncp_st_t
ncp_enable_pmu_usermode(
    ncp_dev_hdl_t dev);


ncp_st_t
ncpTaskArmPmuEnable(int *pNumCounters)  
{ 
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    unsigned int pmuUserEnab;

    NCP_CALL(ncp_enable_pmu_usermode(myDevHdl));
   
    /* is pmu access allowed from user mode? */
    pmuUserEnab = readPMUusrEnabReg();
    if (!pmuUserEnab)
    {
        printf("ERROR: PMU userEnable=0x%x, exiting!\r\n",pmuUserEnab); 
        NCP_CALL(NCP_ST_PMU_USER_ENABLE_ERR);                   
    }
    else
    {
        printf("PMU userEnable=0x%x\r\n",pmuUserEnab);        
    }  

    /* 
     * Enable the PMU                  
     */ 
    printf("Enable PMU\r\n");
    if (0 == enable_pmu())
    {
        printf("ERROR: PMU Enable returned bitVal==0, exiting!\r\n");        
        NCP_CALL(NCP_ST_PMU_USER_ENABLE_ERR);
    }  
    
    printf("Turn off ccnt divider\r\n");
    /* 
     * Make sure cycle count divider is OFF 
     */     
    ccnt_divider(0);             
    
#if 0   /* Not allowed from user mode */  
    /* 
     * Disable all pmu interrupts
     */
     
    disable_ccnt_irq();
    disable_pmn_irq(0);
    disable_pmn_irq(1);
    disable_pmn_irq(2);
    disable_pmn_irq(3);
    disable_pmn_irq(4);
    disable_pmn_irq(5);  
#endif
                       
    /*
     * Get # of PMU counters supported by this chip
     */
    *pNumCounters = getPMN();
    printf("This processor supports %d event counters\r\n", *pNumCounters);

NCP_RETURN_LABEL
        
    return(ncpStatus);
}

void
ncpTaskArmPmuInitCounters(int numPmuEvents,
                          ncp_uint32_t *pmuEventCodes)
{
    if(numPmuEvents > 0)
    { 
        
        /* 
         * Note: split config and enable in order to match ARM example code.
         * We are seeing unexpected beahvior,   so we'll see if this helps.
         */
         
        switch(numPmuEvents)
        {
        case 6:
             pmn_config(5,pmuEventCodes[5]);
        case 5:
             pmn_config(4,pmuEventCodes[4]);
        case 4:
             pmn_config(3,pmuEventCodes[3]);
        case 3:
             pmn_config(2,pmuEventCodes[2]);
        case 2:
             pmn_config(1,pmuEventCodes[1]);
        case 1:
             pmn_config(0,pmuEventCodes[0]);  
             break;                                    
             
        default:
            printf("unexpected numPmuEvents value in ncpTaskArmPmuInitCounters(config)\r\n");
        } /* switch */
        
        
        switch(numPmuEvents)
        {
        case 6:
             enable_pmn(5); 
        case 5:
             enable_pmn(4);          
        case 4:
             enable_pmn(3);          
        case 3:
             enable_pmn(2);          
        case 2:
             enable_pmn(1);          
        case 1:
             enable_pmn(0);  
             break;                                    
             
        default:
            printf("unexpected numPmuEvents value in ncpTaskArmPmuInitCounters (enable)\r\n");
        } /* switch */        

        enable_ccnt();             /* Enable CCNT                     */    reset_pmn();               /* Reset Counters */  
        reset_ccnt();              /* Reset the CCNT (cycle counter)  */          

      
    }  /* if(numPmuEvents > 0) */
    return;
}  
              
void
ncpTaskArmPmuResetCounters(void)
{
    reset_pmn();               /* Reset Counters */  
    reset_ccnt();              /* Reset the CCNT (cycle counter)  */        
    return;
}

void  
ncpTaskArmPmuStoreResults(ncpTaskArmPmuResults_t *pPmuResults,
                          int numPmuEvents,
                          ncp_uint32_t *pmuEventCodes,
                          const char *txtString)
{
    
       
    if(numPmuEvents > 0)
    {   
        pPmuResults->cycle_count = read_ccnt(); /* Read CCNT       */
        switch(numPmuEvents)
        {
        case 6:
            pPmuResults->val[5]    = read_pmn(5);        
        case 5:
            pPmuResults->val[4]    = read_pmn(4);        
        case 4:
            pPmuResults->val[3]    = read_pmn(3);
        case 3:
            pPmuResults->val[2]    = read_pmn(2);        
        case 2:
            pPmuResults->val[1]    = read_pmn(1);        
        case 1:
            pPmuResults->val[0]    = read_pmn(0);        
            
            memcpy(&pPmuResults->name[0], txtString, strlen(txtString));
            
            break;
                                
        default:
            break;
        }
    } 
    return;
}  

void
ncpTaskArmPmuDisplayStoredResults(ncpTaskArmPmuResults_t *pPmuResultsStart,
                                  ncpTaskArmPmuResults_t *pPmuResults,
                                  int numEntries, 
                                  int numPmuEvents, 
                                  ncp_uint32_t *pmuEventCodes)
{
    
    ncpTaskArmPmuResults_t *pResults = pPmuResultsStart;
    /* For better formatting */
    int                     i=0; 
    int                     gMinCycles=0;
    
        
    while( pResults != pPmuResults )
    {
        int j;
        
        /* Apply cycles filter to results */
        if (pResults->cycle_count >= gMinCycles)
        {    
            printf("T%08d", i);
            printf("%24.24s ", pResults->name); 
            for (j=0; j<numPmuEvents; j++)   
            {
                printf("e_0x%02X=%8d ", pmuEventCodes[j],pResults->val[j]);
            }
            printf("cycles=%8d\r\n", pResults->cycle_count); 
        }
        i++;        
        pResults++; 
               
    }  

    return;
}                       

#else
ncp_st_t
ncpTaskArmPmuEnable(int *pNumCounters)   
{ 
    return(NCP_ST_SUCCESS);
} 
void
ncpTaskArmPmuInitCounters(int numPmuEvents,
                          ncp_uint32_t *pmuEventCodes)
{
    return;   
}
void
ncpTaskArmPmuResetCounters(void)
{
    return;
} 
void  
ncpTaskArmPmuStoreResults(ncpTaskArmPmuResults_t *pPmuResults,
                          int numPmuEvents,
                          ncp_uint32_t *pmuEventCodes,
                          unsigned char *txtString)
{
    return;
}  

void
ncpTaskArmPmuDisplayStoredResults(ncpTaskArmPmuResults_t *pPmuResultsStart, 
                                  ncpTaskArmPmuResults_t *pPmuResults,
                                  ncp_uint64_t numEntries, 
                                  int numPmuEvents,
                                  ncp_uint32_t *pmuEventCodes)
{
    return;
}  
     
#endif 
/*
 * ======================================================================================================
 * END of PMU Support funtions
 * ====================================================================================================== 
 */
 

