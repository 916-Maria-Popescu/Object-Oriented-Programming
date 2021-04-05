#include "Movie.h"

Movie::Movie(int id, std::string title, std::string link, std::string genre, int year, int likes) {
    this->id = id;
    this->title = std::move(title);
    this->link = std::move(link);
    this->genre = std::move(genre);
    this->year = year;
    this->likes = likes;
}

Movie::~Movie() = default;;

std::string Movie::toString() const{
    std::string string;
    string = "*************************************************************** \nMovie id: " + std::to_string(this->getId())+ " \n" +"      title: " + this->getTitle() + " \n" +
            "      genre: " + this->getGenre()+ " \n" + "      year: " + std::to_string(this->getYear())+ " \n"+
            "      likes: " + std::to_string(this->getLikes())+ " \n" + "      link: " + this->getLink() + "\n"+
            "***************************************************************";

    return string;
}

void Movie::setYear(int new_year) {
    this->year = new_year;
}

void Movie::setLikes(int new_likes) {
    this->likes = new_likes;
}

void Movie::setGenre(std::string new_genre) {
    this->genre = std::move(new_genre);
}

void Movie::setTitle(std::string new_title) {
    this->title = std::move(new_title);
}

void Movie::setLink(std::string new_link) {
    this->link = std::move(new_link);
}

std::string Movie::toStringWithoutLink() const {
    std::string string;
    string = "*************************************************************** \nMovie id: " + std::to_string(this->getId())+ " \n" +"      title: " + this->getTitle() + " \n" +
             "      genre: " + this->getGenre()+ " \n" + "      year: " + std::to_string(this->getYear())+ " \n"+
             "      likes: " + std::to_string(this->getLikes())+ " \n" +
             "***************************************************************";

    return string;
}

