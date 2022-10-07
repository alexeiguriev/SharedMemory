#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared_memory.h"
#include "shared_memory_cnf.h"

#define KEY_ID_ARG_INDEX 2
int main(int argc, char* argv[])
{
    key_t key;
    key = atoi(argv[KEY_ID_ARG_INDEX]);
    printf("Key Id: %d\n",key);

    if (argc != 3)
    {
        printf("usage - %s [stuff to write]",argv[0]);
        return -1;
    }

    // grab the shared memory blick
    char* block = attach_memory_block(key, BLOCK_SIZE);
    if (block == NULL)
    {
        printf("ERROR: couldn't get block\n");
        return -1;
    }

    printf("Writing: \"%s\"\n", argv[1]);
    strncpy(block,argv[1],BLOCK_SIZE);

    detach_memory_block(block);

    return 0;
}