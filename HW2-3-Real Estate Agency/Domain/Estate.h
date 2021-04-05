#ifndef ESTATE_H
#define ESTATE_H

typedef struct
{
   char type[10];
   char address[50];
   int price;
   int surface;
} Estate;

Estate createEstate(char type[], char address[], int surface, int price);
char* getType(Estate* e);
char* getAddress(Estate* e);
int getPrice(Estate* e);
int getSurface(Estate* e);
void setSurface(Estate* e, int new_surface);
void setPrice(Estate* e, int new_price);
void setType(Estate* e, char new_type[10]);
void toString(Estate e, char str[]);


#endif //ESTATE_H
