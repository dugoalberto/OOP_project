//
// Created by Alberto Dugo on 09/05/2023.
//

#ifndef DUGO_PROGETTO_FILEMANAGERJSON_H
#define DUGO_PROGETTO_FILEMANAGERJSON_H
#include "../Collection/ArrayList.h"
#include "../Model/hierarchy/Spedizione.h"
#include "../Model/SupportClasses/Assicurazione.h"
#include <fstream>

class FileManagerJSON {

private:
    std::string fileName;
    fstream* file;
public:
    explicit FileManagerJSON(const std::string&);
    void saveData(ArrayList<Spedizione *> &vettore) const;
    ArrayList<Spedizione*> readSpedizioni() const;

    static void saveAssicurazioni(std::vector<Assicurazione*>);
    static void saveFiliali(std::vector<Filiale*>);
    static std::vector<Assicurazione *> readAssicurazioni();
    static std::vector<Filiale *> readFiliali();
};


#endif //DUGO_PROGETTO_FILEMANAGER_H
