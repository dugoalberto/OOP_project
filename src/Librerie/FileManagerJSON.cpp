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
    std::ofstream testFile("src/SaveFiles/"+fileName, std::ios::app);
    if(testFile.tellp() == 0)
        testFile << "[]";
    testFile.close();

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
    std::ofstream *fileAssicurazioniJSON = new ofstream;
    fileAssicurazioniJSON->open("src/SaveFiles/Assicurazioni.json",std::ios::app);
    if(fileAssicurazioniJSON->tellp() == 0){ //IL FILE è VUOTO
        *fileAssicurazioniJSON << "[]";
    }
    fileAssicurazioniJSON->close();

    std::ifstream file("src/SaveFiles/Assicurazioni.json");
    json jsonData;
    file >> jsonData;
    std::vector<Assicurazione*> res;

    for(const auto& assicurazione : jsonData)
        res.push_back(new Assicurazione(assicurazione["assicurazione"], assicurazione["prezzo"]));

    return res;
}

std::vector<Filiale*> FileManagerJSON::readFiliali() {
    std::ofstream *fileFilialiJSON = new ofstream;
    fileFilialiJSON->open("src/SaveFiles/Filiali.json", std::ios::app);
    if(fileFilialiJSON->tellp() == 0){ //IL FILE è VUOTO
        *fileFilialiJSON << "[]";
    }
    fileFilialiJSON->close();

    std::ifstream file("src/SaveFiles/Filiali.json");
    json jsonData;
    file >> jsonData;
    std::vector<Filiale*> res;

    for(const auto& filiale : jsonData)
        res.push_back(new Filiale(filiale["citta"], filiale["provincia"], filiale["numeroTel"]));

    return res;
}

void FileManagerJSON::saveAssicurazioni(std::vector<Assicurazione *> vettore) {
    std::ofstream file("src/SaveFiles/Assicurazioni.json", std::ios::out);
    file << "[";
    auto it = vettore.begin();
    if (it != vettore.end()) {
        file << (*it)->toJsonFormat().dump();
        ++it;
    }
    for (; it != vettore.end(); ++it) {
        file << ",\n";
        file << (*it)->toJsonFormat().dump();
    }
    file << "]";
    file.close();
}

void FileManagerJSON::saveFiliali(std::vector<Filiale *> vettore) {
    std::ofstream file("src/SaveFiles/Filiali.json", std::ios::out);
    file << "[";
    auto it = vettore.begin();
    if (it != vettore.end()) {
        file << (*it)->toJsonFormat().dump();
        ++it;
    }
    for (; it != vettore.end(); ++it) {
        file << ",\n";
        file << (*it)->toJsonFormat().dump();
    }
    file << "]";
    file.close();
}
