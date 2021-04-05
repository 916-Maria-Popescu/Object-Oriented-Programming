#ifndef CONSOLE_H
#define CONSOLE_H
#include "..\Service\EstateService.h"

/* The header for Console. It calls Service and it is called by the main function
 * */

typedef struct {
    Service *service;
}Console;

///Description
///It creates a data type 'Console' and it returns a pointer to 'Console'
/// capacity is an integer that represents the initial capacity of the dynamic array that will store the estates
Console* createConsole(int capacity);

///Description
///Runs the menu interface of the program
void run_menu(Console *c);
#endif //CONSOLE_H
