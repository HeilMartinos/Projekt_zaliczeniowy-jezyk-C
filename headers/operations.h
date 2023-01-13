#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED
int randNumber(int min, int max); //Zwraca losową liczbę całkowitą z zakresu (min, max).
float median(int* array, int len); //Zwraca medianę z "len"-elementowej tablicy "array".
void printArray(int* array, int len); //Wypisuje "len"-elementową tablicę "array".
int countTheSame(float* pointer, float value, int len); //Zwraca ilość występowania w "len"-elementowej tablicy "array" wartości "value".
#endif