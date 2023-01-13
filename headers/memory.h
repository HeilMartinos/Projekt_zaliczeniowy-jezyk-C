#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED
float *getMemory(int n); //Rezerwacja pamięci do tablicy float, przyjmuje "n" - liczbę elementów, zwraca wskaźnik do tablicy n-elementowej.
void freeMemory(float *pointer); //Zwalnianie pamięci z podanego wskaźnika typu float ("pointer")
int *getMemoryInt(int n); //Rezerwacja pamięci do tablicy int, przyjmuje "n" - liczbę elementów, zwraca wskaźnik do tablicy n-elementowej.
void freeMemoryInt(int *pointer); //Zwalnianie pamięci z podanego wskaźnika typu int ("pointer")
#endif