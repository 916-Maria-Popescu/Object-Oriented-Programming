#include "Estate.h"
#include <string.h>
#include <stdio.h>

Estate createEstate(char type[], char address[], int surface, int price){
    Estate e;
    strcpy(e.type, type);
    strcpy(e.address, address);
    e.surface = surface;
    e.price = price;

    return e;
}

char* getType(Estate* e)
{
    return e->type;
}

char* getAddress(Estate* e)
{
    return e->address;
}

int getSurface(Estate* e)
{
    return e->surface;
}

int getPrice(Estate* e)
{
    return e->price;
}

void setPrice(Estate* e, int new_price)
{
    e->price = new_price;
}

void setSurface(Estate* e, int surface)
{
    e->surface = surface;
}

void setType(Estate* e, char new_type[10])
{
    strcpy(e->type, new_type);
}

void toString(Estate e, char str[])
{
    sprintf(str, "Estate type: %s\n"
                "        address: %s\n"
                "        surface: %d\n"
                "        price: %d\n", e.type,e.address, e.surface, e.price);
}