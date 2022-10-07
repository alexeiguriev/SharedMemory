#include <stdio.h>
#include <stdlib.h>

#include "shared_memory.h"
#include "shared_memory_cnf.h"

#define KEY_ID_ARG_INDEX    1
int main(int argc, char* argv[])
{
    key_t key;
    key = atoi(argv[KEY_ID_ARG_INDEX]);
    printf("Key Id: %d\n",key);

    if (argc != 2)
    {
        printf("usage - %s // no args)",argv[0]);
        return -1;
    }

    // grab the shared memory blick
    char* block = attach_memory_block(key, BLOCK_SIZE);
    if (block == NULL)
    {
        printf("ERROR: couldn't get block\n");
        return -1;
    }

    printf("Reading: \"%s\"\n", block);

    detach_memory_block(block);

    return 0;
}