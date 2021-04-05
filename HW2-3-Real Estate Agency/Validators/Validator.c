#include "Validator.h"
#include <stdio.h>
#include <string.h>

int validator_estate(char type[], char address[], int surface, int price){
    int errors = 0;
    if((strcmp(type, "house") != 0) && (strcmp(type, "penthouse") != 0) && (strcmp(type, "apartment") != 0)) {
        printf("\nWrong type of estate! Estate type can be just: house, penthouse or apartment\n");
        errors ++ ;
    }
    if(strcmp(address, "") == 0){
        printf("\nPlease introduce an address! Address can not be empty!\n");
        errors ++;
    }
    if(surface <= 0){
        printf("\nPlease enter a valid surface! The surface must be a positive integer!\n");
        errors ++;
    }
    if (price <= 0){
        printf("\nPlease enter a valid price! The price must be a positive integer!\n");
        errors ++;
    }

    if (errors==0)
        return 1;       // no errors
    else
        return 0;       // there is at least one error
}


void error_duplicate_address() {
    printf("\nThere is already an estate with this address!\n");
}

void error_no_estate() {
    printf("\nThere isn't any estate with this address!\n");
}