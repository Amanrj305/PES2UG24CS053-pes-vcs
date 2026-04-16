#include "commit.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int commit_create(const char *message, ObjectID *commit_id_out) { (void)message; (void)commit_id_out; return 0; }
int commit_parse(const void *data, size_t len, Commit *commit_out) { (void)data; (void)len; (void)commit_out; return 0; }
int commit_serialize(const Commit *commit, void **data_out, size_t *len_out) { (void)commit; (void)data_out; (void)len_out; return 0; }
int commit_walk(commit_walk_fn callback, void *ctx) { (void)callback; (void)ctx; return 0; }
int head_read(ObjectID *id_out) { (void)id_out; return 0; }
int head_update(const ObjectID *new_commit) { (void)new_commit; return 0; }
