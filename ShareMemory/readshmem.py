import sysv_ipc
import shared_memory as sh
import shared_memory_cnf as cfg

import argparse
import sys

print ('Number of arguments:', len(sys.argv), 'arguments.')
print ('Argument List:', str(sys.argv))

if (len(sys.argv) != 2):
    print(f"usage - {sys.argv} // no args)")

key = int(sys.argv[1])

globalMessage = ''
def main():
    
    print(f"Key Id: {key}\n");
    
    try:
        memory = sysv_ipc.SharedMemory(key)
    except Exception as e:
        print(e)
        print(f"Memmory block with is: {key} cannot be find\n")
    
    try:
        memory_value = str(memory.read())

        memory_value = memory_value.replace("\\x00","").replace("b'","")
        memory_value = memory_value[:-1]
        globalMessage = memory_value
        print(memory_value)
    except Exception as e:
        print(e)
        print(f"Read data failed\n")

main()
