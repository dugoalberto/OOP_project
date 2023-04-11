//
// Created by Lorenzo on 06/04/2023.
//

#ifndef OOP_PROJECT_DATAPERSISTENCE_H
#define OOP_PROJECT_DATAPERSISTENCE_H

#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class DataPersistence {
private:
    string nomeFile;

public:
    DataPersistence(const string &nomeFile);

    void scriviDati(const json &dati);

    json leggiDati();

};


#endif //OOP_PROJECT_DATAPERSISTENCE_H
