//
// Created by Maria on 05.04.2021.
//

#include <iostream>
#include "Console.h"

Console_ui::Console_ui() = default;

Console_ui::~Console_ui() = default;

void Console_ui::run_menu() {
    int opt = -1;
    this->service.add_service("E_Coli_K12" , "yqgE" , "ATGACATCATCATTG");
    this->service.add_service("M_tuberculosis"," ppiA" ," TCTTCATCATCATCGG");
    this->service.add_service("Mouse",  "Col2a1" , "TTAAAGCATGGCTCTGTG");
    std::cout<<"What do you want to do?\n"
               "    1-> add \n"
               "    2->show all genes\n"
               "    3->show by given seq\n"
               "    0->exit\n";


    while(opt!=0){
        std::cout<<"enter your option: ";
        std::cin>>opt;
        if (opt == 1)
            ui_add();
        else if(opt == 2)
            ui_show_all();
        else if(opt == 3)
            ui_show_by_seq();
        else if (opt == 0)
            break;
        else
            std::cout<<"wrong option\n";
    }
}


void Console_ui::ui_add() {
    std::string name, seq, organism;
    std::cout<<"Enter the name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout<<"Enter the organism: ";
    std::getline(std::cin >> std::ws, organism);
    std::cout<<"Enter the seq: ";
    std::getline(std::cin >> std::ws, seq);

    int a = this->service.add_service(name, organism, seq);
    if (a == 0)
        std::cout<<"duplicate elem"<<std::endl;
    else
        std::cout<<"elem added :D "<<std::endl;

}

void Console_ui::ui_show_all() {
    std::cout<<"All elements:\n";
    //std::vector<Gene> res = this->service.repository.all_elem();
    std::vector<Gene> res = this->service.show_all();
    for(auto & re : res){
        std::string elem = re.toString();
        std::cout<<elem<<std::endl;
    }

}

void Console_ui::ui_show_by_seq() {
    std::string seq;
    std::cout<<"enter the seq: ";
    std::getline(std::cin >> std::ws, seq);
    std::vector<Gene> res = this->service.show_by_seq(seq);
    for(auto & re : res){
        std::string elem = re.toString();
        std::cout<<elem<<std::endl;
    }

}
