//
// Created by Maria on 05.04.2021.
//

#include "Gene.h"

#include <utility>

std::string Gene::getName() {
    return this->name;

}

std::string Gene::getOrganism() {
    return this->organism;

}

std::string Gene::getSeq() {
    return this->seq;

}

void Gene::setName( std::string new_val) {
    this->name = std::move(new_val);
}

void Gene::setOrganism(std::string new_val) {
    this->organism = std::move(new_val);
}

void Gene::setSeq(std::string new_val) {
    this->seq = std::move(new_val);
}

std::string Gene::toString() {
    std::string result;
    result = "Gene: " + this->getName() + ", " + this->getOrganism() + ", " + this->getSeq() + "\n";
    return result;
}

Gene::Gene(std::string name, std::string org, std::string s) {
    this->name = std::move(name);
    this->organism = std::move(org);
    this->seq = std::move(s);

}

Gene::~Gene() = default;
