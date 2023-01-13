#include<stdio.h>
#include<stdlib.h>
float* getMemory(int n)
{
    return(malloc(n * sizeof(float)));
}
void freeMemory(float* pointer)
{
    free(pointer);
    printf("[INFO]Wyczyszczono pamiec.\n");
}
int* getMemoryInt(int n)
{
    return(malloc(n * sizeof(int)));
}
void freeMemoryInt(int* pointer)
{
    free(pointer);
    printf("[INFO]Wyczyszczono pamiec.\n");
}