#include "DynamicArray.h"
#include <stdlib.h>

DynamicArray* createDynamicArray(int capacity)
{
    DynamicArray* d_arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (d_arr == NULL)
        return NULL;

    d_arr->capacity = capacity;
    d_arr->length = 0;
    d_arr->elements = (estate*)malloc(capacity * sizeof(estate));
    if (d_arr->elements == NULL)
        return NULL;

    return d_arr;
}

void destroy(DynamicArray* arr)
{
    if (arr == NULL)
        return;
    free(arr->elements);
    arr->elements = NULL;

    free(arr);
}

void resize(DynamicArray* arr)
{
    int capacity = arr->capacity *2;
    arr->elements = (estate*)realloc(arr->elements, capacity * sizeof(estate));

}

void add(DynamicArray* arr, estate e)
{
    if (arr == NULL)
        return;
    if(arr->elements == NULL)
        return;
    if (arr->length == arr->capacity)
        resize(arr);
    arr->elements[arr->length] = e;
    arr->length ++;
}