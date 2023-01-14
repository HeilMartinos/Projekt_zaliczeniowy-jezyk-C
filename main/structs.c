#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../headers/main.h"
struct City* scanCity() {
    struct City* city = malloc(sizeof(struct City));
    printf("\n[!]Podaj wartosci kodu pocztowego (5 liczb calkowitych, po jednej w kazdym wierszu):\n");
    for (int i = 0; i < 5; i++) {
        printf("%d: ", i+1);
        scanf("%d", &city->address[i]);
    }
    printf("[!]Podaj liczbe mieszkancow:\n");
    scanf("%d", &city->citizens);
    printf("[!]Podaj nazwe miasta (max. 50 znakow):\n");
    char name[50];
    if(strlen(name)<=50){
        scanf("%s", name);
        city->name = malloc(strlen(name) + 1);
        strcpy(city->name, name);
        return city;
    }
    else{
        printf("\n[ERROR]Zbyt dluga nazwa.\n");
    }
}
void freeCity(struct City* f1)
{
    free(f1->name);
    printf("\n[INFO]Wyczyszczono nazwe miasta.\n");
    free(f1);
    printf("[INFO]Wyczyszczono miasto z pamieci.\n");
}
void printCity(struct City* f1) {
    printf("\nKod pocztowy: ");
    for (int i = 0; i < 4; i++) {
        printf("%d-", f1->address[i]);
    }
    printf("%d", f1->address[4]);
    printf("\nMieszkancy: %d\nNazwa: %s\n", f1->citizens, f1->name);
}
void printCities(struct City** f1, int len)
{
    for (int i = 0; i < len; i++)
    {
        printCity(f1[i]);
    }
}
