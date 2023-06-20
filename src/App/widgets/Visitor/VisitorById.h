//
// Created by Alberto Dugo on 16/05/2023.
//

#ifndef DUGO_PROGETTO_VISITORBYID_H
#define DUGO_PROGETTO_VISITORBYID_H


#include "../../../Model/hierarchy/Spedizione.h"

class VisitorById {
private:
    int id;
public:
    VisitorById(int i);
    bool accept(const Spedizione* spedizione) const;
};


#endif //DUGO_PROGETTO_VISITORBYID_H
