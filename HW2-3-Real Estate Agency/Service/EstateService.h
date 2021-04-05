#ifndef ESTATESERVICE_H
#define ESTATESERVICE_H
#include "..\Repository\EstateRepo.h"

/* This header is the service header
 * It calls Repository Header and is called by Console header
 *
 * */

typedef struct {
    Repository *repo;
} Service;

///Description
///It creates and returns(the pointer to) a datatype 'Service'
///capacity is an integer representing the initial capacity of the array, it is given in main and passed through Console
Service *createService(int capacity);

///Description:
///Adds an estate
/// -> It calls the function responsible with adding an estate from repository, the data type 'Estate' it's created just
///   in repository
/// -> returns -2 if there is already an estate with such address
void add_estate(char type[], char address[], int surface, int price, Service *s);

///Description:
///Deletes an estate
/// -> It calls the function responsible with deleting an estate from repository
/// -> returns -2 if there isn't any estate with such address
void delete_estate(char address[], Service *s);

///Description:
///Updates an estate
/// -> returns -2 if there isn't any estate with such address
void update_estate(char address[], char type[], int surface, int price, Service *s);

///Description:
///Returns a pointer to an dynamic array that contains all estates whose address contains a given string
///(if the string is empty, all estates will be considered)
/// -> sorted ascending by their price
Service *filter_address(char string[], Service *s);

///Description:
///Returns a pointer to an dynamic array that contains all estates with the surface equal to a given integer
/// -> sorted ascending by their price
Service *filter_surface(int surface, Service *s);

///Description:
///Based of the type and comparison given by the user, it will return a pointer to an array that contains:
///     -> for type = 1 and comparison = 1 : All the estates of type "house" with the surface greater than
///                                          the given surface, sorted in an ascending order(by surface)
///
///     -> for type = 1 and comparison = 2 : All the estates of type "house" with the surface lesser than
///                                          the given surface, sorted in an descending order(by surface)
///
///     -> for type = 2 and comparison = 1 : All the estates of type "penthouse" with the surface greater than
///                                          the given surface, sorted in an ascending order(by surface)
///
///     -> for type = 2 and comparison = 2 : All the estates of type "penthouse" with the surface lesser than
///                                          the given surface, sorted in an descending order(by surface)
///
///     -> for type = 3 and comparison = 1 : All the estates of type "apartment" with the surface greater than
///                                          the given surface, sorted in an ascending order(by surface)
///
///     -> for type = 3 and comparison = 2 : All the estates of type "apartment" with the surface lesser than
///                                          the given surface, sorted in an descending order(by surface)
///
Service *filter_type(int type, int surface, int comparison, Service *s);

///Description:
///Returns a pointer to an dynamic array that contains all estates with the price lesser then a given integer
/// -> sorted ascending by their surface
Service *filter_price(int price, Service *s);

///Description
///fix fgets
/// \param string
/// \param len
void input(char* string, int len);
#endif //ESTATESERVICE_H
