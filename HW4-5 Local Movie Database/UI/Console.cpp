#include "Console.h"
#include <string>
//#include <windows.h>

void Console::run_menu() {
    add_elements();
    int option = -1;
    std::cout << "Welcome"<<std::endl;
    while (option != 0){
        std::cout << "Choose a mode:\n"
                    "  1 -> administrator mode\n"
                    "  2 -> public mode\n"
                    "  0 -> exit\n";
        std::cout << "option: ";
        std::cin >> option;
        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong option!  Enter a NUMBER (0, 1 or 2): ";
            std::cin >> option;
        }

        if(option == 1)
            ui_administrator_mode();
        else if (option == 2)
            ui_public_mode();
        else if (option == 0)
            break;
        else
            std::cout << "Wrong option!\n"<< std::endl;
    }
}

void Console::ui_public_mode() {
    int option = -1;
    std::cout<<"Welcome to public mode!\n"
               "What do you want to do?\n"
               "   1 -> See the movies having a given genre\n"
               "   2 -> See the watch list\n"
               "   3 -> Delete a movie from watch list\n"
               "   0 -> exit public mode\n";

    while(option != 0){
        std::cout<<"option: ";
        std::cin>>option;
        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong option.  Enter a NUMBER(from 0 to 3): ";
            std::cin >> option;
        }
        if (option == 1)
            ui_display_movie_by_genre();
        else if (option == 2)
            ui_display_watch_list();
        else if (option == 3)
            ui_delete_from_watch_list();
        else if (option == 0)
            break;
    }
}

void Console::ui_display_movie_by_genre(){
    std::string genre, option;
    DynamicArray<Movie> *movies;
    std::cout<<"Enter a genre: ";
    //std::getline(std::cin >> std::ws, genre);
    getchar();
    std::getline(std::cin, genre);
    if (genre.empty())
        movies = service.repository.all_elements();

    else
        movies = service.all_movies_by_genre_service(genre);

    if (movies->size() == 0)
        std::cout<< "No movies with this id"<<std::endl;

    for(int i = 0; i<movies->size(); i++) {
        Movie movie = movies->operator[](i);
        //display the movie
        std::cout << movie.toStringWithoutLink() << std::endl;
        //
        system(std::string("start " + movie.getLink()).c_str());

        std::cout << "\nDid you watch the trailer?If so, would you like to:\n"
                     "   1 -> add the movie to my watch list\n"
                     "   2 -> go to the next movie\n"
                     "   3 -> stop listing movies\n";
        while(option != "3"){
            std::cout << "I choose to: ";
            std::cin >> option;
            if (option == "1")
                {service.add_watch_list_service(movies->operator[](i).getId());
                break;}
            else if(option == "2")
                break;
            else if (option != "3")
                std::cout <<"Wrong option!"<<std::endl;
        }
        if (option == "3")
            break;
        if(i == movies->size() - 1)
            i = -1;
      }
   }


void Console::ui_display_watch_list() {
    std::cout<<"All the movies from the watch list are: "<<std::endl;
    ui_print_all(service.repository.get_watch_list());
}

void Console::ui_delete_from_watch_list() {
    int id;
    std::cout<<"Enter the id of the movie you want to delete from the watch list: ";
    std::cin>>id;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Wrong option.  Enter a NUMBER: ";
        std::cin >> id;
    }
    std::string option;
    std::cout<<"Would you like to give this movie a like: ";
    std::cin>>option;
    if (option == "yes")
        service.delete_watch_list_service(id, 1);
    else
        service.delete_watch_list_service(id, 0);
}
void Console::ui_administrator_mode() {
    int option = -1;
    std::cout<<"Welcome to admin mode!\n"
               "What do you want to do?\n"
               "   1 -> add a movie\n"
               "   2 -> delete a movie\n"
               "   3 -> update a movie\n"
               "   4 -> display all the movies\n"
               "   0 -> exit admin mode\n";

    while(option != 0) {
        std::cout<<"option: ";
        std::cin>>option;
        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong option.  Enter a NUMBER(from 0 to 4): ";
            std::cin >> option;
        }
        if(option == 1)
            ui_admin_add();
        else if(option == 2)
            ui_admin_delete();
        else if(option == 3)
            ui_admin_update();
        else if(option == 4)
            ui_admin_display_all();
        else if(option != 0)
            std::cout<<"Wrong option!"<<std::endl;
    }
}

