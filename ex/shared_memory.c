#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shared_memory.h"

static int get_shared_block(key_t key, int size)
{
    int retVal;

    retVal = shmget(key, size, 0644 | IPC_CREAT);

    return retVal;
}

char* attach_memory_block(key_t key, int size)
{
    int share_block_id = get_shared_block(key, size);
    char* result;

    if (share_block_id == IPC_RESULT_ERROR)
    {
        result = NULL;
    }
    else
    {
        // map the shared block into this process's momory
        // and give me a pointer to it

        result = shmat(share_block_id, NULL, 0);
        
        if (result == (char*) IPC_RESULT_ERROR)
        {
            return NULL;
        }
    }

    return result;
}
bool detach_memory_block(char* block)
{
    return (shmdt(block) != IPC_RESULT_ERROR);
}

bool destroy_memory_block(key_t key)
{
    bool retVal;
    int shared_momory_id = get_shared_block(key, 0);

    if (shared_momory_id == IPC_RESULT_ERROR)
    {
        retVal = NULL;
    }
    else
    {
        retVal = (shmctl(shared_momory_id ,IPC_RMID, NULL) != IPC_RESULT_ERROR);
    }


    return retVal;
}