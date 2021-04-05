#ifndef ESTATEREPO_H
#define ESTATEREPO_H
#include "../Domain/DynamicArray.h"

/* This header is the repository header
 * It calls Domain Header and is called by Service header
 *
 * */

typedef struct{
    DynamicArray *array;
} Repository;

Repository *createRepository(int capacity);
///Description:
///Adds an estate
int add_estate_repo(char type[], char address[], int surface, int price, Repository* r );

///Description:
///Deletes an estate
int delete_estate_repo(char address[], Repository* r);

///Description:
///Updates an estate
int update_estate_type_repo(char address[], char type[], Repository* r);

///Description
///Updates an estate surface
int update_estate_surface_repo(char address[], int type, Repository* r);

///Description
///Updates an estate price
int update_estate_price_repo(char address[], int price, Repository* r);

///Description
int find_estate_by_address(char address[], Repository* r);


DynamicArray* return_arr();
#endif //ESTATEREPO_H
