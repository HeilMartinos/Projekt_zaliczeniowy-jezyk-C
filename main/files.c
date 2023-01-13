#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../headers/main.h"
#include "../headers/structs.h"
void saveCities(struct City** f1, int len, char* filename) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("\n[ERROR]Nie udalo sie otworzyc pliku.\n");
        return;
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 4; j++) {
            fprintf(file, "%d-", f1[i]->address[j]);
        }
        fprintf(file, "%d ", f1[i]->address[4]);
        fprintf(file, "%d ", f1[i]->citizens);
        fprintf(file, "%s\n", f1[i]->name);
    }
    fclose(file);
    printf("\n[INFO]Zapisano miasta do pliku %s.\n", filename);
     for (int i = 0; i < len; i++) {
        freeCity(cities[i]);
    }
}
void readCities(char *filename, int n)
{
    FILE*plik = fopen(filename, "r");
    if (plik == NULL) {
        printf("\n[ERROR]Nie udalo sie otworzyc pliku.\n");
        return;
    }
    int address[5];
    int citizens;
    char name[50];
    int ilosc=0;
    printf("\nZawartosc pliku %s: \n", filename);
    struct City *city;
    while (fscanf(plik, "%d-%d-%d-%d-%d %d %s", &address[0], &address[1], &address[2], &address[3], &address[4], &citizens, name) != EOF){
        for (int j = 0; j < 4; j++) {
            printf("%d-", address[j]);
        }
        printf("%d ", address[4]);
        printf("%d %s.\n", citizens, name);
        city=malloc(sizeof(struct City));
        for(int j=0; j<5; j++)
        {
            city->address[j]=address[j];
        }
        city->citizens=citizens;
        city->name=malloc(strlen(name)+1);
        strcpy(city->name, name);
        if(ilosc+n<50){
            cities[ilosc+n]=city;
            ilosc++;
        }
        else{
            printf("\n[INFO]Przekroczono rozmiar tablicy.\n");
            break;
        }
    }
    printf("\n[INFO]Zapisano %d elementow do tablicy. Zawartosc tablicy:\n", ilosc);
    printCities(cities, ilosc);
    freeCity(city);
    fclose(plik);
}