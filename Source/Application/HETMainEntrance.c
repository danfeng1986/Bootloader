/***************************************************************
 * Copyright (C), 2015-2025, H&T Tech
 * File name    : HETMainEntrance.c
 * Author       : Liu YuanZhen
 * Version      : V1.0.0
 * Date         : 2015-09-25
 * Description  : 
 * Others       : 
***************************************************************/

/******************************************************
*                 includes
******************************************************/
#include "..\Include\HetConfig.h"

/******************************************************
*                 Macros
******************************************************/

/******************************************************
*                Constants
******************************************************/

/******************************************************
*               Enumerations
******************************************************/

/******************************************************
*             Type Definitions
******************************************************/

/******************************************************
*               Structures
******************************************************/

/******************************************************
*           Variables Definitions
******************************************************/

/******************************************************
*               Declarations
******************************************************/
extern void SysInitConfig(void);

/******************************************************
*               Functions
******************************************************/

/********************************************************************************/
void main(void)
/********************************************************************************/
{
    /* system initial settings */
    SysInitConfig();
    
    for( ; ; )
    {
    }
}

#ifdef  USE_FREERTOS

//*****************************************************************************
//
//! \brief Application defined hook (or callback) function - assert
//!
//! \param[in]  pcFile - Pointer to the File Name
//! \param[in]  ulLine - Line Number
//! 
//! \return none
//!
//*****************************************************************************
void vAssertCalled( const char *pcFile, unsigned long ulLine )
{
    //Handle Assert here
    DBG("\r\n%s, %d", pcFile, ulLine);
    while(1)
    {
    }
}

//*****************************************************************************
//
//! \brief Application defined idle task hook
//! 
//! \param  none
//! 
//! \return none
//!
//*****************************************************************************
void vApplicationIdleHook( void)
{
    //Handle Idle Hook for Profiling, Power Management etc
}

//*****************************************************************************
//
//! \brief Application defined malloc failed hook
//! 
//! \param  none
//! 
//! \return none
//!
//*****************************************************************************
void vApplicationMallocFailedHook()
{
    //Handle Memory Allocation Errors
    DBG("\r\nMalloc Failed...");
    while(1)
    {
    }
}

//*****************************************************************************
//
//! \brief Application defined stack overflow hook
//! 
//! \param  none
//! 
//! \return none
//!
//*****************************************************************************
void vApplicationStackOverflowHook( OSTaskHandle *pxTask,
                                   signed char *pcTaskName)
{
    //Handle FreeRTOS Stack Overflow
    DBG("\r\n%s, %s", pxTask, pcTaskName);
    while(1)
    {
    }
}

#endif
