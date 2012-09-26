#ifndef _ORBIT_ORBIT_TYPECODE_H_
#define _ORBIT_ORBIT_TYPECODE_H_

#include "orbit_types.h"

extern const ORBit_RootObject_Interface ORBit_TypeCode_epv;
void ORBit_encode_CORBA_TypeCode(CORBA_TypeCode tc, GIOPSendBuffer* buf);
void ORBit_decode_CORBA_TypeCode(CORBA_TypeCode* tc, GIOPRecvBuffer* buf);

#endif
