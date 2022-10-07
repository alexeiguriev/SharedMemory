import sysv_ipc
import shared_memory_cnf as cfg

import argparse
import sys

print ('Number of arguments:', len(sys.argv), 'arguments.')
print ('Argument List:', str(sys.argv))

if (len(sys.argv) != 3):
    print(f"usage - {sys.argv} // no args)")

writeMessage = str(sys.argv[1])
key = int(sys.argv[2])

def main():
    sysv_memory = ''
    print(f"Key Id: {key}\n");
    
    try:
        sysv_memory=sysv_ipc.SharedMemory(key, sysv_ipc.IPC_CREAT, 644, cfg.BLOCK_SIZE)
    except Exception as e:
        print(e)
        print(f"Memmory block with is: {key} cannot be created\n")
    
    try:
        print(f"Writing: \"{writeMessage}\"\n")
        sysv_memory.write(writeMessage + '\0')
    except Exception as e:
        print(e)
        print(f"Write data failed\n")

main()
