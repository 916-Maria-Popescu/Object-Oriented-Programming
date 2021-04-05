#include "ServiceMovies.h"
#include <string>
#include "..\Domain\DynamicArray.h"

Service::Service() = default;

void Service::add_service(int id, std::string title, std::string link, std::string genre, int year, int likes) {
    int x;
    x = this->repository.add_repository(id, std::move(title), std::move(link), std::move(genre), year, likes);
    if (x == 0){
        validator.duplicate_id_error();
    }
}

void Service::delete_service(int id) {
    int x;
    x = this->repository.delete_repository(id);
    if (x == 0){
        validator.no_element();
    }
}

void Service::update_service(int id, const std::string& new_value, int option) {
    // Option - - - Attribute
    //    1   - - -   title
    //    2   - - -   likes
    //    3   - - -   year
    //    4   - - -   link
    //    5   - - -   genre
    if (option == 1){
        if (repository.update_title_repository(id, new_value) == 0)
            validator.no_element();
    }
    else if (option == 2){
        if (repository.update_likes_repository(id, stoi(new_value)) == 0)
            validator.no_element();
    }
    else if (option == 3){
        if (repository.update_year_repository(id, stoi(new_value)) == 0)
            validator.no_element();
    }
    else if (option == 4){
        if (repository.update_link_repository(id, new_value) == 0)
            validator.no_element();
    }
    else if (option == 5){
        if (repository.update_genre_repository(id, new_value) == 0)
            validator.no_element();
    }
}

DynamicArray<Movie> *Service::all_movies_by_genre_service(const std::string& genre) {
   static DynamicArray<Movie> result = DynamicArray<Movie>(10);
   for(int i = 0; i<result.size(); i++)
        result.erase(i);
    for (int i =0; i<repository.all_elements()->size(); i++){
        if(repository.all_elements()->operator[](i).getGenre() == genre)
            result.push(repository.all_elements()->operator[](i));
    }
    return &result;
}

void Service::add_watch_list_service(int id) {
    int x = repository.add_watch_list_repository(id);
    if (x == 0)
        validator.duplicate_id_watch_list();
}

void Service::delete_watch_list_service(int id, int yes_no) {
    int x = repository.delete_watch_list_repository(id);
    if (x == 0)
        validator.no_elem_watch_list();
    else if (yes_no == 1)
        repository.like_watch_list_repository(id);
}




