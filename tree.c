#include "tree.h"
#include <stdlib.h>
#include <string.h>

int tree_parse(const void *data, size_t len, Tree *tree_out) { (void)data; (void)len; (void)tree_out; return 0; }
int tree_serialize(const Tree *tree, void **data_out, size_t *len_out) { (void)tree; (void)data_out; (void)len_out; return 0; }
int tree_from_index(const ObjectID *id_out) { (void)id_out; return 0; }
