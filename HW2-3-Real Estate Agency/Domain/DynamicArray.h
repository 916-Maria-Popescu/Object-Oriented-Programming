#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "Estate.h"
typedef Estate estate;
typedef struct
{
    estate* elements;
    int length;
    int capacity;
} DynamicArray;


///Description
/// Creates an dynamic array with the initial capacity equal the an integer capacity
DynamicArray* createDynamicArray(int capacity);

///Description
///Destroys the dynamic array -> no memory lacks
void destroy(DynamicArray* arr);

///Description
///Adds an new element "estate" to the elements of the array
/// length of the array increased by 1
/// if the length > capacity, the array is resized
void add(DynamicArray*arr, estate);




#endif //DYNAMICARRAY_H
