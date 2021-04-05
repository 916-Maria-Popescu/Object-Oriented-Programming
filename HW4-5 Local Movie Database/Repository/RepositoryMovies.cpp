#include "RepositoryMovies.h"

Repository::Repository() = default;

Repository::~Repository() = default;

int Repository::add_repository(int id, std::string title, std::string link, std::string genre, int year, int likes) {
    if (find_movie_by_id(id) == -1) {
        Movie movie = Movie(id, std::move(title), std::move(link), std::move(genre), year, likes);
        elements.push(movie);
        return 1; // everything worked, elem added
    }
    else
        return 0; // elem not added, duplicate id
}

int Repository::delete_repository(int id) {
    int x = find_movie_by_id(id);
    if (x != -1) {
        elements.erase(x);
        if (int index = find_by_id_watch_list(id) != -1)
            watch_list.erase(index);
        return 1;
    }
    else
        return 0;
}

int Repository::find_movie_by_id(int id) {
    for (int i = 0; i< elements.size(); i++){
        if (elements[i].getId() == id)
            return i; //there is an element with this id
    }
    return -1; // no elem with this id
}

int Repository::update_title_repository(int id, const std::string& new_title) {
    int x = find_movie_by_id(id);
    if (x != -1) {
        elements[x].setTitle(new_title);
        int index = find_by_id_watch_list(id);
        if (index != -1)
            watch_list[index].setTitle(new_title);
        return 1;
    }
    return 0;
}

int Repository::update_genre_repository(int id, const std::string& new_genre) {
    int x = find_movie_by_id(id);
    if (x != -1) {
        elements[x].setGenre(new_genre);
        int index = find_by_id_watch_list(id);
        if (index != -1)
            watch_list[index].setGenre(new_genre);
        return 1;
    }
    return 0;
}

int Repository::update_link_repository(int id, const std::string& new_link) {
    int x = find_movie_by_id(id);
    if (x != -1) {
        elements[x].setLink(new_link);
        int index = find_by_id_watch_list(id);
        if (index != -1)
            watch_list[index].setLink(new_link);
        return 1;
    }
    return 0;
}

int Repository::update_year_repository(int id, int year) {
    int x = find_movie_by_id(id);
    if (x != -1) {
        elements[x].setYear(year);
        int index = find_by_id_watch_list(id);
        if (index != -1)
            watch_list[index].setYear(year);
        return 1;
    }
    return 0;
}

int Repository::update_likes_repository(int id, int likes) {
    int x = find_movie_by_id(id);
    if (x != -1) {
        elements[x].setLikes(likes);
        int index = find_by_id_watch_list(id);
        if (index != -1)
            watch_list[index].setLikes(likes);
        return 1;
    }
    return 0;
}

DynamicArray<Movie> *Repository::all_elements() {
    return &elements;
}

int Repository::add_watch_list_repository(int id) {
    int x = find_by_id_watch_list(id);
    if (x == -1) {
        Movie movie = elements[find_movie_by_id(id)];
        watch_list.push(movie);
        return 1; // everything worked, elem added
    }
    else
        return 0; // elem not added, duplicate id

}

int Repository::delete_watch_list_repository(int id) {
    int x = find_by_id_watch_list(id);
    if (x != -1){
        watch_list.erase(x);
        return 1;//elem deleted
    }
    else
        return 0; //elem not found -> elem not deleted
}

int Repository::find_by_id_watch_list(int id) {
    for (int i = 0; i < watch_list.size(); i++){
        if (watch_list[i].getId() == id)
            return i; //there is an element with this id
    }
    return -1; // no elem with this id
}

DynamicArray<Movie> *Repository::get_watch_list() {
    return &watch_list;
}

void Repository::like_watch_list_repository(int id) {
    int index = find_movie_by_id(id);
    int likes = this->elements[index].getLikes() + 1;
    elements[index].setLikes(likes);

}







