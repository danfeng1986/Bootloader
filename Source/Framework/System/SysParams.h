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

    /* �Ƿ�󶨹�·��������ͨ�û�����д�� */
    HET_PSO_BOUND_ROUTER = HET_PSO_SECURITY_START, 

    /* �Ƿ�󶨹���֤����������ͨ�û�����д�� */
    HET_PSO_BOUND_IDENTIFY, 

    /* �ļ�Э������ �������û���������� */
    HET_PSO_PROTOCOL_TYPE, 

    /* ����״̬���û�������д�� */
    HET_PSO_OTA_STATUS, 

#if 0    
    /* �豸������Ϣ�������豸Ʒ�ƣ���С���� */
    HET_PSO_DEV_SERIAL_NO_TYPE = HET_PSO_OTA_STATUS + HET_OTA_STATUS_LEN,

    /* �豸������Ϣ���64�ֽ� */
    HET_PSO_DEV_BASIC_INFO = HET_PSO_DEV_SERIAL_NO_TYPE + HET_DEV_SERIAL_NO_LEN,

    /* �豸������Ϣ��1�ֽ� */
    HET_PSO_DEV_BASIC_INFO_LEN = HET_PSO_DEV_BASIC_INFO + HET_DEV_BASIC_INFO_LEN,
    
    /* APP���͸�ģ�����Կ��32�ֽ� */
    HET_PSO_USR_KEY, 

    /* DEVICE KEY��32�ֽ� */
    HET_PSO_DEV_KEY = HET_PSO_USR_KEY + HET_USR_KEY_LEN,

    /* ���ݷ�����IP��ַ��4�ֽ� */
    HET_PSO_SERVER_DATAS_IP = HET_PSO_DEV_KEY + HET_DEV_KEY_LEN, 
 
    /* ���ݷ�����port�˿ڣ�2�ֽ� */
    HET_PSO_SERVER_DATAS_PORT = HET_PSO_SERVER_DATAS_IP + HET_SERVER_DATAS_IP_LEN,

    HET_PSO_SECURITY_MAX = HET_PSO_SERVER_DATAS_PORT + HET_SERVER_DATAS_PORT_LEN,

 /*----------------------- Usr backup storage offset -------------------------------*/
    HET_PSO_USR_BACKUP_START,

    /* �û����ݴ洢�����256�ֽ� */
    HET_PSO_USR_BACKUP = HET_PSO_USR_BACKUP_START,

    HET_PSO_USR_BACKUP_MAX = HET_PSO_USR_BACKUP + HET_USR_BACKUP_LEN,
    
 /*----------------------- Temperate storage offset -------------------------------*/
    HET_PSO_TMP_START,
    
     /* wifi ״̬��Ϣ�������󶨺����ӣ��Լ��ź�ǿ��״̬��1�ֽ� */
    HET_PSO_WIFI_STATUS = HET_PSO_TMP_START,
    
    /* ����ģʽ���ݣ��16�ֽ� */
    HET_PSO_ENGINEER_MODE,

    /* ʱ�����ݣ�16�ֽ� */
    HET_PSO_TIME_DATAS = HET_PSO_ENGINEER_MODE + HET_ENGINEER_MODE_LEN,
    
    /* ������Ӳ��������Ϣ���128�ֽ� */
    HET_PSO_CDP_CONFIG = HET_PSO_TIME_DATAS + HET_TIME_DATAS_LEN, 
 
    /* ������Ӳ��������Ϣ���� */
    HET_PSO_CDP_CONFIG_LEN = HET_PSO_CDP_CONFIG + HET_CDP_CONFIG_LEN,
    
    /* ģ�����IP��4�ֽ� */
    HET_PSO_WIFI_IP, 

    /* ģ��MAC��ַ��6�ֽ� */
    HET_PSO_WIFI_MAC_ADDR = HET_PSO_WIFI_IP + HET_WIFI_IP_LEN, 

    /* ģ�����ϵ�·��SSID���32�ֽ� */
    HET_PSO_WIFI_SSID = HET_PSO_WIFI_MAC_ADDR + HET_WIFI_MAC_ADDR_LEN, 

    /* ģ�����ϵ�·��KEY���32�ֽ� */
    HET_PSO_WIFI_KEY = HET_PSO_WIFI_SSID + HET_WIFI_SSID_LEN,

    /* ����URL���128�ֽ� */
    HET_PSO_OTA_URL = HET_PSO_WIFI_KEY + HET_WIFI_KEY_LEN, 

    /* ����URL���峤�� */
    HET_PSO_OTA_URL_LEN = HET_PSO_OTA_URL + HET_OTA_URL_LEN, 

    /* �����̼����ͣ�6�ֽ� */
    HET_PSO_OTA_HW_TYPE, 

    /* ����������Ϣ���128�ֽ� */
    HET_PSO_OTA_ENCYPT = HET_PSO_OTA_HW_TYPE + HET_OTA_HW_LEN, 

    /* ����������Ϣ���峤�� */
    HET_PSO_OTA_ENCYPT_LEN = HET_PSO_OTA_ENCYPT + HET_OTA_ENCYPT_LEN,

    /* ����У�����ͣ�1�ֽ� */
    HET_PSO_OTA_CHSUM_TYPE,

    /* ����У����Ϣ��32�ֽ� */
    HET_PSO_OTA_CHSUM_INFO,

    /* ���������Ʋ������128�ֽ� */
    HET_PSO_CDP_CONTROL = HET_PSO_OTA_CHSUM_INFO + HET_OTA_CHSUM_INFO_LEN, 

    /* ���������Ʋ������� */
    HET_PSO_CDP_CONTROL_LEN = HET_PSO_CDP_CONTROL + HET_CDP_CONTROL_LEN, 

    /* �������ϴ����в������128�ֽ� */
    HET_PSO_CDP_OPERATING, 

    /* �������ϴ����в������� */
    HET_PSO_CDP_OPERATING_LEN = HET_PSO_CDP_OPERATING + HET_CDP_OPERATING_LEN, 

    /* �豸������Ϣ���128�ֽ� */
    HET_PSO_CDP_ERROR,
 
    /* �豸������Ϣ���ȣ�1�ֽ� */
    HET_PSO_CDP_ERROR_LEN = HET_PSO_CDP_ERROR + HET_CDP_ERROR_LEN,

    /* ��֤������IP��ַ��4�ֽ� */
    HET_PSO_SERVER_IDENTIFY_IP, 
 
    /* ��֤������port�˿ڣ�2�ֽ� */
    HET_PSO_SERVER_IDENTIFY_PORT = HET_PSO_SERVER_IDENTIFY_IP + HET_SERVER_IDENTIFY_IP_LEN, 

    /* ���������ڣ�2�ֽ� */
    HET_PSO_CYCLE_HEART = HET_PSO_SERVER_IDENTIFY_PORT + HET_SERVER_IDENTIFY_PORT_LEN, 

    /* ���ݲ������ڣ�2�ֽ� */
    HET_PSO_CYCLE_DATA_SAMPLE = HET_PSO_CYCLE_HEART + HET_CYCLE_HEART_LEN, 

    /* �����ϴ����ڣ�2�ֽ� */
    HET_PSO_CYCLE_DATA_UPLOAD = HET_PSO_CYCLE_DATA_SAMPLE + HET_CYCLE_DATA_SAMPLE_LEN, 

    /* �������������ݣ��1024�ֽ� */
    HET_PSO_HDP_CONTROL = HET_PSO_CYCLE_DATA_UPLOAD + HET_CYCLE_DATA_UPLOAD_LEN, 

    /* �������������ݳ��ȣ�2�ֽ�  */
    HET_PSO_HDP_CONTROL_LEN = HET_PSO_HDP_CONTROL + HET_HDP_CONTROL_LEN,

    /* �豸������Ϣ���1024�ֽ� */
    HET_PSO_HDP_ERROR = HET_PSO_HDP_CONTROL_LEN + 2,
 
    /* �豸������Ϣ���ȣ�2�ֽ� */
    HET_PSO_HDP_ERROR_LEN = HET_PSO_HDP_ERROR + HET_HDP_ERROR_LEN,

    /* �������ϴ���ʷ���в������1024�ֽ� */
    HET_PSO_HDP_OPERATING = HET_PSO_HDP_ERROR_LEN + 2, 

    /* �������ϴ���ʷ���в������ȣ�2�ֽ�  */
    HET_PSO_HDP_OPERATING_LEN = HET_PSO_HDP_OPERATING + HET_HDP_OPERATING_LEN, 

    /* ���ܴ�Ż��棬�1024�ֽ� */
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

