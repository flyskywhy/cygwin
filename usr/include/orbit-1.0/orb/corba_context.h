#ifndef CORBA_CONTEXT_H
#define CORBA_CONTEXT_H 1

#include "orbit_object_type.h"
#include "orbit_object.h"

typedef struct {
  CORBA_unsigned_long len;
  const CORBA_char *str;
} ORBit_ContextMarshalItem;

typedef struct CORBA_Context_type *CORBA_Context;

struct CORBA_Context_type {
  struct ORBit_PseudoObject_struct parent;
  GHashTable *mappings;
  GSList *children;

  char *the_name;

  CORBA_Context parent_ctx;
};


extern CORBA_Status CORBA_Context_set_one_value(
	CORBA_Context ctx,
	CORBA_Identifier prop_name,
	char *value,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_Context_set_values(
	CORBA_Context ctx,
	CORBA_NVList *values,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_Context_get_values(
	CORBA_Context ctx,
	CORBA_Identifier start_scope,
	CORBA_Flags op_flags,
	CORBA_Identifier prop_name,
	CORBA_NVList **values,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_Context_delete_values(
	CORBA_Context ctx,
	CORBA_Identifier prop_name,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_Context_create_child(
	CORBA_Context ctx,
	CORBA_Identifier ctx_name,
	CORBA_Context *child_ctx,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_Context_delete(
	CORBA_Context ctx,
	CORBA_Flags del_flags,
	CORBA_Environment *ev);

void ORBit_Context_marshal(CORBA_Context ctx, const ORBit_ContextMarshalItem *mlist,
			   CORBA_unsigned_long nitems, GIOPSendBuffer *buf);
void ORBit_Context_demarshal(CORBA_Context parent, CORBA_Context initme, GIOPRecvBuffer *recv_buffer);
void ORBit_Context_server_free(CORBA_Context ctx);

#endif
