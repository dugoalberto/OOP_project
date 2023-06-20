//
// Created by Alberto Dugo on 09/05/2023.
//

#include <iostream>
#include "FileManager.h"
#include "../Model/hierarchy/SpedizionePremium.h"
#include "../Model/hierarchy/SpedizioneEconomica.h"
#include "../Model/hierarchy/SpedizioneCargo.h"
#include "../Model/hierarchy/SpedizioneInternazionale.h"
#include "../Model/hierarchy/SpedizioneAssicurata.h"

FileManager::FileManager(const std::string &fn) : fileName(fn+".txt"){
    file = new fstream;
    file->open("src/SaveFiles/"+fileName,std::ios::app);
    file->close();
}

void FileManager::saveData(ArrayList<Spedizione *> &vettore) const {
    std::ofstream file("src/SaveFiles/"+fileName, std::ios::out);
    for(auto it = vettore.begin(); it != vettore.end(); it++)
        file << (*it)->toSaveFormat() + "\n";
    file.close();
}

ArrayList<Spedizione*> FileManager::readSpedizioni() const {
    ArrayList<Spedizione*> res;
    file->open("src/SaveFiles/"+fileName,std::ios::in);
    string linea;
    std::getline(*file, linea);
    while(linea != ""){
        std::vector<std::string> att = Spedizione::ScomposeAttribute(linea);
        Spedizione* toAdd = nullptr;
        if(att[0] == "SPEDIZIONEPREMIUM"){
            toAdd = new SpedizionePremium(std::stoi(att[1]),
                                          new Address(att[2], att[3], att[4], att[5], std::stoi(att[7])),
                                          new Address(att[8], att[9], att[10], att[11], std::stoi(att[13])),
                                          new Package(att[14], std::stof(att[15]), std::stof(att[16]), std::stof(att[17])),
                                          new Stato(att[18], Filiale(att[19], att[20], att[21])),
                                          att[22], std::stoi(att[23]), std::stoi(att[24]), std::stoi(att[25]),
                                          std::stoi(att[26]), std::stoi(att[27])
            );
            dynamic_cast<SpedizionePremium*>(toAdd)->setOrario(std::stoi(att[28]), std::stoi(att[29]), std::stoi(att[30]), std::stoi(att[31]), std::stoi(att[32]));
        }else if(att[0] == "SPEDIZIONEECONOMICA"){
            toAdd = new SpedizioneEconomica(std::stoi(att[1]),
                                            new Address(att[2], att[3], att[4], att[5], std::stoi(att[7])),
                                            new Address(att[8], att[9], att[10], att[11], std::stoi(att[13])),
                                            new Package(att[14], std::stof(att[15]), std::stof(att[16]), std::stof(att[17])),
                                            new Stato(att[18], Filiale(att[19], att[20], att[21])),
                                            att[22]
            );
        }else if(att[0] == "SPEDIZIONECARGOA" || att[0] == "SPEDIZIONECARGOB"){
            toAdd = new SpedizioneCargo(std::stoi(att[2]),
                                        new Address(att[3], att[4], att[5], att[6], std::stoi(att[8]), att[7]),
                                        new Address(att[9], att[10], att[11], att[12], std::stoi(att[14]), att[13]),
                                        new Package(att[15], std::stof(att[16]), std::stof(att[17]), std::stof(att[18])),
                                        new Stato(att[19], Filiale(att[20], att[21], att[22])),
                                        att[23], SpedizioneCargo::TipologiaTrasporto(std::stoi(att[24]))
            );

        }else if(att[0] == "SPEDIZIONEINTERNAZIONALE"){
            toAdd = new SpedizioneInternazionale(std::stoi(att[1]),
                                                 new Address(att[2], att[3], att[4], att[5], std::stoi(att[7]), att[6]),
                                                 new Address(att[8], att[9], att[10], att[11], std::stoi(att[13]), att[12]),
                                                 new Package(att[14], std::stof(att[15]), std::stof(att[16]), std::stof(att[17])),
                                                 new Stato(att[18], Filiale(att[19], att[20], att[21])),
                                                 att[22]
            );
        }else if(att[0] == "SPEDIZIONEASSICURATA"){
            std::vector<std::string>* servizi = new std::vector<std::string>();
            for(int i = 0; i < stoi(att[25]); i++)
                servizi->push_back(att[26+i]);

            toAdd = new SpedizioneAssicurata(std::stoi(att[1]),
                                             new Address(att[2], att[3], att[4], att[5], std::stoi(att[7])),
                                             new Address(att[8], att[9], att[10], att[11], std::stoi(att[13])),
                                             new Package(att[14], std::stof(att[15]), std::stof(att[16]),
                                                         std::stof(att[17])),
                                             new Stato(att[18], Filiale(att[19], att[20], att[21])),
                                             att[22], new Assicurazione(att[23], stof(att[24])), servizi);
        }

        res.add(toAdd);
        std::getline(*file, linea);
    }
    file->close();
    return res;
}

std::vector<Assicurazione *> FileManager::readAssicurazioni() {
    fstream *fA = new fstream;
    fA->open("src/SaveFiles/Assicurazioni.txt",std::ios::app);
    fA->close();

    std::vector<Assicurazione*> res;

    fstream* fileAssicurazioni = new fstream;
    fileAssicurazioni->open("src/SaveFiles/Assicurazioni.txt", std::ios::in);
    std::string linea;
    std::getline(*fileAssicurazioni, linea);
    while (linea != ""){
        std::vector<std::string> attAssicurazione;
        string current = "";
        for(unsigned int i = 0; i < linea.size(); i++){
            while(linea[i] != '|' && linea[i] != '\0'){
                current += linea[i];
                ++i;
            }
            attAssicurazione.push_back(current);
            current = "";
        }

        res.push_back(new Assicurazione(attAssicurazione[0], stof(attAssicurazione[1])));
        std::getline(*fileAssicurazioni, linea);
    }

    return res;
}

std::vector<Filiale*> FileManager::readFiliali() {
    fstream *fL = new fstream;
    fL->open("src/SaveFiles/Filiali.txt",std::ios::app);
    fL->close();

    std::vector<Filiale*> res;

    fstream* fileFiliali = new fstream;
    fileFiliali->open("src/SaveFiles/Filiali.txt", std::ios::in);
    std::string linea;
    std::getline(*fileFiliali, linea);
    while (linea != ""){
        std::vector<std::string> attFiliale;
        string current = "";
        for(unsigned int i = 0; i < linea.size(); i++){
            while(linea[i] != '|' && linea[i] != '\0'){
                current += linea[i];
                ++i;
            }
            attFiliale.push_back(current);
            current = "";
        }

        res.push_back(new Filiale(attFiliale[0], attFiliale[1], attFiliale[2]));
        std::getline(*fileFiliali, linea);
    }

    return res;
}

void FileManager::saveAssicurazioni(std::vector<Assicurazione *> vettore) {
    std::ofstream file("src/SaveFiles/Assicurazioni.txt", std::ios::out);
    for(auto it = vettore.begin(); it != vettore.end(); it++)
        file << (*it)->toString() + "\n";
    file.close();
}

void FileManager::saveFiliali(std::vector<Filiale *> vettore) {
    std::ofstream file("src/SaveFiles/Filiali.txt", std::ios::out);
    for(auto it = vettore.begin(); it != vettore.end(); it++)
        file << (*it)->toString() + "\n";
    file.close();
}
