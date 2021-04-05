//
// Created by Maria on 05.04.2021.
//

#ifndef T1_916_MARIA_POPESCU_1_CONSOLE_H
#define T1_916_MARIA_POPESCU_1_CONSOLE_H

#include <Service.h>

class Console_ui{
private:
    Service service;
    void ui_add();
    void ui_show_all();
    void ui_show_by_seq();

public:
    void run_menu();
    Console_ui();
    ~Console_ui();
};
#endif //T1_916_MARIA_POPESCU_1_CONSOLE_H
