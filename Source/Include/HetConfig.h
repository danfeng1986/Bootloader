/***************************************************************
 * Copyright (C), 2015-2025, H&T Tech
 * File name    : HetConfig.h
 * Author       : Bernie Liu
 * Version      : V1.0.0
 * Date         : 2015-09-08
 * Description  : 
 * Others       : 
***************************************************************/

#ifndef _HET_CONFIG_H_
#define _HET_CONFIG_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HetTypeDefine.h"

/*------------------------OS SELECT---------------------------------------*/
//#define USE_FREERTOS  /* FreeRTOS */

/*------------------------COMPLIER SELECT---------------------------------------*/
#define COMPLIER_EARM  /* IAR or KEIL Complier*/
//#define COMPLIER_GCC   /* GCC Complier */
//#define COMPLIER_CCS   /* CCS Complier */

/*------------------------PLATFORM SELECT---------------------------------------*/
#define PLATFORM_CC3200  /* TI CC3200 platform */
//#define PLATFORM_MW300   /* MARVELL MW300 platform */
//#define PLATFORM_QCA4004 /* Qualcomm QCA4004 platform */

/*------------------------PROTOCOL SELECT---------------------------------------*/
//#define PROTOCOL_COMM_HET      /* Het protocol by self */
#define PROTOCOL_COMM_THIRD    /* Third open protocol */
//#define PROTOCOL_COMM_HOMEKIT  /* Apple Homekit protocol */

/*------------------------USER CONSOLE SELECT-----------------------------------*/
#define USRCONSOLE_ON_SOC       /* console by SOC */

#ifdef USRCONSOLE_ON_SOC
    #define USRCONSOLE_COMM_WITCH_MCU /* wifi is commucation witch mcu */
    
    /* Use short time for function test: 1M = 1H, 1M = 1S */
    #define USE_SHORT_TIME_TEST
    
#else
    #define USRCONSOLE_COMM_WITCH_MCU /* wifi is commucation witch mcu */
#endif

/*------------------------DEBUG SHELL SELECT------------------------------------*/
#define SHELL_DEBUG_FUNC /* enable shell debug func, use uart */
#if defined(SHELL_DEBUG_FUNC)    
    #define PRINT_FUNC  /* user or system print message */
#else
    //#define PRINT_ENABLE_USR_START_FUNC /* surpport user start print by command */
#endif

extern void DBG(const TCHAR *pcFormat, ...);

/*------------------------TASK PARAMS DEFINE------------------------------------*/

#define OS_STACK_SIZE                   (2048)
#define OS_SLEEP_TIME                   (20ul)

#define TASK_SPAWN_PRIORITY             (2ul)

#define TASK_NETWORK_NAME               "TASK-NETWORK"
#define TASK_NETWORK_PRIORITY           (3ul)
#define TASK_NETWORK_STACK              (OS_STACK_SIZE)
#define TASK_NETWORK_SLEEP              (20ul)

#define MSGQ_NETWORK_NAME               "MSGQ-NETWORK"
#define MSGQ_NETWORK_MSG_SIZE           (sizeof(T16U))
#define MSGQ_NETWORK_MSGS_LEN           (32ul)

#define TASK_TCP_NAME                   "TASK-TCP"
#define TASK_TCP_PRIORITY               (4ul)
#define TASK_TCP_STACK                  (OS_STACK_SIZE)
#define TASK_TCP_SLEEP                  (10ul)

#define MSGQ_TCP_NAME                   "MSGQ-TCP"
#define MSGQ_TCP_MSG_SIZE               (sizeof(T16U))
#define MSGQ_TCP_MSGS_LEN               (32ul)

#define TASK_UDP_NAME                   "TASK-UDP"
#define TASK_UDP_PRIORITY               (4ul)
#define TASK_UDP_STACK                  (OS_STACK_SIZE)
#define TASK_UDP_SLEEP                  (10ul)

#define MSGQ_UDP_NAME                   "MSGQ-UDP"
#define MSGQ_UDP_MSG_SIZE               (sizeof(T16U))
#define MSGQ_UDP_MSGS_LEN               (32ul)

#define TASK_USER_NAME                  "TASK-USER"
#define TASK_USER_PRIORITY              (1ul)
#define TASK_USER_STACK                 (OS_STACK_SIZE)
#define TASK_USER_SLEEP                 (10ul)

#define MSGQ_USER_NAME                  "MSGQ-USER"
#define MSGQ_USER_MSG_SIZE              (sizeof(T16U))
#define MSGQ_USER_MSGS_LEN              (32ul)

/*------------------------SDK PARAMS DEFINE------------------------------------*/
#define HET_WIFI_SDK_NAME              "HET WIFI MODUAL"

