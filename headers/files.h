#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED
struct City;
void saveCities(struct City **f1, int len, char *filename); // Zapis do pliku o nazwie "filename" "len"-elementowej tablicy struktur "f1".
void readCities(char *filename, int n);                     // Odczyt z pliku o nazwie "filename" "n" elementów i zapis ich do tablicy struktur.
#endif