/***************************************************************
 * Copyright (C), 2015-2025, H&T Tech
 * File name    : HetProtocolConfig.h
 * Author       : Bernie Liu
 * Version      : V1.0.0
 * Date         : 2015-09-08
 * Description  : 
 * Others       : 
***************************************************************/

#ifndef _HET_PROTOCOL_CONFIG_H_
#define _HET_PROTOCOL_CONFIG_H_

#ifdef  __cplusplus
extern "C" {
#endif

#if defined(PROTOCOL_COMM_HET)  
/* Het protocol by self */

#elif defined(PROTOCOL_COMM_THIRD) 
/* Third open protocol */

    //#include "..\Framework\Protocol\ThirdOpen\ThirdProtocolFrame.h"
    //#include "..\Framework\Protocol\ThirdOpen\ThirdProtocol.h"

#elif defined(PROTOCOL_COMM_HOMEKIT)
/* Apple Homekit protocol */

    
#endif

#ifdef  __cplusplus
}
#endif // __cplusplus

#endif /* _HET_PROTOCOL_CONFIG_H_ */
