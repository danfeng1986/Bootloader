/***************************************************************
 * Copyright (C), 2015-2025, H&T Tech
 * File name    : SysParams.h
 * Author       : Liu YuanZhen
 * Version      : V1.0.0
 * Date         : 2015-06-03
 * Description  : 
 * Others       : 
***************************************************************/

#ifndef _SYSPARAMS_H_
#define _SYSPARAMS_H_

/******************************************************
*                 includes
******************************************************/
#include "..\..\Include\HetProtocolConfig.h"

/******************************************************
*                 Macros
******************************************************/
#define SECURITY_DATA_START  (HET_PSO_SECURITY_START)
#define SECURITY_DATA_LEN    (HET_PSO_SECURITY_MAX - HET_PSO_SECURITY_START)

#define USRBACKUP_DATA_START (HET_PSO_USR_BACKUP_START)
#define USRBACKUP_DATA_LEN   (HET_PSO_USR_BACKUP_MAX - HET_PSO_USR_BACKUP_START)

/******************************************************
*                Constants
******************************************************/

/******************************************************
*               Enumerations
******************************************************/
/* HPSO = HET PARAMS STORAGE OFFSET*/
typedef enum
{
 /*----------------------- Security storage offset -------------------------------*/
    HET_PSO_SECURITY_START = 0x0,

    /* 是否绑定过路由器，普通用户不能写入 */
    HET_PSO_BOUND_ROUTER = HET_PSO_SECURITY_START, 

    /* 是否绑定过认证服务器，普通用户不能写入 */
    HET_PSO_BOUND_IDENTIFY, 

    /* 文件协议类型 ，所有用户不允许操作 */
    HET_PSO_PROTOCOL_TYPE, 

    /* 升级状态，用户不允许写入 */
    HET_PSO_OTA_STATUS, 

#if 0    
    /* 设备类型信息，包括设备品牌，大小分类 */
    HET_PSO_DEV_SERIAL_NO_TYPE = HET_PSO_OTA_STATUS + HET_OTA_STATUS_LEN,

    /* 设备基本信息，最长64字节 */
    HET_PSO_DEV_BASIC_INFO = HET_PSO_DEV_SERIAL_NO_TYPE + HET_DEV_SERIAL_NO_LEN,

    /* 设备基本信息，1字节 */
    HET_PSO_DEV_BASIC_INFO_LEN = HET_PSO_DEV_BASIC_INFO + HET_DEV_BASIC_INFO_LEN,
    
    /* APP发送给模组的密钥，32字节 */
    HET_PSO_USR_KEY, 

    /* DEVICE KEY，32字节 */
    HET_PSO_DEV_KEY = HET_PSO_USR_KEY + HET_USR_KEY_LEN,

    /* 数据服务器IP地址，4字节 */
    HET_PSO_SERVER_DATAS_IP = HET_PSO_DEV_KEY + HET_DEV_KEY_LEN, 
 
    /* 数据服务器port端口，2字节 */
    HET_PSO_SERVER_DATAS_PORT = HET_PSO_SERVER_DATAS_IP + HET_SERVER_DATAS_IP_LEN,

    HET_PSO_SECURITY_MAX = HET_PSO_SERVER_DATAS_PORT + HET_SERVER_DATAS_PORT_LEN,

 /*----------------------- Usr backup storage offset -------------------------------*/
    HET_PSO_USR_BACKUP_START,

    /* 用户数据存储，最大256字节 */
    HET_PSO_USR_BACKUP = HET_PSO_USR_BACKUP_START,

    HET_PSO_USR_BACKUP_MAX = HET_PSO_USR_BACKUP + HET_USR_BACKUP_LEN,
    
 /*----------------------- Temperate storage offset -------------------------------*/
    HET_PSO_TMP_START,
    
     /* wifi 状态信息，包括绑定和连接，以及信号强度状态，1字节 */
    HET_PSO_WIFI_STATUS = HET_PSO_TMP_START,
    
    /* 工程模式数据，最长16字节 */
    HET_PSO_ENGINEER_MODE,

    /* 时间数据，16字节 */
    HET_PSO_TIME_DATAS = HET_PSO_ENGINEER_MODE + HET_ENGINEER_MODE_LEN,
    
    /* 控制器硬件配置信息，最长128字节 */
    HET_PSO_CDP_CONFIG = HET_PSO_TIME_DATAS + HET_TIME_DATAS_LEN, 
 
    /* 控制器硬件配置信息长度 */
    HET_PSO_CDP_CONFIG_LEN = HET_PSO_CDP_CONFIG + HET_CDP_CONFIG_LEN,
    
    /* 模组分配IP，4字节 */
    HET_PSO_WIFI_IP, 

    /* 模组MAC地址，6字节 */
    HET_PSO_WIFI_MAC_ADDR = HET_PSO_WIFI_IP + HET_WIFI_IP_LEN, 

    /* 模组连上的路由SSID，最长32字节 */
    HET_PSO_WIFI_SSID = HET_PSO_WIFI_MAC_ADDR + HET_WIFI_MAC_ADDR_LEN, 

    /* 模组连上的路由KEY，最长32字节 */
    HET_PSO_WIFI_KEY = HET_PSO_WIFI_SSID + HET_WIFI_SSID_LEN,

    /* 升级URL，最长128字节 */
    HET_PSO_OTA_URL = HET_PSO_WIFI_KEY + HET_WIFI_KEY_LEN, 

    /* 升级URL具体长度 */
    HET_PSO_OTA_URL_LEN = HET_PSO_OTA_URL + HET_OTA_URL_LEN, 

    /* 升级固件类型，6字节 */
    HET_PSO_OTA_HW_TYPE, 

    /* 升级加密信息，最长128字节 */
    HET_PSO_OTA_ENCYPT = HET_PSO_OTA_HW_TYPE + HET_OTA_HW_LEN, 

    /* 升级加密信息具体长度 */
    HET_PSO_OTA_ENCYPT_LEN = HET_PSO_OTA_ENCYPT + HET_OTA_ENCYPT_LEN,

    /* 升级校验类型，1字节 */
    HET_PSO_OTA_CHSUM_TYPE,

    /* 升级校验信息，32字节 */
    HET_PSO_OTA_CHSUM_INFO,

    /* 控制器控制参数，最长128字节 */
    HET_PSO_CDP_CONTROL = HET_PSO_OTA_CHSUM_INFO + HET_OTA_CHSUM_INFO_LEN, 

    /* 控制器控制参数长度 */
    HET_PSO_CDP_CONTROL_LEN = HET_PSO_CDP_CONTROL + HET_CDP_CONTROL_LEN, 

    /* 控制器上传运行参数，最长128字节 */
    HET_PSO_CDP_OPERATING, 

    /* 控制器上传运行参数长度 */
    HET_PSO_CDP_OPERATING_LEN = HET_PSO_CDP_OPERATING + HET_CDP_OPERATING_LEN, 

    /* 设备错误信息，最长128字节 */
    HET_PSO_CDP_ERROR,
 
    /* 设备错误信息长度，1字节 */
    HET_PSO_CDP_ERROR_LEN = HET_PSO_CDP_ERROR + HET_CDP_ERROR_LEN,

    /* 认证服务器IP地址，4字节 */
    HET_PSO_SERVER_IDENTIFY_IP, 
 
    /* 认证服务器port端口，2字节 */
    HET_PSO_SERVER_IDENTIFY_PORT = HET_PSO_SERVER_IDENTIFY_IP + HET_SERVER_IDENTIFY_IP_LEN, 

    /* 心跳桢周期，2字节 */
    HET_PSO_CYCLE_HEART = HET_PSO_SERVER_IDENTIFY_PORT + HET_SERVER_IDENTIFY_PORT_LEN, 

    /* 数据采样周期，2字节 */
    HET_PSO_CYCLE_DATA_SAMPLE = HET_PSO_CYCLE_HEART + HET_CYCLE_HEART_LEN, 

    /* 数据上传周期，2字节 */
    HET_PSO_CYCLE_DATA_UPLOAD = HET_PSO_CYCLE_DATA_SAMPLE + HET_CYCLE_DATA_SAMPLE_LEN, 

    /* 控制器运行数据，最长1024字节 */
    HET_PSO_HDP_CONTROL = HET_PSO_CYCLE_DATA_UPLOAD + HET_CYCLE_DATA_UPLOAD_LEN, 

    /* 控制器运行数据长度，2字节  */
    HET_PSO_HDP_CONTROL_LEN = HET_PSO_HDP_CONTROL + HET_HDP_CONTROL_LEN,

    /* 设备错误信息，最长1024字节 */
    HET_PSO_HDP_ERROR = HET_PSO_HDP_CONTROL_LEN + 2,
 
    /* 设备错误信息长度，2字节 */
    HET_PSO_HDP_ERROR_LEN = HET_PSO_HDP_ERROR + HET_HDP_ERROR_LEN,

    /* 控制器上传历史运行参数，最长1024字节 */
    HET_PSO_HDP_OPERATING = HET_PSO_HDP_ERROR_LEN + 2, 

    /* 控制器上传历史运行参数长度，2字节  */
    HET_PSO_HDP_OPERATING_LEN = HET_PSO_HDP_OPERATING + HET_HDP_OPERATING_LEN, 

    /* 加密存放缓存，最长1024字节 */
    HET_PSO_FRAME_SECURITY = HET_PSO_HDP_OPERATING_LEN + 2,
    
    HET_PSO_TMP_MAX = HET_PSO_FRAME_SECURITY + HET_FRAME_SECURITY_LEN,
   
    HET_PSO_MAX
#endif
}HET_PSO_OFFSET_e;

/******************************************************
*             Type Definitions
******************************************************/

/******************************************************
*               Structures
******************************************************/

/******************************************************
*               Declarations
******************************************************/
/********************************************************************************/
T16S SysParams_open(void);
/********************************************************************************/

/********************************************************************************/
T16S  SysParams_close(void);
/********************************************************************************/

/********************************************************************************/
T16S SysParams_write(T16S psoOffset, T8U* pBuf, T16S len);
/********************************************************************************/

/********************************************************************************/
T8U* SysParams_read(T16S psoOffset);
/********************************************************************************/

/********************************************************************************/
TBOOL SysParams_isUsrBackupGet (void);
/********************************************************************************/

/********************************************************************************/
void SysParams_readFS (void);
/********************************************************************************/

/********************************************************************************/
void SysParams_saveFS(void);
/********************************************************************************/

#endif /* _SYSPARAMS_H_ */

