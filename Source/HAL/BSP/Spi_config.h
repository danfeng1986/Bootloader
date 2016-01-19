/***************************************************************
 * Copyright (C), 2015-2025, H&T Tech
 * File name    : Spi_config.h
 * Author       : fu chan hao 
 * Version      : V1.0.0
 * Date         : 2015-08-10
 * Description  : 
 * Others       : 
***************************************************************/

#ifndef _SPI_CONFIG_H_
#define _SPI_CONFIG_H_

/******************************************************
*                 includes
******************************************************/
#include "..\..\Include\HetTypeDefine.h"

/******************************************************
*                 Macros
******************************************************/ 
/******************************************************
*                Constants
******************************************************/

/******************************************************
*               Enumerations
******************************************************/

typedef enum
{
    HET_ID_SPI0 = 0x0,
    HET_ID_SPI1,
}SPIID_e;
        
typedef enum
{
    SPI_RES_DEFAULT = 0x0,
}SPIResource_e;

typedef enum
{
    SPI_WR_SEND_BUF = 0x0, 
    SPI_WR_INT_FLAG_CLR,       
}SPIWRConsole_e;

typedef enum
{
    SPI_RD_READ_BUF = 0x0,
    SPI_RD_INT_RUN_STATUS, 
}SPIRDConsole_e;

typedef enum
{
    HET_SPI_MODE_MASTER = 0x0,
    HET_SPI_MODE_SLAVE,
    HET_SPI_MODE_MAX,  
}SPIMode_e;

typedef enum
{
    HET_SPI_SUB_MODE_0 = 0x0,  
    HET_SPI_SUB_MODE_1,      
    HET_SPI_SUB_MODE_2,      
    HET_SPI_SUB_MODE_3,
    HET_SPI_SUB_MODE_MAX,  
}SPISubMode_e;

typedef enum
{
    HET_SPI_SW_CTRL_CS = (1 << 0),
    HET_SPI_HW_CTRL_CS = (1 << 1),      
    HET_SPI_3PIN_MODE = (1 << 2),       
    HET_SPI_4PIN_MODE = (1 << 3),      
    HET_SPI_TURBO_ON = (1 << 4),       
    HET_SPI_TURBO_OFF = (1 << 5),      
    HET_SPI_CS_ACTIVEHIGH = (1 << 6),  
    HET_SPI_CS_ACTIVELOW = (1 << 7),   
    HET_SPI_WL_8 = (1 << 8),           
    HET_SPI_WL_16 = (1 << 9),          
    HET_SPI_WL_32 = (1 << 10),          
}SPIConfig_e;

typedef enum
{
    HET_SPI_TX_FIFO = 0x0,    
    HET_SPI_RX_FIFO,
    HET_SPI_FIFO_MAX,          
}SPILevelg_e;

typedef enum
{
    HET_SPI_INT_DMATX = (1 << 0),  
    HET_SPI_INT_DMARX = (1 << 1),        
    HET_SPI_INT_EOW = (1 << 2),          
    HET_SPI_INT_WKS = (1 << 3),          
    HET_SPI_INT_RX_OVRFLOW = (1 << 4),   
    HET_SPI_INT_RX_FULL = (1 << 5),      
    HET_SPI_INT_TX_UDRFLOW = (1 << 6),   
    HET_SPI_INT_TX_EMPTY = (1 << 7),    
}SPIIntType_e;

typedef enum
{
    HET_SPI_CS_ENABLE = 0x0,  
    HET_SPI_CS_DISABLE,
    HET_SPI_CS_MAX,       
}SPICsEn_e;

typedef enum
{
    HET_PRCM_GSPI = 0x0,  
    HET_PRCM_LSPI,
    HET_PRCM_MAX,       
}SPIPrcm_e;




/******************************************************
*             Type Definitions
******************************************************/

typedef void (*P_SPI_INT_ENTRY)(void);

/******************************************************
*               Structures
******************************************************/
typedef struct
{
    P_SPI_INT_ENTRY entry; 
    SPIID_e ID; 
    T32U  prcm;
    T32U  bitRate;
    T32U  mode;
    T32U  subMode;
    T32U  config;
    T32U  fifo;
    T32U  txLevel;
    T32U  rxLevel;
    T32U  intType;
    T32U  csEn;
}SPIParams_st;

/******************************************************
*               Function Declarations
******************************************************/

#endif /*_SPI_CONFIG_H_*/

