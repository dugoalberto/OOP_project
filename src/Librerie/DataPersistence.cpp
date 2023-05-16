//
// Created by Lorenzo on 06/04/2023.
//

#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "DataPersistence.h"
#include "../Collection/ArrayList.h"

using json = nlohmann::json;
using namespace std;

DataPersistence::DataPersistence(const string &nomeFile) {
    this->nomeFile = nomeFile;
}

void DataPersistence::scriviDati(const json &dati) {
    ofstream file(DataPersistence::nomeFile);
    file << dati.dump(4);
    file.close();
}

json DataPersistence::leggiDati() {
    ifstream file(DataPersistence::nomeFile);
    json dati;
    file >> dati;
    file.close();
    return dati;
}
