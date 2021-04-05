#include "EstateService.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "..\Validators\Validator.h"

Service *createService(int capacity)
{
    Service *s = (Service*)malloc(sizeof(Service));
    s->repo = createRepository(capacity);
    return s;
}

void add_estate(char type[], char address[], int surface, int price, Service *s)
{
    if (validator_estate(type, address, surface, price) == 1)
        if (add_estate_repo(type, address, surface, price, s->repo) == 0)
            error_duplicate_address();
}

void delete_estate(char address[], Service *s)
{
    if (delete_estate_repo(address, s->repo) == 0)
        error_no_estate();

}

void update_estate(char address[50], char type[50], int surface, int price, Service *s)
{
    if(validator_estate(type, address, surface, price) == 1) //correct input
    {
        if(update_estate_type_repo(address, type, s->repo) == 0)
            error_no_estate();
        else {
            update_estate_surface_repo(address, surface, s->repo);
            update_estate_price_repo(address, price, s->repo);
        }
    }
}

void bubble_sort_price(Service *s)
{
    int c, d;
    estate e;
    for (c = 0 ; c < s->repo->array->length - 1; c++)
    {
        for (d = 0 ; d < s->repo->array->length - c - 1; d++)
        {
            if (getPrice(&s->repo->array->elements[d]) > getPrice(&s->repo->array->elements[d+1]))
            {
                e = s->repo->array->elements[d];
                s->repo->array->elements[d]   = s->repo->array->elements[d+1];
                s->repo->array->elements[d+1] = e;
            }
        }
    }
}

void bubble_sort_surface(Service *s, int comparison)
{
    int c, d;
    estate e;
    for (c = 0 ; c < s->repo->array->length - 1; c++)
    {
        for (d = 0 ; d < s->repo->array->length - c - 1; d++)
        {
            if (comparison == 1 && getSurface(&s->repo->array->elements[d]) > getSurface(&s->repo->array->elements[d+1]))
            //ascending order
            {
                e = s->repo->array->elements[d];
                s->repo->array->elements[d]   = s->repo->array->elements[d+1];
                s->repo->array->elements[d+1] = e;
            }
            else if(comparison == 2 && getSurface(&s->repo->array->elements[d]) < getSurface(&s->repo->array->elements[d+1]))
            //descending order
            {
                e = s->repo->array->elements[d];
                s->repo->array->elements[d]   = s->repo->array->elements[d+1];
                s->repo->array->elements[d+1] = e;
            }
        }
    }
}

Service *filter_surface(int surface, Service *s){
    Service *s_aux;
    int j = 0;
    s_aux = createService(s->repo->array->length);
    for (int i = 0; i < s->repo->array->length; i++){
        if(s->repo->array->elements[i].surface == surface)
        {
            s_aux->repo->array->elements[j] = s->repo->array->elements[i];
            s_aux->repo->array->length ++;
            j++;
        }
    }
    bubble_sort_price(s_aux);
    return s_aux;


}

Service *filter_address(char string[], Service *s){
    Service *s_aux;
    int j = 0;
    s_aux = createService(s->repo->array->length);
        for (int i = 0; i < s->repo->array->length; i++){
            if(strstr(s->repo->array->elements[i].address, string) != NULL)
            {
                s_aux->repo->array->elements[j] = s->repo->array->elements[i];
                s_aux->repo->array->length ++;
                j++;
            }
        }
    bubble_sort_price(s_aux);
    return s_aux;
}

Service *filter_price(int price, Service *s){
    Service *s_aux;
    int j = 0;
    s_aux = createService(s->repo->array->length);
    for (int i = 0; i < s->repo->array->length; i++){
        if(getPrice(&s->repo->array->elements[i]) < price)
        {
            s_aux->repo->array->elements[j] = s->repo->array->elements[i];
            s_aux->repo->array->length ++;
            j++;
        }
    }
    bubble_sort_surface(s_aux, 2);
    return s_aux;

}

Service *filter_type(int type, int surface, int comparison, Service *s){
    // 1 - house                        1 - greater(ascending)
    // 2 - penthouse                    2 - lesser(descending)
    // 3 - apartment

    Service *s_aux;
    s_aux = createService(s->repo->array->length);
    estate e;
    int j = 0;
    for (int i = 0; i<s->repo->array->length; i++)
        {
            e = s->repo->array->elements[i];
            // house
            if(type == 1 && strcmp(e.type, "house") == 0){
                if (comparison == 1 && e.surface > surface){
                    s_aux->repo->array->elements[j] = e;
                    s_aux->repo->array->length ++;
                    j ++;
                }

                else if (comparison == 2 && e.surface < surface){
                    s_aux->repo->array->elements[j] = e;
                    s_aux->repo->array->length ++;
                    j ++;
                }
            }
            // penthouse
            else if (type == 2 && strcmp(e.type, "penthouse") == 0){
                if (comparison == 1 && e.surface > surface){
                    s_aux->repo->array->elements[j] = e;
                    s_aux->repo->array->length ++;
                    j ++;
                }
                else if (comparison == 2 && e.surface < surface){
                    s_aux->repo->array->elements[j] = e;
                    s_aux->repo->array->length ++;
                    j ++;
                }
            }
            // apartment
            else if (type == 3 && strcmp(e.type, "apartment") == 0){
                if (comparison == 1 && e.surface > surface){
                    s_aux->repo->array->elements[j] = e;
                    s_aux->repo->array->length ++;
                    j ++;
                }
                else if (comparison == 2 && e.surface < surface){
                    s_aux->repo->array->elements[j] = e;
                    s_aux->repo->array->length ++;
                    j ++;
                }
            }


        }
    bubble_sort_surface(s_aux, comparison);
    return s_aux;

}



/// fix fegts, it gets rid of the empty space
void input(char *string,int length)
{
    int x;

    fgets(string,length,stdin);
    for(x=0;x<=length;x++)
    {
        if( string[x] == '\n')
        {
            string[x] = '\0';
            break;
        }
    }
}