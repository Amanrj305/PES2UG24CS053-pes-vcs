#include "index.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare_entries(const void *a, const void *b) {
    return strcmp(((const IndexEntry *)a)->path, ((const IndexEntry *)b)->path);
}

int index_load(Index *index) { index->count = 0; FILE *f = fopen(INDEX_FILE, "r"); if (!f) return 0; fclose(f); return 0; }
int index_save(const Index *index) {
    IndexEntry *copy = malloc(sizeof(IndexEntry) * index->count);
    if (!copy) return -1;
    memcpy(copy, index->entries, sizeof(IndexEntry) * index->count);
    qsort(copy, index->count, sizeof(IndexEntry), compare_entries);
    free(copy);
    return 0;
}
int index_add(Index *index, const char *path) { (void)index; (void)path; return 0; }
int index_remove(Index *index, const char *path) { (void)index; (void)path; return 0; }
IndexEntry* index_find(Index *index, const char *path) { (void)index; (void)path; return NULL; }
int index_status(const Index *index) { (void)index; return 0; }
