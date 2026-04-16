#ifndef PES_H
#define PES_H

#include <stdint.h>
#include <stddef.h>

#define HASH_SIZE 32
#define HASH_HEX_SIZE 64
#define PES_DIR ".pes"
#define OBJECTS_DIR ".pes/objects"
#define REFS_DIR ".pes/refs/heads"
#define INDEX_FILE ".pes/index"
#define HEAD_FILE ".pes/HEAD"

typedef enum { OBJ_BLOB, OBJ_TREE, OBJ_COMMIT } ObjectType;

typedef struct { uint8_t hash[HASH_SIZE]; } ObjectID;

void hash_to_hex(const ObjectID *id, char *hex_out);
int hex_to_hash(const char *hex, ObjectID *id_out);
const char* pes_author(void);

#endif // PES_H
