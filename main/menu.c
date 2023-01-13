#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../headers/main.h"
#include "../headers/operations.h"
#include "../headers/memory.h"
#include "../headers/structs.h"
#include "../headers/files.h"
void menu()
{
    int run = 1;
    int ileTab=0;
    int indeks = 173592;
        int rok = 1;
    printf("\nProgram w jezyku C wykonany przez studenta o indeksie nr %d na %d roku studiow.\n", indeks, rok);
    do
    {
        int selected;
        printf("\nMenu:\n\n1. Generator liczb pseudolosowych\n2. Kalkulator mediany\n3. Szukanie liczb\n4. Miasta\nAby zakonczyc, wprowadz 0.\n\n[!]Wybierz opcje:\n");
        do
        {
            scanf("%d", &selected);
            if (selected < 0 || selected>4)
            {
                printf("\n[ERROR]Nieprawidlowy numer. Wybierz opcje od 1 do 4!\n[!]Wybierz opcje:\n");
            }
        } while (selected < 0 || selected>4);
        printf("[INFO]Wybrales opcje: %d.\n", selected);
        switch (selected)
        {
        case 0:
            run = 0;
            break;
        case 1:
            printf("[Losowanie]\n");
            printf("[!]Podaj zakres losowania:\n");
            int min;
            int max;
            printf("Min: ");
            scanf("%d", &min);
            printf("Max: ");
            scanf("%d", &max);
            printf("\nWylosowano liczbe %d.\n", randNumber(min, max));
            break;
        case 2:
            printf("[Mediana]\n");
            int* tab;
            int liczba;
            printf("[!]Podaj rozmiar tablicy: ");
            scanf("%d", &liczba);
            tab = getMemoryInt(liczba);
            printf("[!]Podaj %d elementow tablicy: \n", liczba);
            for (int i = 0; i < liczba; i++)
            {
                printf("%d: ", i+1);
                scanf("%d", &tab[i]);
            }
            printArray(tab, liczba);
            printf("\nMediana tablicy: %f.\n", median(tab, liczba));
            freeMemoryInt(tab);
            break;
        case 3:
            printf("[Szukanie]\n");
            int size;
            float* tab2;
            printf("[!]Podaj rozmiar tablicy: ");
            scanf("%d", &size);
            tab2 = getMemory(size);
            printf("[!]Podaj %d elementow tablicy: \n", size);
            for (int i = 0; i < size; i++)
            {
                printf("%d: ", i+1);
                scanf("%f", &tab2[i]);
            }
            float value;
            printf("[!]Podaj szukana wartosc: ");
            scanf("%f", &value);
            printf("\nPodana wartosc wystepuje %d razy.\n", countTheSame(tab2, value, size));
            freeMemory(tab2);
            break;
        case 4:;
            printf("[Miasta]\n[!]Wybierz opcje:\n1: Dodaj miasta\n2: Zapisz miasta do pliku\n3: Wczytaj miasta z pliku.\n");
            int opcja;
            scanf("%d", &opcja);
            if(opcja<1 || opcja>3){
                printf("\n[ERROR]Podales zla opcje.\n");
            }
            if(opcja == 1){
                int liczMiast;
                printf("[Dodaj miasta]\n[!]Podaj liczbe miast, ktore chcesz dodac: ");
                scanf("%d", &liczMiast);
                ileTab+=liczMiast;
                for (int i=0; i < liczMiast; i++)
                {
                    cities[i] = scanCity();
                }
                printCities(cities, liczMiast);
            }
            if(opcja==2){
                char nazwa[50];
                printf("[Zapisz do pliku]\n[!]Podaj nazwe pliku: ");
                scanf("%s", nazwa);
                saveCities(cities, ileTab, nazwa);
                ileTab=0;
            }
            if(opcja==3){
                char nazwa[50];
                printf("[Wczytaj z pliku]\n[!]Podaj nazwe pliku: ");
                scanf("%s", nazwa);
                readCities(nazwa, ileTab);
            }
        }
    } while (run == 1);
    printf("\nDo widzenia.");
}