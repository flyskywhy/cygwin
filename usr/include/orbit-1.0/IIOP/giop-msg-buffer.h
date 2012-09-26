#ifndef GIOP_MSG_BUFFER_H
#define GIOP_MSG_BUFFER_H 1

#include "IIOP.h"
/* For struct iovec */
#include <sys/uio.h>

typedef enum {
  GIOP_REQUEST,
  GIOP_REPLY,
  GIOP_CANCELREQUEST,
  GIOP_LOCATEREQUEST,
  GIOP_LOCATEREPLY,
  GIOP_CLOSECONNECTION,
  GIOP_MESSAGEERROR,
  GIOP_FRAGMENT
} GIOPMsgType;

/* GIOP message header */
typedef struct _GIOPMessageHeader {
  GIOP_char magic[4];
  GIOP_char GIOP_version[2];
  GIOP_octet flags;

  /*
   * We should really use GIOPMsgType
   * but that enum winds up being an int...
   */
  GIOP_octet message_type;

  GIOP_unsigned_long message_size;
} GIOPMessageHeader;

#define GIOP_MESSAGE_BUFFER(x) ((GIOPMessageBuffer *)x)
typedef struct _GIOPMessageBuffer
{
  /* The connection that this message will go out over... */
  GIOPConnection *connection; 
				 
  GArray *iovecs;
  GIOPMessageHeader message_header;
} GIOPMessageBuffer;

#include "../orb/iop.h"

/* GIOP_REQUEST header */
typedef enum {
  GIOP_NO_EXCEPTION,
  GIOP_USER_EXCEPTION,
  GIOP_SYSTEM_EXCEPTION,
  GIOP_LOCATION_FORWARD
} GIOPReplyStatusType;

typedef struct _GIOPMessageRequest {
  IOP_ServiceContextList service_context;
  GIOP_unsigned_long request_id;
  GIOP_boolean response_expected;
  CORBA_sequence_octet object_key;
  CORBA_char *operation;
  CORBA_Principal requesting_principal;
} GIOPMessageRequest;

typedef struct _GIOPMessageReply {
  IOP_ServiceContextList service_context;
  GIOP_unsigned_long request_id;
  GIOPReplyStatusType reply_status;
} GIOPMessageReply;

typedef struct _GIOPMessageCancelRequest {
  GIOP_unsigned_long request_id;
} GIOPMessageCancelRequest;

typedef struct _GIOPMessageLocateRequest {
  GIOP_unsigned_long request_id;
  CORBA_sequence_octet object_key;
} GIOPMessageLocateRequest;

typedef enum {
  GIOP_UNKNOWN_OBJECT,
  GIOP_OBJECT_HERE,
  GIOP_OBJECT_FORWARD
} GIOPLocateStatusType;

typedef struct _GIOPMessageLocateReply {
  GIOP_unsigned_long request_id;
  GIOPLocateStatusType locate_status;
} GIOPMessageLocateReply;

typedef struct _GIOPMessage
{
  union {
    GIOPMessageRequest request;
    GIOPMessageReply reply;
    GIOPMessageCancelRequest cancel_request;
    GIOPMessageLocateRequest locate_request;
    GIOPMessageLocateReply locate_reply;
  } u;
} GIOPMessage;

typedef enum {
  GIOP_MSG_READING_HEADER,
  GIOP_MSG_READING_BODY,
  GIOP_MSG_READY
} GIOPMessageBufferState;

#define GIOP_SEND_BUFFER(x) ((GIOPSendBuffer *)x)
typedef struct _GIOPSendBuffer
{
  GIOPMessageBuffer message_buffer;

  gpointer indirect;

  GMemChunk *indirects; /* Request buffers only (at present) */
  gulong indirect_used;

  GIOPMessage message;
  CORBA_unsigned_long scontext_tmp;
} GIOPSendBuffer;

