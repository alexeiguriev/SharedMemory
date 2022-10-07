#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <stdbool.h>

#define IPC_RESULT_ERROR (-1)

// attach a shared memory block
// associated with filename
// create it if it doesn't exist

char* attach_memory_block(char* filename, int size);
bool detach_memory_block(char* block);
bool destroy_memory_block(char* filename);

#endif /* SHARED_MEMORY_H */