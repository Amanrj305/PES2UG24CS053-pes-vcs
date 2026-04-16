#include "index.h"
#include <stdlib.h>
#include <string.h>

int index_load(Index *index) { (void)index; return 0; }
int index_save(const Index *index) { (void)index; return 0; }
int index_add(Index *index, const char *path) { (void)index; (void)path; return 0; }
int index_remove(Index *index, const char *path) { (void)index; (void)path; return 0; }
IndexEntry* index_find(Index *index, const char *path) { (void)index; (void)path; return NULL; }
int index_status(const Index *index) { (void)index; return 0; }
