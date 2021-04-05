#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include "../Service/ServiceMovies.h"

class Console{
private:
    Service service;
    void ui_public_mode();
    void ui_display_movie_by_genre();
    void ui_display_watch_list();
    void ui_delete_from_watch_list();
    void ui_administrator_mode();
    void ui_admin_add();
    void ui_admin_delete();
    void ui_admin_update();
    static void ui_print_all(DynamicArray<Movie>* movies);
    void ui_admin_display_all();
    void add_elements();

public:
    void run_menu();
};






#endif