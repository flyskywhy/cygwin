#ifndef ORBIT_IDL2_H
#define ORBIT_IDL2_H 1

#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <libIDL/IDL.h>
#include <ORBitutil/basic_types.h>
#define _ORBIT_H_	/* kludge - we only want ORBIT_SERIAL */
#include <orb/orbit.h>

typedef struct {
  char *cpp_args;
  int debug_level;

  enum { OUTPUT_STUBS=1<<0,
	 OUTPUT_SKELS=1<<1,
	 OUTPUT_COMMON=1<<2,
	 OUTPUT_HEADERS=1<<3,
	 OUTPUT_SKELIMPL=1<<4 } enabled_passes;

  char *output_formatter;

  char *output_language;
  char *input_filename;
  char *backend_directory;
} OIDL_Run_Info;

int orbit_idl_to_backend(const char *filename, OIDL_Run_Info *rinfo);

typedef struct {
  IDL_tree tree;
} OIDL_Output_Tree;

/* yadda yadda:
   Fixed length as in bulk-marshallable
   Fixed length as in a terminal allocation.

   Turn an IDL_LIST of params into a tree of marshalling info.
     Each node will need to give:
         Type (datum, loop, switch, string, complex)
	 Name
	 Subnodes (loop & switch only)
	 Dependencies

   Note for string_info.length_var, loop_info.loop_var, switch_info.discrim - these are all subnodes of the current node,
   not pointers to other unrelated nodes.

   dependencies is a list of pointers to unrelated nodes.
 */
typedef struct _OIDL_Marshal_Node OIDL_Marshal_Node;

typedef enum { MARSHAL_DATUM = 0,
	       MARSHAL_LOOP = 1,
	       MARSHAL_SWITCH = 2,
	       MARSHAL_CASE = 3,
	       MARSHAL_COMPLEX = 4,
	       MARSHAL_CONST = 5,
	       MARSHAL_SET = 6
} OIDL_Marshal_Node_Type;

typedef enum {
  MN_INOUT = 1<<0, /* Needs freeing before alloc */
  MN_NSROOT = 1<<1, /* Don't go to parents for variable naming */
  MN_NEED_TMPVAR = 1<<2, /* Need a temporary variable to hold this value */
  MN_NOMARSHAL = 1<<3, /* This is used by other vars, but not actually marshalled */
  MN_ISSEQ = 1<<4, /* for MARSHAL_LOOP only - we need to do foo._buffer before tacking on [v1] */
  MN_ISSTRING = 1<<5, /* for MARSHAL_LOOP only */
  MN_LOOPED = 1<<6, /* This variable is looped over */
  MN_COALESCABLE = 1<<7, /* You can coalesce multiple sequential instances of this type into one encode/decode operation */
  MN_ENDIAN_DEPENDANT = 1<<8,
  MN_DEMARSHAL_UPDATE_AFTER = 1<<9,
  MN_DEMARSHAL_CORBA_ALLOC = 1<<10, /* Set if we can never allocate this thingie on the stack (i.e. an inout param) */
  MN_DEMARSHAL_USER_MOD = 1<<11 /* OK, so this is just a hack to fix usage of the above flag */
} OIDL_Marshal_Node_Flags;

struct _OIDL_Marshal_Node {
  OIDL_Marshal_Node *up;
  char *name;
  IDL_tree tree;
  OIDL_Marshal_Node_Type type;
  GSList *dependencies;
  union {
    struct {
      OIDL_Marshal_Node *loop_var, *length_var;
      OIDL_Marshal_Node *contents;
    } loop_info;
    struct {
      OIDL_Marshal_Node *discrim;
      GSList *cases;
    } switch_info;
    struct {
      GSList *labels;
      OIDL_Marshal_Node *contents;
    } case_info;
    struct {
      guint32 datum_size;
    } datum_info;
    struct {
      OIDL_Marshal_Node *amount;
    } update_info;
    struct {
      guint32 amount;
    } const_info;
    struct {
      enum { CX_CORBA_FIXED, CX_CORBA_ANY, CX_CORBA_OBJECT, CX_CORBA_TYPECODE, CX_CORBA_CONTEXT } type;
      int context_item_count;
    } complex_info;
    struct {
      GSList *subnodes;
    } set_info;
  } u;
  OIDL_Marshal_Node_Flags flags;
  guint8 arch_head_align, arch_tail_align;
  guint8 iiop_head_align, iiop_tail_align;
  guint8 nptrs;
};

/* Handling an IDLN_ATTR_DCL:
   foreach(node->simple_declarations) {
       turn node->data into a OIDL_Attr_Info.
       Process op1 & op2.
   }
*/
typedef struct {
  IDL_tree op1, op2;
} OIDL_Attr_Info;
typedef struct {
  OIDL_Marshal_Node *in_stubs, *out_stubs, *in_skels, *out_skels;
  int counter;
} OIDL_Op_Info;
typedef struct {
  OIDL_Marshal_Node *marshal, *demarshal;
} OIDL_Except_Info;

typedef struct {
  const char *name;
  void (*op_output)(OIDL_Output_Tree *tree, OIDL_Run_Info *rinfo);
} OIDL_Backend_Info;
OIDL_Backend_Info *orbit_idl_backend_for_lang(const char *lang,const char *backend_dir);

/* genmarshal */
OIDL_Marshal_Node *orbit_idl_marshal_populate_in(IDL_tree tree, gboolean is_skels);
OIDL_Marshal_Node *orbit_idl_marshal_populate_out(IDL_tree tree, gboolean is_skels);
OIDL_Marshal_Node *orbit_idl_marshal_populate_except_marshal(IDL_tree tree);
OIDL_Marshal_Node *orbit_idl_marshal_populate_except_demarshal(IDL_tree tree);
char *oidl_marshal_node_fqn(OIDL_Marshal_Node *node);
char *oidl_marshal_node_valuestr(OIDL_Marshal_Node *node);

/* passes */
void orbit_idl_do_passes(IDL_tree tree, OIDL_Run_Info *rinfo);

/* Utils */
void orbit_idl_attr_fake_ops(IDL_tree attr, IDL_ns ns);
void oidl_marshal_tree_dump(IDL_tree tree, int indent_level);
void oidl_marshal_node_dump(OIDL_Marshal_Node *tree, int indent_level);
void orbit_idl_print_node(IDL_tree node, int indent_level);
IDL_tree orbit_idl_get_array_type(IDL_tree tree);
char *orbit_idl_member_get_name(IDL_tree tree);
void orbit_idl_node_foreach(OIDL_Marshal_Node *node, GFunc func, gpointer user_data);
void IDL_tree_traverse_parents(IDL_tree p, GFunc f, gconstpointer func_data);
gboolean orbit_cbe_type_contains_complex(IDL_tree ts);

typedef enum { DATA_IN=1, DATA_INOUT=2, DATA_OUT=4, DATA_RETURN=8 } IDL_ParamRole;
gint oidl_param_numptrs(IDL_tree param, IDL_ParamRole role);
gboolean orbit_cbe_type_is_fixed_length(IDL_tree ts);
IDL_tree orbit_cbe_get_typespec(IDL_tree node);
IDL_ParamRole oidl_attr_to_paramrole(enum IDL_param_attr attr);

#define ORBIT_RETVAL_VAR_NAME "_ORBIT_retval"

#endif /* ORBIT_IDL2_H */
