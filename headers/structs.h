#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDEDs
struct City *scanCity();
void freeCity(struct City *f1); //Zwalnia pamięć z podanego wskaźnika do struktury City.
void printCity(struct City *f1); //Wypisuje wszystkie pola podanej struktury City.
void printCities(struct City** f1, int len); //Wypisuje "len"-elementową tablicę struktur City "f1".
#endif