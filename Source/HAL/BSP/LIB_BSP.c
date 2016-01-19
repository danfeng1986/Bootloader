/*****************************************************
 * Copyright (C), 2015-2025, H&T Tech
 * File name    : LIB_BSP.c
 * Author       : Bernie Liu
 * Version      : V1.0.0
 * Date         : 2015-09-25
 * Description  : 
 * Others       : 
******************************************************/

/******************************************************
*                 includes
******************************************************/
#include "..\..\Include\HetPlatformConfig.h"

#if defined(PLATFORM_CC3200)
/* TI CC3200 platform */
    
    #if defined(COMPLIER_EARM)
        #include ".\CC3200\Complier\HET_WIFI_STARTUP_APP_EARM.c"
    #elif defined(COMPLIER_GCC)
        #include ".\CC3200\Complier\HET_WIFI_STARTUP_APP_GCC.c"
    #elif defined(COMPLIER_CCS)
        #include ".\CC3200\Complier\HET_WIFI_STARTUP_APP_CCS.c"
    #endif
    
    #include ".\CC3200\Complier\PlatformStartup.c"

    //#include "CC3200\LIB\adc.c"
    //#include "CC3200\LIB\aes.c"
    //#include "CC3200\LIB\camera.c"
    #include "CC3200\LIB\cpu.c"
    //#include "CC3200\LIB\crc.c"
    //#include "CC3200\LIB\des.c"
    #include "CC3200\LIB\flash.c"
    //#include "CC3200\LIB\gpio.c"
    //#include "CC3200\LIB\hwspinlock.c"
    //#include "CC3200\LIB\i2c.c"  
    //#include "CC3200\LIB\i2s.c"
    #include "CC3200\LIB\interrupt.c"
    #include "CC3200\LIB\pin.c"
    #include "CC3200\LIB\prcm.c"
    //#include "CC3200\LIB\sdhost.c"
    //#include "CC3200\LIB\shamd5.c"
    #include "CC3200\LIB\spi.c"
    //#include "CC3200\LIB\systick.c"
    //#include "CC3200\LIB\timer.c"
    //#include "CC3200\LIB\uart.c"
    #include "CC3200\LIB\udma.c"
    #include "CC3200\LIB\utils.c"
    //#include "CC3200\LIB\wdt.c"
    
    #include "CC3200\LIB\Network\src\device.c"
    #include "CC3200\LIB\Network\src\driver.c"
    //#include "CC3200\LIB\Network\src\flowcont.c"
    #include "CC3200\LIB\Network\src\fs.c"
    #include "CC3200\LIB\Network\src\netapp.c"
    //#include "CC3200\LIB\Network\src\netcfg.c"
    #include "CC3200\LIB\Network\src\nonos.c"
    #include "CC3200\LIB\Network\src\socket.c"
    //#include "CC3200\LIB\Network\src\spawn.c"
    //#include "CC3200\LIB\Network\src\wlan.c"
    #include "CC3200\LIB\Network\cc_pal.c"
    //#include "CC3200\LIB\Network\osi_freertos.c"

    //#include "CC3200\Adc_drv.c"
    //#include "CC3200\Gpio_drv.c"  ////
    //#include "CC3200\I2c_drv.c"
    //#include "CC3200\Spi_drv.c"
    //#include "CC3200\Timer_drv.c"
    //#include "CC3200\Uart_drv.c"
    
    //#include "CC3200\Socket_drv.c"
    //#include "CC3200\Easylink_drv.c"
    //#include "CC3200\Storage_drv.c" 

#elif defined(PLATFORM_MW300)
/* MARVELL MW300 platform */


#elif defined(PLATFORM_QCA4004)
/* Qualcomm QCA4004 platform */
  
#endif

//#include "Adc_api.c"
//#include "Gpio_api.c"
//#include "I2c_api.c"
//#include "Spi_api.c"
//#include "Timer_api.c"
//#include "Uart_api.c"

//#include "Socket_api.c"
//#include "Easylink_api.c"
//#include "Storage_api.c" 


