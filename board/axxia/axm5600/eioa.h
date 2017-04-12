#pragma once 

#define NCP_EIOA_GEN_CFG_REG_OFFSET(portIndex)                                  \
    0x100000 +                                                                  \
    ((portIndex > 0) ? 0x10000 : 0) +                                           \
    ((portIndex > 0) ? (0x1000 * (portIndex - 1)) : 0)

typedef enum                                                
{                                                           
    NCP_EIOA_SERDES_REF_CLK_001_0_TO_026_MHZ            = 0,
    NCP_EIOA_SERDES_REF_CLK_026_1_TO_052_MHZ        = 1,    
    NCP_EIOA_SERDES_REF_CLK_052_1_TO_078_MHZ            = 2,
    NCP_EIOA_SERDES_REF_CLK_078_1_TO_104_MHZ            = 3,
    NCP_EIOA_SERDES_REF_CLK_104_1_TO_130_MHZ            = 4,
    NCP_EIOA_SERDES_REF_CLK_130_1_TO_156_MHZ            = 5,
    NCP_EIOA_SERDES_REF_CLK_156_1_TO_182_MHZ            = 6,
    NCP_EIOA_SERDES_REF_CLK_182_1_TO_200_MHZ            = 7,
    NCP_EIOA_SERDES_REF_CLK_FREQ_MAX                        
} ncp_eioa_serdes_ref_clk_range_t;                          
