//
// Created by Maria on 05.04.2021.
//

#include "Service.h"

Service::Service() = default;

Service::~Service() = default;

int Service::add_service(const std::string& name, const std::string& org, const std::string& seq) {
    //Check if there is scuh an elem and adds it
    // return 0 if there is
    // return 1 if there is not => the elem will be added
    // int a = 0/1 ( retunred by repo)
    int a = this->repository.add_repo(name, org, seq);
    return a;
}

std::vector<Gene> Service::show_by_seq(const std::string& seq) {
    std::vector<Gene> res;
    for(int i = 0; i< this->repository.all_elem().size(); i++) {
        if (this->repository.all_elem()[i].getSeq().find(seq) != std::string::npos) {
            res.push_back(this->repository.all_elem()[i]);
        }
    }
    int i, j;
    int n = res.size();
    for (i = 0; i < n-1; i++){
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (res[j].getSeq().length() > res[j + 1].getSeq().length())
                std::swap(res[j], res[j + 1]);
        }
    }

    return res;
}

std::vector<Gene> Service::show_all() {
    int i, j;
    std::vector<Gene> arr = this->repository.all_elem();
    int n = arr.size();
    for (i = 0; i < n-1; i++){
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].getSeq().length() > arr[j + 1].getSeq().length())
                std::swap(arr[j], arr[j + 1]);
        }
    }
    return arr;
}

