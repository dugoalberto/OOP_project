//
// Created by utente on 09/05/2023.
//

#include <iostream>
#include "FileManager.h"
#include "../Model/hierarchy/SpedizionePremium.h"

FileManager::FileManager(const std::string &fn) : fileName(fn+".txt"){
    file = new fstream;
    file->open("../"+fileName,std::ios::app);
    file->close();
}

void FileManager::saveData(ArrayList<Spedizione *> &vettore) const {
    std::ofstream file("../"+fileName);
    for(auto it = vettore.begin(); it != vettore.end(); it++)
        file << (*it)->toSaveFormat() + "\n";
    file.close();
}

ArrayList<Spedizione*> FileManager::readFromFile() const {
    ArrayList<Spedizione*> res;
    file->open("../"+fileName,std::ios::in);
    string linea;
    std::getline(*file, linea);
    while(linea != ""){
        std::vector<std::string> att = Spedizione::ScomposeAttribute(linea);
        Spedizione* toAdd = nullptr;
        if(att[0] == "SPEDIZIONEPREMIUM"){
            toAdd = new SpedizionePremium(std::stoi(att[1]),
                                          Address(att[2], att[3], att[4], att[5], att[6], std::stoi(att[7])),
                                          Address(att[8], att[9], att[10], att[11], att[12], std::stoi(att[13])),
                                          Package(att[14], std::stod(att[15])),
                                          std::stoi(att[16]), std::stod(att[17]),
                                          Stato(att[18],Filiale(att[19],att[20], att[21])),
                                          att[22], std::stoi(att[23]), std::stoi(att[24]), std::stoi(att[25]), std::stoi(att[26]), std::stoi(att[27])
                                          );
            dynamic_cast<SpedizionePremium*>(toAdd)->setOrario(std::stoi(att[28]), std::stoi(att[29]), std::stoi(att[30]), std::stoi(att[31]), std::stoi(att[32]));
        }

        res.add(toAdd);
        std::getline(*file, linea);
    }

    return res;
}