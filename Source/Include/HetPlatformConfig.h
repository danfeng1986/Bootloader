/***************************************************************
 * Copyright (C), 2015-2025, H&T Tech
 * File name    : HetPlatformConfig.h
 * Author       : Bernie Liu
 * Version      : V1.0.0
 * Date         : 2015-09-08
 * Description  : 
 * Others       : 
***************************************************************/

#ifndef _HET_PLATFORM_CONFIG_H_
#define _HET_PLATFORM_CONFIG_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include "HetConfig.h"

#if defined(PLATFORM_CC3200)
/* TI CC3200 platform */

    //#include "..\HAL\BSP\CC3200\Adc_drv.h"
    //#include "..\HAL\BSP\CC3200\Gpio_drv.h"
    //#include "..\HAL\BSP\CC3200\I2c_drv.h"
    //#include "..\HAL\BSP\CC3200\Spi_drv.h"
    //#include "..\HAL\BSP\CC3200\Timer_drv.h"
    //#include "..\HAL\BSP\CC3200\Uart_drv.h"
    
    //#include "..\HAL\BSP\CC3200\Socket_drv.h"
    //#include "..\HAL\BSP\CC3200\Easylink_drv.h"
    //#include "..\HAL\BSP\CC3200\Storage_drv.h"

#elif defined(PLATFORM_MW300)
/* MARVELL MW300 platform */


#elif defined(PLATFORM_QCA4004)
/* Qualcomm QCA4004 platform */
  
#endif


#ifdef  __cplusplus
}
#endif // __cplusplus

#endif /* _HET_PLATFORM_CONFIG_H_ */
