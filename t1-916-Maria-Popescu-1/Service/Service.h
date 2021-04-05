//
// Created by Maria on 05.04.2021.
//

#ifndef T1_916_MARIA_POPESCU_1_SERVICE_H
#define T1_916_MARIA_POPESCU_1_SERVICE_H

#include <Repository.h>

class Service{
public:
    Repo repository;
    int add_service(const std::string& name, const std::string& org, const std::string& seq);
    std::vector <Gene> show_by_seq(const std::string& seq);
    std::vector<Gene> show_all();
    Service();
    ~Service();

};
#endif //T1_916_MARIA_POPESCU_1_SERVICE_H
