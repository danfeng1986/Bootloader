/***************************************************************
 * Copyright (C), 2015-2025, H&T Tech
 * File name    : TypeDefine.h
 * Author       : Bernie Liu
 * Version      : V1.0.0
 * Date         : 2015-07-30
 * Description  : 
 * Others       : 
***************************************************************/

#ifndef _TYPE_DEFINE_H_
#define _TYPE_DEFINE_H_

/******************************************************
*                 includes
******************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


typedef signed char TBOOL;
typedef volatile signed char VBOOL;

typedef char  TCHAR;

typedef signed char T8S, TSCHAR;
typedef signed short T16S;
typedef signed long  T32S;

typedef unsigned char  T8U;
typedef unsigned short T16U;
typedef unsigned long  T32U;

typedef volatile signed char V8S;
typedef volatile signed short V16S;
typedef volatile signed long  V32S;

typedef volatile unsigned char  V8U;
typedef volatile unsigned short V16U;
typedef volatile unsigned long  V32U;

typedef enum
{
    HET_SUCCESS = 0x0,
    HET_FAILURE = -1,
    HET_INVALID_PARAMS = -2,
}HETRetVal_e;

#ifndef NULL
#define NULL ((void*)(0))
#endif

#define tdSUCCESS    (0)
#define tdFAILURE    (-1)

#define tdENABLE     (1)
#define tdDISABLE    (0)

#define tdTRUE       (1)
#define tdFALSE      (0)

#define isNULL(this) (NULL == this)
#define MAX(a, b) (((a) > (b)) ? 1 : 0)

#define BYTE_SWAP(a, b) \
        do \
        { \
            T8U t = a; \
            a = b; \
            b = t; \
        }while(0)

#define DATA_VALID_SET(Datas, min, max) \
        do \
        { \
            if(Datas < min) \
            { \
                Datas = min; \
            } \
            else if (Datas > max) \
            { \
                Datas = max; \
            } \
        }while(0)


/* Character code support macros */
#define IsUpper(c) (((c)>='A')&&((c)<='Z'))
#define IsLower(c) (((c)>='a')&&((c)<='z'))
#define IsDigit(c) (((c)>='0')&&((c)<='9'))

#define HexToASCII(c) ((c) += '0')

#define DigitToHex(c) ((c) -= '0')
#define UpperToHex(c) ((c) -= ('A' + 9 + 1))
#define LowerToHex(c) ((c) -= ('a' + 9 + 1))

#define BITS_SET(data, bits) \
        do \
        { \
            if (!((data) & (bits))) \
            { \
                (data) &= ~(bits); \
                (data) |= (bits); \
            } \
        }while(0)

#define BITS_CLR(data, bits) \
        do \
        { \
            if ((data) & (bits)) \
            { \
                (data) &= ~(bits); \
            } \
        }while(0)

#define BITS_XOR(data, bits) \
        do \
        { \
            if (((data) & (bits))) \
            { \
                (data) &= ~(bits); \
            } \
            else \
            { \
                (data) &= ~(bits); \
                (data) |= (bits); \
            } \
        }while(0)

#define BITS_GET(data, bits) \
        ((data) & (bits))

/* High first */
#define C4BYTES2HEX(retval, pBuf) \
        do \
        { \
            if (!isNULL(pBuf)) \
            { \
                retval = ( ((T32U)(*((pBuf) + 0)) << 24) \
                         | ((T32U)(*((pBuf) + 1)) << 16) \
                         | ((T32U)(*((pBuf) + 2)) << 8) \
                         | ((T32U)(*((pBuf) + 3)) << 0)); \
            } \
        }while(0)
        
/* High first */
#define C2BYTES2HEX(retval, pBuf) \
        do \
        { \
            if (!isNULL(pBuf)) \
            { \
                retval = ( ((T32U)(*((pBuf) + 0)) << 8) \
                         | ((T32U)(*((pBuf) + 1)) << 0)); \
            } \
        }while(0)

/* High first */
#define C32HEX2BYTES(pBuf, Data) \
        do \
        { \
            if (!isNULL(pBuf)) \
            { \
                *((pBuf) + 0) =  (T8U)(Data >> 24); \
                *((pBuf) + 1) =  (T8U)(Data >> 16); \
                *((pBuf) + 2) =  (T8U)(Data >> 8); \
                *((pBuf) + 3) =  (T8U)(Data >> 0); \
            } \
        }while(0)

/* High first */
#define C16HEX2BYTES(pBuf, Data) \
        do \
        { \
            if (!isNULL(pBuf)) \
            { \
                *((pBuf) + 0) =  (T8U)(Data >> 8); \
                *((pBuf) + 1) =  (T8U)(Data >> 0); \
            } \
        }while(0)

#define C1BYTE2S16(retVal, pBuf) \
        do \
        { \
            if (!isNULL(pBuf)) \
            { \
                retVal =  (T16S)(*(pBuf)); \
            } \
        }while(0)

#define C1BYTE2U8(retVal, pBuf) \
        do \
        { \
            if (!isNULL(pBuf)) \
            { \
                retVal =  (T8U)(*(pBuf)); \
            } \
        }while(0)

#define MEM_COPY(src, des, len) \
        do \
        { \
            if ((!isNULL(src)) && (!isNULL(des)) && (len > 0))\
            { \
                memcpy(src, des, len); \
            } \
        }while(0)

#define MEM_SET(src, des, len) \
        do \
        { \
            if ((!isNULL(src)) && (len > 0))\
            { \
                memset(src, des, len); \
            } \
        }while(0)

#define MEM_CMP   memcmp

#define HET_BIT0  (T32U)(1 << 0)
#define HET_BIT1  (T32U)(1 << 1)
#define HET_BIT2  (T32U)(1 << 2)
#define HET_BIT3  (T32U)(1 << 3)
#define HET_BIT4  (T32U)(1 << 4)
#define HET_BIT5  (T32U)(1 << 5)
#define HET_BIT6  (T32U)(1 << 6)
#define HET_BIT7  (T32U)(1 << 7)
#define HET_BIT8  (T32U)(1 << 8)
#define HET_BIT9  (T32U)(1 << 9)
#define HET_BIT10 (T32U)(1 << 10)
#define HET_BIT11 (T32U)(1 << 11)
#define HET_BIT12 (T32U)(1 << 12)
#define HET_BIT13 (T32U)(1 << 13)
#define HET_BIT14 (T32U)(1 << 14)
#define HET_BIT15 (T32U)(1 << 15)
#define HET_BIT16 (T32U)(1 << 16)
#define HET_BIT17 (T32U)(1 << 17)
#define HET_BIT18 (T32U)(1 << 18)
#define HET_BIT19 (T32U)(1 << 19)
#define HET_BIT20 (T32U)(1 << 20)
#define HET_BIT21 (T32U)(1 << 21)
#define HET_BIT22 (T32U)(1 << 22)
#define HET_BIT23 (T32U)(1 << 23)
#define HET_BIT24 (T32U)(1 << 24)
#define HET_BIT25 (T32U)(1 << 25)
#define HET_BIT26 (T32U)(1 << 26)
#define HET_BIT27 (T32U)(1 << 27)
#define HET_BIT28 (T32U)(1 << 28)
#define HET_BIT29 (T32U)(1 << 29)
#define HET_BIT30 (T32U)(1 << 30)
#define HET_BIT31 (T32U)(1 << 31)

#endif /*_TYPE_DEFINE_H_*/

