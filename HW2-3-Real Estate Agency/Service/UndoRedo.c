#include "UndoRedo.h"
#include <stdlib.h>

List *createList(int capacity)
{
    List* undo_array = (List*)malloc(sizeof(List));
    if (undo_array == NULL)
        return NULL;

    undo_array->capacity = capacity;
    undo_array->length = 0;
    undo_array->elements = (DynamicArray *)malloc(capacity * sizeof(DynamicArray));
    if (undo_array->elements == NULL)
        return NULL;

    return undo_array;
}

void destroy_list(List* undo)
{
    if (undo == NULL)
        return;
    free(undo->elements);
    undo->elements = NULL;

    free(undo);
}

void resize_undo(List* undo)
{
    int capacity = undo->capacity *2;
    undo->elements = (da*)realloc(undo->elements, capacity * sizeof(da));

}

int empty_undo(List* undo){
    if (undo->length == 0)
        return 1;
    else
        return 0;
}

int do_undo(List* undo, DynamicArray *a){
    if (empty_undo(undo) == 0){
        a = &undo->elements[undo->length - 1];
        return 1;
    }
    return 0;
}

void add_to_list(List* list, DynamicArray *da)
{
    if (list == NULL)
        return;
    if(list->elements == NULL)
        return;
    if (list->length == list->capacity)
        resize_undo(list);
    list->elements[list->length] = *da;
    list->length ++;
}