#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
struct City 
{
    int address[5];
    int citizens;
    char *name;
};
extern struct City *cities[50];
#endif