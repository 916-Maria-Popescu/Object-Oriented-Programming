#include "EstateRepo.h"
#include <string.h>
#include <stdlib.h>

Repository *createRepository(int capacity) {
    Repository *r =(Repository*)malloc(sizeof(Repository));
    r->array = createDynamicArray(capacity);
    return r;
}

int find_estate_by_address(char address[], Repository* r){
    //checks if there is an estate with the given address in the array
    //if so, it returns the address, otherwise it returns -1
    for (int i=0; i< r->array->length; i++){
        if (strcmp(r->array->elements[i].address, address) == 0) {
            return i;}
    }
    return -1;
}

int add_estate_repo(char type[], char address[], int surface, int price, Repository* r )
    //check if there is already an estate with that address
    //if so, it print an exception
    //otherwise, it creates an Estate that will be added in the array
{   Estate e;
    if (find_estate_by_address(address, r) == -1) {
        e = createEstate(type, address, surface, price);
        add(r->array, e);
        return 1; // no error
    }
    else
        return 0; // duplicate address

}

int delete_estate_repo(char address[], Repository* r)
{
    if (find_estate_by_address(address, r) == -1)
        return 0; // error: no estate with this address
    else{
        r->array->elements[find_estate_by_address(address, r)] = r->array->elements[r->array->length - 1];
        r->array->length --;
        return  1; // no error
    }
}

int update_estate_type_repo(char address[], char type[], Repository *r){
    int index = find_estate_by_address(address, r);
    if (index != -1){
        setType(&r->array->elements[index], type);
        return 1; // okay
    }
    else
        return 0; // no estate with this address

    //strcpy((r->array->elements[index]).type , type);
}

int update_estate_surface_repo(char address[], int surface, Repository *r){
    int index = find_estate_by_address(address, r);
    if (index != -1){
        r->array->elements[index].surface = surface;
        return 1; // ok, elem updated
    }
    else
        return 0; // no estate with this address
}

int update_estate_price_repo(char address[], int price, Repository *r){
    int index = find_estate_by_address(address, r);
    if (index != -1){
        r->array->elements[index].price = price;
        return 1; // okay, elem updated
    }
    else
        return 0; // there is no estate with this address
}
