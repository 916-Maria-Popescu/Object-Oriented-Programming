#ifndef REPOSITORYMOVIES_H
#define REPOSITORYMOVIES_H
#include <vector>
#include "..\Domain\DynamicArray.h"
#include "../Domain/Movie.h"

class Repository{
    DynamicArray<Movie> elements = DynamicArray<Movie>(20);
    DynamicArray<Movie> watch_list = DynamicArray<Movie>(20);
public:

    ///Description
    DynamicArray<Movie>* all_elements();

    ///Description
    ///Constructor of Repository class
    Repository ();

    ///Description
    ///Destructor of Repository class
    ~Repository();

    ///Description
    ///Adds an object movie to the vector elements
    ///First it creates the element
    /// returns 0 -> there is already an element with this id (so the element is not added)
    /// returns 1 -> the id is unique, the new element is added
    int add_repository(int id, std::string title, std::string link, std::string genre, int year, int likes);

    ///Description
    ///Function that returns the index of a movie by its unique id ( for the general list of movies)
    /// returns i (index) -> if there is such movie ( in the general list)
    /// returns -1 -> if there isn't any movie with this id ( in the general list)
    int find_movie_by_id(int id);

    ///Description
    ///It deletes an object movie from the vector elements
    /// returns 0 -> there isn't any element with this id ( so nothing was deleted)
    /// returns 1 -> there is an element with this id that was deleted
    int delete_repository(int id);


    ///Description
    ///Methods for updating an attribute of the object movie
    /// returns 0 -> there isn't any element with this id ( so nothing was deleted)
    /// returns 1 -> there is an element with this id that was deleted
    int update_title_repository(int id, const std::string& new_title);
    int update_genre_repository(int id, const std::string& new_genre);
    int update_link_repository(int id, const std::string& new_link);
    int update_year_repository(int id, int year);
    int update_likes_repository(int id, int likes);

    ///Description
    ///Adds an object movie to the vector elements
    ///First it creates the element
    /// returns 0 -> there is already an element with this id (so the element is not added)
    int add_watch_list_repository(int id);

    ///Description
    int delete_watch_list_repository(int id);

    ///Description
    ///Function that returns the index of a movie by its unique id (for the watch list)
    /// returns i (index) -> if there is such movie
    /// returns -1 -> if there isn't any movie with this id
    int find_by_id_watch_list(int id);

    DynamicArray<Movie> *get_watch_list();

    void like_watch_list_repository(int id);

};


#endif //REPOSITORYMOVIES_H