#define GIOP_RECV_BUFFER(x) ((GIOPRecvBuffer *)x)
typedef struct _GIOPRecvBuffer
{
  GIOPMessageBuffer message_buffer;
  GIOPMessage message;

  gpointer message_body;
  gpointer cur;

  void (*decoder)(gpointer dest, gpointer src, gulong len);

  GIOPMessageBufferState state;
  gint left_to_read;
} GIOPRecvBuffer;

/* This function needs to be called before useful things happen */
void giop_message_buffer_init(void);

gint giop_send_buffer_write(GIOPSendBuffer *request_buffer);

void 
giop_message_buffer_append_mem_a(GIOPMessageBuffer *request_buffer,
				 gconstpointer mem_region,
				 gulong mem_region_length);
void 
giop_message_buffer_append_mem(GIOPMessageBuffer *request_buffer,
			       gconstpointer mem_region,
			       gulong mem_region_length);

/*
 * This copies the value into a request-specific buffer before
 * adding it to the list
 */
gpointer
giop_send_buffer_append_mem_indirect_a(GIOPSendBuffer *request_buffer,
				       gconstpointer mem_region,
				       gulong mem_region_length);
gpointer
giop_send_buffer_append_mem_indirect(GIOPSendBuffer *request_buffer,
				     gconstpointer mem_region,
				     gulong mem_region_length);

GIOPSendBuffer *
giop_send_request_buffer_use(GIOPConnection *connection,
			     const IOP_ServiceContextList *service_context,
			     GIOP_unsigned_long request_id,
			     GIOP_boolean response_expected,
			     const struct iovec *object_key_vec,
			     const struct iovec *operation_vec,
			     const struct iovec *principal_vec);
GIOPSendBuffer *
giop_send_reply_buffer_use(GIOPConnection *connection,
			   const IOP_ServiceContextList *service_context,
			   GIOP_unsigned_long request_id,
			   GIOPReplyStatusType reply_status);
GIOPSendBuffer *
giop_send_locate_request_buffer_use(GIOPConnection *connection,
			     GIOP_unsigned_long request_id,
			     const struct iovec *object_key_vec);
GIOPSendBuffer *
giop_send_locate_reply_buffer_use(GIOPConnection *connection,
			   GIOP_unsigned_long request_id,
			   GIOPLocateStatusType reply_status);

void giop_send_buffer_unuse(GIOPSendBuffer *send_buffer);

GIOP_unsigned_long giop_get_request_id(void);

GIOPRecvBuffer *
giop_recv_reply_buffer_use(GIOP_unsigned_long request_id,
			   gboolean block_for_reply);
GIOPRecvBuffer *
giop_recv_reply_buffer_use_2(GIOPConnection *request_cnx,
			     GIOP_unsigned_long request_id,
			     gboolean block_for_reply);

/* For DII - hands back the first received request matching an id on the list */
GIOPRecvBuffer *
giop_recv_reply_buffer_use_multiple(GArray *request_ids,
				    gboolean block_for_reply);
GIOPRecvBuffer *
giop_recv_reply_buffer_use_multiple_2(GIOPConnection *request_cnx,
				      GArray *request_ids,
				      gboolean block_for_reply);

GIOPRecvBuffer *
giop_recv_locate_reply_buffer_use(GIOP_unsigned_long request_id,
				  gboolean block_for_reply);

/*
 * For server-side use. It's the responsibility of the caller to do
 * any select()ion desired
 */
GIOPRecvBuffer *
giop_recv_message_buffer_use(GIOPConnection *connection);

void giop_recv_buffer_unuse(GIOPRecvBuffer *buffer);

/*
 * This is used for sending (and recving, if we ever
 *  get zero-copy receives implemented) alignment bytes
 */ 
extern char giop_scratch_space[2048];
gulong giop_message_buffer_do_alignment(GIOPMessageBuffer *buffer,
					gulong align_for);

#define giop_msg_conversion_needed(msgbuf) (conversion_needed(GIOP_MESSAGE_BUFFER(msgbuf)->message_header.flags & 1))

#endif /* GIOP_MSG_BUFFER_H */
