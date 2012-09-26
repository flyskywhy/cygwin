#ifndef _ORBIT_CORBA_ANY_PROTO_H_
#define _ORBIT_CORBA_ANY_PROTO_H_

void ORBit_marshal_arg(GIOPSendBuffer *buf,
		       gpointer val,
		       CORBA_TypeCode tc);
void ORBit_marshal_any(GIOPSendBuffer *buf, const CORBA_any *val);
gpointer ORBit_demarshal_arg(GIOPRecvBuffer *buf,
			     CORBA_TypeCode tc,
			     gboolean dup_strings,
			     CORBA_ORB orb);
void ORBit_demarshal_any(GIOPRecvBuffer *buf, CORBA_any *retval,
			 gboolean dup_strings,
			 CORBA_ORB orb);

#endif /* !_ORBIT_CORBA_ANY_PROTO_H_ */
