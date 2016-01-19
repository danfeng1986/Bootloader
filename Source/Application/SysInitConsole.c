/***************************************************************
 * Copyright (C), 2015-2025, H&T Tech
 * File name    : SysInitConsole.c
 * Author       : Liu YuanZhen
 * Version      : V1.0.0
 * Date         : 2015-07-31
 * Description  : 
 * Others       : 
***************************************************************/

/******************************************************
*                 includes
******************************************************/
#include "..\Include\HetConfig.h"
#include "..\HAL\BSP\CC3200\LIB\Network\src\fs.h"

/******************************************************
*                 Macros
******************************************************/
#define FS_NAME_OTA_SRC              "/sys/HetSrc.bin"
#define FS_NAME_OTA_TMPA             "/sys/tmpA.bin"
#define FS_NAME_OTA_TMPB             "/sys/tmpB.bin"
#define FS_NAME_SECURITY             "/sys/Security.txt"

#define FS_MIN_SIZE                   (1024ul)
 
#define FS_SIZE_BOOTLOADER            (32 * FS_MIN_SIZE)
#define FS_SIZE_SRC                   (120 * FS_MIN_SIZE)
#define FS_SIZE_SECURITY              (1 * FS_MIN_SIZE)
#define FS_SIZE_DATABASE              (1 * FS_MIN_SIZE)
#define FS_SIZE_USER                  (1 * FS_MIN_SIZE)
 
#define FS_LOC_BOOTLOADER             (0x20004000)
#define FS_LOC_SRC                    (FS_LOC_BOOTLOADER + FS_SIZE_BOOTLOADER)  

#define IMG_STATUS_UPDATE       (0XC33C)
#define IMG_STATUS_RECOVERY     (0x0000)
#define IGM_STATUS_TEMPA        (0X5AA5)
#define IGM_STATUS_TEMPB        (0XA55A)

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
extern void SysPlatformConfig(void);

/******************************************************
*               Functions
******************************************************/

/********************************************************************************/
static void SysjumpToAddr(T32U baseLocation)
/********************************************************************************/
{
  //
  // Set the SP
  //
  __asm("   ldr    sp,[r0]\n"
    "   add    r0,r0,#4");

  //
  // Jump to entry code
  //
  __asm("   ldr    r1,[r0]\n"
        "   bx     r1");
}

/********************************************************************************/
static T16S System_readAuto(TCHAR* fsName, T32U startPos, T8U* buf, T32U len)
/********************************************************************************/
{
    T32S pFsHandle = NULL;

    /* open file by read status */
    if (sl_FsOpen((const T8U*)(fsName), FS_MODE_OPEN_READ, NULL, &pFsHandle) < 0)
    {
        return tdFAILURE;
    }

    /* read from file, start with "startPos"*/
    if (sl_FsRead(pFsHandle, startPos, buf, len) < 0)
    {
        return tdFAILURE;
    }
    
    if (sl_FsClose(pFsHandle, NULL, NULL, 0) < 0)
    {
        return tdFAILURE;
    }

    return tdSUCCESS;
}

/********************************************************************************/
static void SystemRuntime(void)
/********************************************************************************/
{
    T32U UpdateStatus = IMG_STATUS_RECOVERY;
    T8U pRead[4] = {0};
    TCHAR* pFsName = NULL;

    sl_Start(NULL, NULL, NULL);
    
    System_readAuto((TCHAR*)(FS_NAME_SECURITY), HET_PSO_OTA_STATUS, pRead, 4); 
    C4BYTES2HEX(UpdateStatus, pRead);
    if(IMG_STATUS_UPDATE != (UpdateStatus >> 16)) 
    {
        pFsName = (TCHAR*)(FS_NAME_OTA_SRC);
    }
    else
    {          
        if(IGM_STATUS_TEMPA != (UpdateStatus & 0x0000FFFF))
        {
            pFsName = (TCHAR*)(FS_NAME_OTA_TMPB);
        }
        else
        {
            pFsName = (TCHAR*)(FS_NAME_OTA_TMPA);
        }
    }

    System_readAuto(pFsName, 0, (T8U *)(FS_LOC_SRC), FS_SIZE_SRC);

    sl_Stop(30);
    SysjumpToAddr(FS_LOC_SRC);
}

/********************************************************************************/
void SysInitConfig(void)
/********************************************************************************/
{
    SysPlatformConfig();
    SystemRuntime();
}
