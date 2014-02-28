#ifndef GCJ_INTERFACE_H
#define GCJ_INTERFACE_H

#include <libfirm/firm.h>
#include "class_file.h"

#define GCJI_LENGTH_OFFSET 4
#define GCJI_DATA_OFFSET   8

void       gcji_init(void);
void       gcji_deinit(void);
void       gcji_class_init(ir_type *type, ir_graph *irg, ir_node *block, ir_node **mem);
ir_node   *gcji_allocate_object(ir_type *type, ir_graph *irg, ir_node *block, ir_node **mem);
ir_node   *gcji_allocate_array(ir_type *eltype, ir_node *count, ir_graph *irg, ir_node *block, ir_node **mem);
ir_entity *gcji_emit_utf8_const(constant_t *constant, int mangle_slash);
ir_node   *gcji_new_string(ir_entity *bytes, ir_graph *irg, ir_node *block, ir_node **mem);
ir_node   *gcji_get_arraylength(dbg_info *dbgi, ir_node *block, ir_node *arrayref, ir_node **mem);
ir_node   *gcji_get_arrayclass(ir_node *array_class_ref, ir_graph *irg, ir_node *block, ir_node **mem);
ir_node   *gcji_new_multiarray(ir_node *array_class_ref, unsigned dims, ir_node **sizes, ir_graph *irg, ir_node *block, ir_node **mem);
ir_entity *gcji_get_rtti_object(ir_type *classtype);
ir_node   *gcji_get_runtime_classinfo(ir_type *type, ir_graph *irg, ir_node *block, ir_node **mem);
void       gcji_create_rtti(class_t *cls, ir_type* classtype);
ir_node   *gcji_lookup_interface(ir_node *obptr, ir_type *iface, ir_entity *method, ir_graph *irg, ir_node *block, ir_node **mem);
ir_node   *gcji_instanceof(ir_node *objptr, ir_type *classtype, ir_graph *irg, ir_node *block, ir_node **mem);
void       gcji_checkcast(ir_type *classtype, ir_node *objptr, ir_graph *irg, ir_node *block, ir_node **mem);
void       gcji_create_vtable_entity(ir_type *type);
void       gcji_init_java_lang_class(ir_type *type);
void       gcji_set_java_lang_class(ir_type *type);

#endif
