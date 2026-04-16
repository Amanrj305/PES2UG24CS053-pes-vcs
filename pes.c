#include "pes.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: pes <command> [args]
");
        return 1;
    }
    if (strcmp(argv[1], "init") == 0) {
        printf("init
");
    }
    return 0;
}
