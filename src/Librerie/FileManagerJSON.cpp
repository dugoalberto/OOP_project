//
// Created by Alberto Dugo on 09/05/2023.
//

#include <iostream>
#include "FileManagerJSON.h"
#include "json.hpp"
#include "../Model/hierarchy/SpedizionePremium.h"
#include "../Model/hierarchy/SpedizioneEconomica.h"
#include "../Model/hierarchy/SpedizioneCargo.h"
#include "../Model/hierarchy/SpedizioneInternazionale.h"
#include "../Model/hierarchy/SpedizioneAssicurata.h"

FileManagerJSON::FileManagerJSON(const std::string &fn) : fileName(fn + ".json"){
    file = new fstream;
    file->open("src/SaveFiles/"+fileName,std::ios::app);
    file->close();
}

void FileManagerJSON::saveData(ArrayList<Spedizione *> &vettore) const {
    std::ofstream file("src/SaveFiles/"+fileName, std::ios::out);
    file << "[";
    auto it = vettore.begin();
    if (it != vettore.end()) {
        file << (*it)->toSaveFormat(1).dump();
        ++it;
    }
    for (; it != vettore.end(); ++it) {
        file << ",\n";
        file << (*it)->toSaveFormat(1).dump();
    }
    file << "]";
    file.close();
}