void Console::ui_admin_add() {
    int id;
    int likes;
    int year;
    std::string title;
    std::string link;
    std::string genre;

    std::cout<<"Id: ";
    std::cin>> id;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Wrong input for id.  Enter a NUMBER: ";
        std::cin >> id;
    }

    std::cout<<"Title: ";
    std::getline(std::cin >> std::ws, title);
    std::cout<<"Genre: ";
    std::getline(std::cin >> std::ws, genre);
    std::cout<<"Year of publication: ";
    std::cin>>year;
    while(std::cin.fail())
    {
        std::cin.clear();
        ::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Wrong input for year.  Enter a NUMBER: ";
        std::cin >> year;
    }
    std::cout<<"Number of likes: ";
    std::cin>>likes;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Wrong input for number of likes.  Enter a NUMBER: ";
        std::cin >> likes;
    }
    std::cout<<"Link: ";
    std::cin>>link;

    this->service.add_service(id, title, link, genre, year, likes);
}


void Console::ui_admin_delete() {
    int id;
    std::cout<<"Enter the id of the movie you want to delete: ";
    std::cin>>id;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Wrong input for id.  Enter a NUMBER: ";
        std::cin >> id;
    }
    this->service.delete_service(id);
}

void Console::ui_admin_update() {
    int option;
    int id;
    std::string new_value;
    std::cout<<"Enter the id of the movie you want to change: ";
    std::cin>>id;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Wrong input for id.  Enter a NUMBER: ";
        std::cin >> id;
    }
    std::cout<<"What do you want to update?\n"
               "    1 -> title\n"
               "    2 -> likes\n"
               "    3 -> year\n"
               "    4 -> link\n"
               "    5 -> genre\n";
    option = 0;
    while (option == 0) {
        std::cout << "Option: ";
        std::cin >> option;
        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong option.  Enter a NUMBER(from 1 to 5): ";
            std::cin >> id;
        }
        if (option == 1)
            std::cout << "Enter the new title: ";
        else if (option == 2)
            std::cout << "Enter the new likes: ";
        else if (option == 3)
            std::cout << "Enter the new year: ";
        else if (option == 4)
            std::cout << "Enter the new link: ";
        else if (option == 5)
            std::cout << "Enter the new genre: ";
        else{
            std::cout << "wrong option :(" << std::endl;
            option = 0;
        }
    }
    std::cin>>new_value;
    service.update_service(id, new_value, option);

}

void Console::ui_print_all(DynamicArray<Movie> *movies) {
    for (int i = 0; i< movies->size(); i++)
        std::cout<<movies->operator[](i).toString()<<std::endl;
}

void Console::ui_admin_display_all() {
    std::cout<<"All the movies:"<<std::endl;
    ui_print_all(service.repository.all_elements());
}

void Console::add_elements() {
    service.add_service(15, "Casablanca", "https://www.youtube.com/watch?v=BkL9l7qovsE", "romantic", 1942, 19822);
    service.add_service(16, "Call me by your name", "https://www.youtube.com/watch?v=Z9AYPxH5NTM", "romantic drama", 2017, 6543);
    service.add_service(17, "Corpse Bride", "https://www.youtube.com/watch?v=AGACeWVdFqo", "musical fantasy", 2005, 4390);
    service.add_service(18, "Before Sunrise", "https://www.youtube.com/watch?v=6MUcuqbGTxc", "romantic", 1995, 11440);
    service.add_service(19, "Before Sunset", "https://www.youtube.com/watch?v=oI3UuneLcyU", "romantic", 2004, 10607);
    service.add_service(20, "Before Midnight", "https://www.youtube.com/watch?v=Kv6JWoVKlGY", "romantic", 2013, 9870);
    service.add_service(21, "The imitation game", "https://www.youtube.com/watch?v=nuPZUUED5uk", "historical drama", 2014, 8820);
    service.add_service(22, "How to Lose a Guy in 10 Days", "https://www.youtube.com/watch?v=2ZMGk_Ml1fc", "comedy", 2003, 6974);
    service.add_service(23, "The mission", "https://www.youtube.com/watch?v=HU14R9hbUFc", "historical drama", 1986, 8995);
    service.add_service(27, "Breakfast at tiffany's","https://www.youtube.com/watch?v=OPQkbvo99Ug", "romantic", 1996, 89933);
    service.add_service(28, "Roman Holiday", "https://www.youtube.com/watch?v=ELb4S8P3q20", "romantic", 1956, 6000);
    service.add_service(29, "Filantropica", "https://www.youtube.com/watch?v=0vVpsJnbq3A", "comedy", 2002, 5098);
    }








