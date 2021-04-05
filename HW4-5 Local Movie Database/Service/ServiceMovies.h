#ifndef SERVICEMOVIES_H
#define SERVICEMOVIES_H

#include "../Validators/Validator.h"
#include "../Repository/RepositoryMovies.h"
#include "../Domain/Movie.h"

class Service{
private:
    Validator validator;
public:
    Repository repository;
    Service();

    void add_service(int id, std::string title, std::string link, std::string genre, int year, int likes);
    void delete_service(int id);
    void update_service(int id, const std::string& new_value, int option);
    DynamicArray<Movie> *all_movies_by_genre_service(const std::string& genre);

    void add_watch_list_service(int id);
    void delete_watch_list_service(int id, int yes_no);
};


#endif //SERVICEMOVIES_H
