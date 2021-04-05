#include "Console.h"
#include"..\Service\UndoRedo.h"
#include <stdio.h>
#include <stdlib.h>

Console *createConsole(int capacity){
    Console *c = (Console*)malloc(sizeof(Console));
    c->service = createService(capacity);
    return c;
}

void ui_add_estate(Console *c)
{
    char type[50];
    char address[50];
    int surface;
    int price;

    printf(" Enter the type: ");
    getchar();
    input(type, 50);

    printf (" Enter the address (Street,number): ");
    input(address, 50);

    printf(" Enter the surface: ");
    scanf("%d", &surface);

    printf(" Enter the price: ");
    scanf("%d", &price);

    add_estate(type, address, surface, price, c->service);
}

void ui_delete_estate(Console *c)
{
    char address[50];
    printf("Enter th address of the estate you want to delete: ");
    getchar();
    input(address, 50);
    delete_estate(address, c->service);

}

void ui_update_estate(Console *c)
{
    char address[50], type[50];
    int surface, price;
    //int  option;
    printf("\nEnter the address of the estate you want to update:");
    getchar();
    input(address, 50);

    printf("\nEnter the new type: ");
    input(type, 50);

    printf("\nEnter the new surface: ");
    scanf("%d", &surface);

    printf("\nEnter the new price: ");
    scanf("%d", &price);
    update_estate(address, type, surface, price, c->service);

}
void ui_display_elements(Service *s) {
    char output[100];
    if(s->repo->array->length == 0)
        printf("There is no such estate!\n");
    else{
        for (int i = 0; i < s->repo->array->length; i++) {
            toString(s->repo->array->elements[i], output);
            printf("\n %s", output);
        }
    }
}
void ui_display_by_string(Console *c){
    Service *s;
    char string[50];

    printf(" enter the string from the address: ");
    getchar();
    input(string, 50);

    s = filter_address(string, c->service);
    printf("All estates:\n");
    ui_display_elements(s);
    free(s->repo->array->elements);
    free(s->repo->array);
    free(s->repo);
    free(s);
}

void ui_display_by_surface(Console *c){
    Service *s;
    int surface;
    printf(" enter the surface: ");
    scanf("%d", &surface);
    s = filter_surface(surface, c->service);
    printf("All estates:\n");
    ui_display_elements(s);
    free(s->repo->array->elements);
    free(s->repo->array);
    free(s->repo);
    free(s);


}

void ui_display_by_price(Console *c){
    Service *s;
    int surface;
    printf(" enter the price: ");
    scanf("%d", &surface);
    s = filter_price(surface, c->service);
    printf("All estates:\n");
    ui_display_elements(s);
    free(s->repo->array->elements);
    free(s->repo->array);
    free(s->repo);
    free(s);

}

void ui_display_by_type(Console *c){
    Service *s;
    int type, comparison, surface;
    char output[100];
    printf("At what type of estates do you want to look at?\n"
                    " 1 - house\n"
                    " 2 - penthouse\n"
                    " 3 - apartment\n" );
    printf("Enter your choice:");
    scanf("%d", &type);
    printf("Enter the surface you want to compare: ");
    scanf("%d", &surface);
    printf("\n 1 - greater(ascending)"
           " 2- lesser(descending)\n");
    printf("Enter your choice: ");
    scanf("%d", &comparison);
    s = filter_type(type, surface, comparison, c->service);
    ui_display_elements(s);
    free(s->repo->array->elements);
    free(s->repo->array);
    free(s->repo);
    free(s);

}

void run_menu(Console *c)
{   List *undo = createList(100);
    List *redo = createList(100);
    int last_move = 1; // 1 for operation ( add/delete/upgrade)
                       // 2 for undo
                       // 3 for redo ( only if last operation was undo)

    printf("Your options are:\n"
           "    1 -> ADD an estate\n"
           "    2 -> DELETE an estate\n"
           "    3 -> UPDATE an estate\n"
           "    4 -> DISPLAY all estates whose address contains a given string\n"
           "    5 -> DISPLAY all estates with given surface (in an ascending order by surface)\n"
           "    6 -> DISPLAY all estates having the price lesser than a given value (in an descending order by surface)\n"
           "    7 -> DISPLAY all estates of a given type, having the surface greater than a user provided value.\n"
           "    8 -> UNDO\n"
           "    9 -> REDO\n"
           "    0 -> exit\n");

    int option = 0;
    add_estate("house", "Baker, 23", 2000, 17000,c->service);
    add_estate("penthouse", "Baker, 33", 300, 2000, c->service);
    add_estate("apartment", "Spring, 44", 60, 6000, c->service);
    add_estate("house", "Spring, 23", 300, 1000, c->service);
    add_estate("house", "Ananana, 67", 78, 300, c->service);
    add_estate("apartment", "Alba, 89", 200, 15089, c->service);
    add_estate("penthouse", "Valea, 87", 300, 40000, c->service);
    add_estate("apartment", "Main Street, 203", 150, 85090,c->service);
    add_to_list(undo, c->service->repo->array);
    while (option != -1){
        printf("\n My options is: ");
        scanf("%d", &option);
        if (option == 0)
            break;

        else if (option == 1) {
            ui_add_estate(c);
            add_to_list(undo, c->service->repo->array);
            last_move == 1;
        }

        else if (option == 2) {
            ui_delete_estate(c);
            add_to_list(undo, c->service->repo->array);
            last_move == 1;

        }

        else if (option == 3) {
            ui_update_estate(c);
            add_to_list(undo, c->service->repo->array);
            last_move == 1;

        }
        else if (option == 4)
            ui_display_by_string(c);

        else if (option == 5)
            ui_display_by_surface(c);

        else if (option == 6)
            ui_display_by_price(c);

        else if (option ==7)
            ui_display_by_type(c);

        else if (option == 8){
            if (empty_undo(undo) == 1)
                printf("No more undo :(\n");
            else
            {   c->service->repo->array = &undo->elements[undo->length-2];
                add_to_list(redo, &undo->elements[undo->length-1]);
                undo->length --;
                last_move = 2;
                printf("Undo worked :D\n ");
            }
        }
        else if (option == 9){
            if (last_move == 2 && empty_undo(redo) == 0){
                c->service->repo->array = &redo->elements[undo->length-1];
                add_to_list(undo, c->service->repo->array);
                redo->length --;
                printf("Redo worked!:D\n");
            }
            else
            printf("No redo:( \n");
        }

        else
            printf("\nSorry, wrong option!\n");

    }
    free(redo->elements);
    free(redo);
    //destroy_list(redo);
    //destroy_list(undo);
    free(undo->elements);
    free(undo);
    //destroy(c->service->repo->array);
    free(c->service->repo->array->elements);
    free(c->service->repo->array);
    free(c->service->repo);
    free(c->service);
    free(c);

}