ArrayList<Spedizione*> FileManagerJSON::readSpedizioni() const {
    std::ifstream file("src/SaveFiles/"+fileName);
    json jsonData;
    file >> jsonData;
    ArrayList<Spedizione*> res;

    for(const auto& spedizione : jsonData) {
        Spedizione *toAdd = nullptr;
        if (spedizione["TypeName"] == "SPEDIZIONEPREMIUM") {
            toAdd = new SpedizionePremium(
                    spedizione["trakingNumber"],
                    new Address(spedizione["mittente"]["nomeCognome"], spedizione["mittente"]["indirizzo"],
                                spedizione["mittente"]["citta"], spedizione["mittente"]["provincia"],
                                spedizione["mittente"]["cap"], spedizione["mittente"]["nazione"]),
                    new Address(spedizione["destinatario"]["nomeCognome"], spedizione["destinatario"]["indirizzo"],
                                spedizione["destinatario"]["citta"], spedizione["destinatario"]["provincia"],
                                spedizione["destinatario"]["cap"], spedizione["destinatario"]["nazione"]),
                    new Package(spedizione["pacco"]["contenuto"], spedizione["pacco"]["valore"],
                                spedizione["pacco"]["volume"], spedizione["pacco"]["peso"]),
                    new Stato(spedizione["stato"]["descStato"], Filiale(spedizione["stato"]["filiale"]["citta"],
                                                                        spedizione["stato"]["filiale"]["provincia"],
                                                                        spedizione["stato"]["filiale"]["numeroTel"])),
                    spedizione["descrizione"],
                    spedizione["arrivo_data"]["anno"], spedizione["arrivo_data"]["mese"],
                    spedizione["arrivo_data"]["giorno"], spedizione["arrivo_data"]["ora"],
                    spedizione["arrivo_data"]["minuti"]
            );
            res.add(toAdd);
        } else if (spedizione["TypeName"] == "SPEDIZIONEECONOMICA") {
            toAdd = new SpedizioneEconomica(
                    spedizione["trakingNumber"],
                    new Address(spedizione["mittente"]["nomeCognome"], spedizione["mittente"]["indirizzo"],
                                spedizione["mittente"]["citta"], spedizione["mittente"]["provincia"],
                                spedizione["mittente"]["cap"]),
                    new Address(spedizione["destinatario"]["nomeCognome"], spedizione["destinatario"]["indirizzo"],
                                spedizione["destinatario"]["citta"], spedizione["destinatario"]["provincia"],
                                spedizione["destinatario"]["cap"]),
                    new Package(spedizione["pacco"]["contenuto"], spedizione["pacco"]["valore"],
                                spedizione["pacco"]["volume"], spedizione["pacco"]["peso"]),
                    new Stato(spedizione["stato"]["descStato"], Filiale(spedizione["stato"]["filiale"]["citta"],
                                                                        spedizione["stato"]["filiale"]["provincia"],
                                                                        spedizione["stato"]["filiale"]["numeroTel"])),
                    spedizione["descrizione"]
            );
            res.add(toAdd);
        } else if (spedizione["TypeName"] == "SPEDIZIONECARGOA" || spedizione["TypeName"] == "SPEDIZIONECARGOB") {
            toAdd = new SpedizioneCargo(
                    spedizione["trakingNumber"],
                    new Address(spedizione["mittente"]["nomeCognome"], spedizione["mittente"]["indirizzo"],
                                spedizione["mittente"]["citta"], spedizione["mittente"]["provincia"],
                                spedizione["mittente"]["cap"], spedizione["mittente"]["nazione"]),
                    new Address(spedizione["destinatario"]["nomeCognome"], spedizione["destinatario"]["indirizzo"],
                                spedizione["destinatario"]["citta"], spedizione["destinatario"]["provincia"],
                                spedizione["destinatario"]["cap"], spedizione["destinatario"]["nazione"]),
                    new Package(spedizione["pacco"]["contenuto"], spedizione["pacco"]["valore"],
                                spedizione["pacco"]["volume"], spedizione["pacco"]["peso"]),
                    new Stato(spedizione["stato"]["descStato"], Filiale(spedizione["stato"]["filiale"]["citta"],
                                                                        spedizione["stato"]["filiale"]["provincia"],
                                                                        spedizione["stato"]["filiale"]["numeroTel"])),
                    spedizione["descrizione"], SpedizioneCargo::TipologiaTrasporto((int) (spedizione["tipo_trasporto"]))
            );
            res.add(toAdd);
        } else if (spedizione["TypeName"] == "SPEDIZIONEINTERNAZIONALE") {
            toAdd = new SpedizioneInternazionale(
                    spedizione["trakingNumber"],
                    new Address(spedizione["mittente"]["nomeCognome"], spedizione["mittente"]["indirizzo"],
                                spedizione["mittente"]["citta"], spedizione["mittente"]["provincia"],
                                spedizione["mittente"]["cap"], spedizione["mittente"]["nazione"]),
                    new Address(spedizione["destinatario"]["nomeCognome"], spedizione["destinatario"]["indirizzo"],
                                spedizione["destinatario"]["citta"], spedizione["destinatario"]["provincia"],
                                spedizione["destinatario"]["cap"], spedizione["destinatario"]["nazione"]),
                    new Package(spedizione["pacco"]["contenuto"], spedizione["pacco"]["valore"],
                                spedizione["pacco"]["volume"], spedizione["pacco"]["peso"]),
                    new Stato(spedizione["stato"]["descStato"], Filiale(spedizione["stato"]["filiale"]["citta"],
                                                                        spedizione["stato"]["filiale"]["provincia"],
                                                                        spedizione["stato"]["filiale"]["numeroTel"])),
                    spedizione["descrizione"]
            );
            res.add(toAdd);
        } else if (spedizione["TypeName"] == "SPEDIZIONEASSICURATA") {
            std::vector<std::string> *servizi = new std::vector<std::string>();
            for (auto const &servizio: spedizione["servizi_assicurazione"])
                servizi->push_back(servizio.get<std::string>());

            toAdd = new SpedizioneAssicurata(
                    spedizione["trakingNumber"],
                    new Address(spedizione["mittente"]["nomeCognome"], spedizione["mittente"]["indirizzo"],
                                spedizione["mittente"]["citta"], spedizione["mittente"]["provincia"],
                                spedizione["mittente"]["cap"]),
                    new Address(spedizione["destinatario"]["nomeCognome"], spedizione["destinatario"]["indirizzo"],
                                spedizione["destinatario"]["citta"], spedizione["destinatario"]["provincia"],
                                spedizione["destinatario"]["cap"]),
                    new Package(spedizione["pacco"]["contenuto"], spedizione["pacco"]["valore"],
                                spedizione["pacco"]["volume"], spedizione["pacco"]["peso"]),
                    new Stato(spedizione["stato"]["descStato"], Filiale(spedizione["stato"]["filiale"]["citta"],
                                                                        spedizione["stato"]["filiale"]["provincia"],
                                                                        spedizione["stato"]["filiale"]["numeroTel"])),
                    spedizione["descrizione"],
                    new Assicurazione(spedizione["assicurazione"], spedizione["prezzo_assicurazione"]),
                    servizi
            );
            res.add(toAdd);
        }
    }

    file.close();
    return res;
}

std::vector<Assicurazione *> FileManagerJSON::readAssicurazioni() {
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

std::vector<Filiale*> FileManagerJSON::readFiliali() {
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

void FileManagerJSON::saveAssicurazioni(std::vector<Assicurazione *> vettore) {
    std::ofstream file("src/SaveFiles/Assicurazioni.txt", std::ios::out);
    for(auto it = vettore.begin(); it != vettore.end(); it++)
        file << (*it)->toString() + "\n";
    file.close();
}

void FileManagerJSON::saveFiliali(std::vector<Filiale *> vettore) {
    std::ofstream file("src/SaveFiles/Filiali.txt", std::ios::out);
    for(auto it = vettore.begin(); it != vettore.end(); it++)
        file << (*it)->toString() + "\n";
    file.close();
}
