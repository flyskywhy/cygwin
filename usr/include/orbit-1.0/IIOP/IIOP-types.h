#ifndef IIOP_TYPES_H
#define IIOP_TYPES_H 1

/* XXX todo sync this up with basic_types.h if needed */
#include <unistd.h>
#include <netinet/in.h>
#include <sys/un.h>

#include <ORBitutil/basic_types.h>

typedef enum {
  GIOP_CONNECTION_SERVER, /* Not a real connection to any place - just
			     listening */
  GIOP_CONNECTION_CLIENT
} GIOPConnectionClass;

typedef struct _GIOPConnection GIOPConnection;
struct _GIOPConnection {
  enum { GIOP_CONNECTION_NONE, GIOP_CONNECTION_IIOP } connection_type;
  void (*destroy_func)(GIOPConnection *connection);

  gint refcount;
  GIOPConnectionClass connection_class;

  int fd;

  /* You can access these if you wish. */
  gpointer orb_data;
  gpointer user_data;
  /* end accessable stuff */

  guchar is_valid, was_initiated, is_auth;

  gpointer incoming_msg; /* GIOPRecvBuffer */
};

#define GIOP_CONNECTION(x) ((GIOPConnection *)(x))
#define GIOP_CONNECTION_GET_FD(x) (GIOP_CONNECTION((x))->fd)

typedef enum { IIOP_IPV4, IIOP_IPV6, IIOP_USOCK } IIOPConnectionType;

typedef struct {
  GIOPConnection giop_connection;

  gboolean is_serversock;
  IIOPConnectionType icnxtype;
  union {
    struct {
      char *hostname;
      struct sockaddr_in location;
    } ipv4;
    struct sockaddr_un usock;
    /* Yes this is a config.h define, and no it doesn't matter,
       because this structure should only be used internally anyways */
#ifdef HAVE_IPV6
    struct {
      char *hostname;
      struct sockaddr_in6 location;
    } ipv6;
#endif
  } u;
} IIOPConnection;

#define IIOP_CONNECTION(x) ((IIOPConnection *)(x))

#if defined(DEBUG_sopwith_connection_refcounting)
#define giop_connection_ref(x) G_STMT_START{ (GIOP_CONNECTION(x)->refcount++); g_print("!   reffing fd %d in " __PRETTY_FUNCTION__ ":%d to %d\n", GIOP_CONNECTION_GET_FD(x), __LINE__, GIOP_CONNECTION(x)->refcount); }G_STMT_END

#define giop_connection_unref(x) G_STMT_START{ GIOP_CONNECTION(x)->refcount--; g_print("!   dereffing fd %d in " __PRETTY_FUNCTION__ ":%d to %d\n", GIOP_CONNECTION_GET_FD(x), __LINE__, GIOP_CONNECTION(x)->refcount); if(GIOP_CONNECTION(x)->refcount <= 0) giop_connection_free(x); }G_STMT_END
#else
#define giop_connection_ref(x) G_STMT_START{ (GIOP_CONNECTION(x)->refcount++); }G_STMT_END

#define giop_connection_unref(x) G_STMT_START{ GIOP_CONNECTION(x)->refcount--; if(GIOP_CONNECTION(x)->refcount <= 0) giop_connection_free(x); }G_STMT_END
#endif

#endif /* IIOP_TYPES_H */
