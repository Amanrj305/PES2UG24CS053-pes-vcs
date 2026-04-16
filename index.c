#include "index.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

static int compare_entries(const void *a, const void *b) {
    return strcmp(((const IndexEntry *)a)->path, ((const IndexEntry *)b)->path);
}

int index_load(Index *index) {
    index->count = 0;
    FILE *f = fopen(INDEX_FILE, "r");
    if (!f) return 0;
    char hash_hex[HASH_HEX_SIZE + 1];
    while (fscanf(f, "%o %64s %lu %lu %511s", &index->entries[index->count].mode, hash_hex, &index->entries[index->count].mtime_sec, &index->entries[index->count].size, index->entries[index->count].path) == 5) {
        hex_to_hash(hash_hex, &index->entries[index->count].hash);
        index->count++;
    }
    fclose(f);
    return 0;
}
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
IndexEntry* index_find(Index *index, const char *path) {
    for (int i = 0; i < index->count; i++)
        if (strcmp(index->entries[i].path, path) == 0)
            return &index->entries[i];
    return NULL;
}
int index_status(const Index *index) { (void)index; return 0; }
