#ifndef ENCODERS_H
#define ENCODERS_H 1

#define ENCODER_DEC(typename) \
void giop_encoder_##typename(GIOPSendBuffer *send_buffer, \
			     const typename *mem)

#define ENCODER_CALL(typename, mem) \
giop_encoder_##typename(send_buffer, mem)

#define AP(m, l) giop_message_buffer_append_mem(GIOP_MESSAGE_BUFFER(send_buffer), m, l)
#define APA(m, l) giop_message_buffer_append_mem_a(GIOP_MESSAGE_BUFFER(send_buffer), m, l)

#define API(m, l) giop_send_buffer_append_mem_indirect(send_buffer, m, l)
#define APIA(m, l) giop_send_buffer_append_mem_indirect_a(send_buffer, m, l)

ENCODER_DEC(IOP_ServiceContext);
ENCODER_DEC(IOP_ServiceContextList);
ENCODER_DEC(CORBA_sequence_octet);
ENCODER_DEC(CORBA_Principal);
#define giop_encoder_CORBA_Principal(rb, mem) \
	giop_encoder_CORBA_sequence_octet(rb, mem)
ENCODER_DEC(CORBA_char);

#endif /* ENCODERS_H */