/* BYTE0 ~ BYTE5 */
/* BYTE0:B[7-4],BOOT VER; B[3~0], ServicePack Ver */
#define HET_WIFI_VER_SERVICEPACK       (1)
#define HET_WIFI_VER_BOOT              (1)
#define HET_WIFI_VER_DRIVER \
        (T8U)(((HET_WIFI_VER_BOOT & 0x0F) << 4) | (HET_WIFI_VER_SERVICEPACK & 0x0F))

/* BYTE1:B[7-5],HET APP Main VER; B[4~0], HET APP Sub VER */
#define HET_WIFI_VER_APP_MAIN          (2)
#define HET_WIFI_VER_APP_SUB           (0)
#define HET_WIFI_VER_APP \
        (T8U)(((HET_WIFI_VER_APP_MAIN & 0x07) << 5) | (HET_WIFI_VER_APP_SUB & 0x1F))

/* BYTE2:CHIP Firm¡êo1-oo¡¤?, 2-TI, 3-MARVELL */
#define HET_WIFI_CHIP_FIRM             (2)

/* BYTE3:WIFI model NO */
#define HET_WIFI_MODEL_NO              (1)

/* BYTE4:WIFI Hardware VER */
#define HET_WIFI_VER_HW                (1)

/* BYTE5:WIFI Chip SDK VER */
#define HET_WIFI_VER_CHIP_SDK          (1)

#define HET_WIFI_SDK_HARDWARE_VERSION \
        (T16U)((HET_WIFI_VER_DRIVER << 8) | HET_WIFI_VER_APP)

#define HET_WIFI_SDK_SOFTWARE_VERSION \
        (T32U)((HET_WIFI_CHIP_FIRM << 24) \
             | (HET_WIFI_MODEL_NO << 16) \
             | (HET_WIFI_VER_HW << 8) \
             | (HET_WIFI_VER_CHIP_SDK << 0))

/*------------------------SDK OTA DEFINE---------------------------------------*/
#define IMG_STATUS_UPDATE       (0XC33C)
#define IMG_STATUS_RECOVERY     (0x0000)
#define IGM_STATUS_TEMPA        (0X5AA5)
#define IGM_STATUS_TEMPB        (0XA55A)

/*------------------------SDK SECURITY DEFINE------------------------------------*/
/*
    0x00000000: 2??¨®?¨¹
    0x00000001: ?¨²2?D-¨°¨¦¨º1¨®?¦Ì??¨®?¨¹¡¤?¨º?
    0x00000002: DES_ECB?¨®?¨¹ 64???¨¹??   ¡ê¡§¡¤t???¡ÂD¨¨¨¦¨²3¨¦N=16??¡Á??¨²???¨²¨ºy¡ê?
    0x00000003: AES_ECB?¨®?¨¹ 128???¨¹??  ¡ê¡§¡¤t???¡ÂD¨¨¨¦¨²3¨¦N=16??¡Á??¨²???¨²¨ºy¡ê?
    0x00000004: AES_CBC?¨®?¨¹ 128???¨¹??  ¡ê¡§¡¤t???¡ÂD¨¨¨¦¨²3¨¦N=32??¡Á??¨²???¨²¨ºy¡ê?
*/
#define SECURITY_NONE                 (0x00000000)
#define SECURITY_HET                  (0x00000001)
#define SECURITY_DES_ECB              (0x00000002)
#define SECURITY_AES_ECB              (0x00000003)
#define SECURITY_AES_CBC              (0x00000004)
#define SDK_PROTOCOL_SECURITY_TYPE    (SECURITY_NONE)/*(SECURITY_AES_ECB)*/

/*------------------------SYSTEM INCLUDE (.h)-----------------------------------*/

//#include "HetMessageConfig.h"

//#include "..\HAL\BSP\Adc_api.h"
//#include "..\HAL\BSP\Gpio_api.h"   ////
//#include "..\HAL\BSP\I2c_api.h"    ////
////#include "..\HAL\BSP\Spi_api.h"    ////
//#include "..\HAL\BSP\Timer_api.h"
//#include "..\HAL\BSP\Uart_api.h"
  
//#include "..\HAL\BSP\Storage_api.h"
//#include "..\HAL\BSP\Socket_api.h"
//#include "..\HAL\BSP\EasyLink_api.h"
    
//#include "..\HAL\OS\Os_api.h"

//#include "..\Framework\System\SysStorage.h"
#include "..\Framework\System\SysParams.h"
//#include "..\Framework\System\Rsh.h"
//#include "..\Framework\System\NetCommunity.h"
//#include "..\Framework\OTA\ota.h"


#ifdef  __cplusplus
}
#endif // __cplusplus

#endif /* _HET_CONFIG_H_ */
