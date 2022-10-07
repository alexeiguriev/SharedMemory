#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <stdbool.h>

#include <sys/types.h>

#define IPC_RESULT_ERROR (-1)

// attach a shared memory block
// associated with filename
// create it if it doesn't exist

char* attach_memory_block(key_t key, int size);
bool detach_memory_block(char* block);
bool destroy_memory_block(key_t key);

#endif /* SHARED_MEMORY_H */