//
// Created by Alberto Dugo on 16/05/2023.
//

#include "VisitorById.h"
VisitorById::VisitorById(int i) : id(i){}

bool VisitorById::accept(const Spedizione *spedizione) const {
    return spedizione->getTrakingNumber() == id;
}