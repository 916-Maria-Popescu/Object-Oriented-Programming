//
// Created by Maria on 05.04.2021.
//

#include "Repository.h"

#include <utility>
#include <iostream>

Repo::Repo() = default;

Repo::~Repo() = default;

int Repo::add_repo(const std::string& name, const std::string& org, std::string seq) {
    if (find_element(name, org) != -1)
        return 0;
    else{
        Gene gen = Gene(name, org, std::move(seq));
        elements.push_back(gen);
        return 1;
    }
}

int Repo::find_element(const std::string& name, std::string org) {
    for(int i = 0; i<this->elements.size(); i++){
        if(elements[i].getName() == name and elements[i].getOrganism() == org)
            //there is already such elem
            return i;}
    return -1;
}

std::vector<Gene> Repo::all_elem() {
    return this->elements;
}
