#ifndef A23_916_MARIA_POPESCU_UNDOREDO_H
#define A23_916_MARIA_POPESCU_UNDOREDO_H
#include "../Domain/DynamicArray.h"

typedef DynamicArray da;
typedef struct
{
    da* elements;
    int length;
    int capacity;
} List;

List *createList(int capacity);
void destroy_list(List* undo);
void resize_list(List* undo);
void add_to_list(List* undo, DynamicArray *da);
int do_undo(List* undo, DynamicArray *a);
int empty_undo(List* undo);


#endif //A23_916_MARIA_POPESCU_UNDOREDO_H
