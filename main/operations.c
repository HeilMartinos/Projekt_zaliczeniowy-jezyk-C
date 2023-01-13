#include<stdlib.h>
#include<stdio.h>
#include "../headers/operations.h"
int randNumber(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}
float median(int* array, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int pom = array[j];
                array[j] = array[j + 1];
                array[j + 1] = pom;
            }
        }
    }
    float median;
    if (len % 2 != 0)
    {
        median = array[(len / 2)];
    }
    else
    {
        median = (array[(len / 2) - 1] + array[len / 2]) / (float)2;
    }
    return median;
}
void printArray(int* array, int len)
{
    printf("Tablica %d - elementowa: \n", len);
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}
int countTheSame(float* pointer, float value, int len)
{
    int number = 0;
    for (int i = 0; i < len; i++)
    {
        if (pointer[i] == value)
        {
            number++;
        }
    }
    return number;
}