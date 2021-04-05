//
// Created by Maria on 05.04.2021.
//

#ifndef T1_916_MARIA_POPESCU_1_GENE_H
#define T1_916_MARIA_POPESCU_1_GENE_H

#include <string>

class Gene{
private:
    std::string name;
    std::string organism;
    std::string seq;

public:
    Gene(std::string name, std::string org, std::string s);
    ~Gene();
    std::string getName();
    std::string getOrganism();
    std::string getSeq();

    void setName(std::string new_val);
    void setOrganism(std::string new_val);
    void setSeq(std::string new_val);

    std::string toString();
};





#endif //T1_916_MARIA_POPESCU_1_GENE_H
