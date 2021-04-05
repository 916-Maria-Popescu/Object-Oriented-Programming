//
// Created by Maria on 05.04.2021.
//
#include <vector>
#include <Gene.h>

#ifndef T1_916_MARIA_POPESCU_1_REPOSITORY_H
#define T1_916_MARIA_POPESCU_1_REPOSITORY_H

class Repo{
private:
    std::vector<Gene> elements;

public:
    int add_repo(const std::string& name, const std::string& org, std::string seq);
    int find_element(const std::string& name, std::string org);
    std::vector<Gene> all_elem();
    Repo();
    ~Repo();

};




#endif //T1_916_MARIA_POPESCU_1_REPOSITORY_H
