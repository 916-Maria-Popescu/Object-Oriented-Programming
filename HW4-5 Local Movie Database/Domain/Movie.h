#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie{
    private:
        int year;
        int likes;
        int id;
        std::string title;
        std::string genre;
        std::string link;

    public:
        ///Description:
        ///constructor of MOVIE
        Movie (int id, std::string title, std::string link, std::string genre, int year, int likes );

        ///Description:
        ///destructor
        ~Movie();

        ///Description:
        /// Creates a string formed with all the attributes of an object movie
        /// returns a string
        std::string toString() const;

        std::string toStringWithoutLink() const;

        ///Description:
        /// Getters and setters for all the attributes of an object movie
        ///
        int getYear() const { return this->year; }
        int getLikes() const { return this->likes; }
        int getId() const { return this->id;}
        std::string getTitle() const {return this->title;}
        std::string getLink() const {return this->link;}
        std::string getGenre() const {return this->genre;}
        ///
        void setYear(int year);
        void setLikes(int likes);
        void setGenre(std::string genre);
        void setTitle(std::string title);
        void setLink(std::string link);

















};






#endif //MOVIE_H
