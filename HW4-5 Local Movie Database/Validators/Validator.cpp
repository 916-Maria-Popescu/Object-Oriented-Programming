#include <iostream>
#include "Validator.h"

void Validator::duplicate_id_error() {
    std::cout<<"Sorry, there is already a movie with this id!"<<std::endl;
}

void Validator::no_element() {
    std::cout<<"There isn't any movie with this id!"<<std::endl;
}

void Validator::no_elem_watch_list() {
    std::cout<<"This movie is not in the watch list"<<std::endl;
}

void Validator::duplicate_id_watch_list() {
    std::cout<<"This movie is already in the watch list"<<std::endl;
}
