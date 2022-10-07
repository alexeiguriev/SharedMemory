#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

#include "shared_memory.h"
#include "shared_memory_cnf.h"

#define KEY_ID_ARG_INDEX    1

int main(int argc, char *argv[])
{
    key_t key;
    key = atoi(argv[KEY_ID_ARG_INDEX]);
    printf("Key Id: %d\n",key);

    if (argc != 2)
    {
        printf("usage - %s (no args)",argv[0]);
        return -1;
    }

    if (destroy_memory_block(key))
    {
        printf("Destroyed block: %d\n",key);
    }
    else
    {
        printf("Coult not distroy block: %d\n",key);
    }
    return 0;
}