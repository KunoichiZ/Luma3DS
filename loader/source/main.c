#include "memory.h"

void main(void)
{
    void *payloadAddress = (void *)0x23F00000;

    memcpy(payloadAddress, (void*)0x24F00000, *(u32 *)0x24FFFF04);
    cleanInvalidateDCacheAndDMB(); //Ensure that all memory transfers have completed and that the data cache has been flushed 

    ((void (*)())payloadAddress)();
}