#ifndef IIOP_H
#define IIOP_H 1

#include <unistd.h>
#include <ORBitutil/util.h>
#include "IIOP-config.h"
#include "IIOP-types.h"
#include "giop-msg-buffer.h"
#include "iiop-encoders.h"
#include "iiop-endian.h"

/* We don't speak GIOP 1.0, sosumi */
#define GIOP_1_1

#undef GIOP_INTERNAL_DEBUG

void giop_init(const char *argv0);

/* You use this to get a pointer to a new (or existing) connection
   that has the specified host/port characteristics */
IIOPConnection *iiop_connection_get(const char *host, gushort port,
				    gboolean existing_only);
/* Similar, but for UNIX sockets */
IIOPConnection *iiop_connection_unix_get(const char *sockpath,
					 gboolean existing_only);

/* gives us a local socket that other people can connect to... */
IIOPConnection *iiop_connection_server(void);
IIOPConnection *iiop_connection_server_ipv6(void);
IIOPConnection *iiop_connection_server_unix(const char *sockpath);

void giop_main_quit(void);
void giop_main(void); /* main loop for the program if none other is given,
			 and also used while waiting for a reply */
void giop_main_iterate(gboolean blocking);
void giop_main_handle_connection(GIOPConnection *connection);
void giop_main_handle_connection_exception(GIOPConnection *connection);
GIOPRecvBuffer *giop_main_next_message(gboolean blocking);
GIOPRecvBuffer *giop_main_next_message_2(gboolean blocking,
					 GIOPConnection *monitor);
GIOPConnection *giop_check_connections(gboolean block_for_reply);

/* This assumes that the appropriate GIOP_CLOSECONNECTION message
   has been sent to the peer */
void giop_connection_free(GIOPConnection *connection);

/* Called when a connection is created */
extern void (*IIOPAddConnectionHandler)(GIOPConnection *newcnx);
/* Called when a connection is about to be destroyed */
extern void (*IIOPRemoveConnectionHandler)(GIOPConnection *oldcnx);
extern void (*IIOPIncomingMessageHandler)(GIOPRecvBuffer *recv_buffer);

#endif /* IIOP_H */
