//
// Created by Alberto Dugo on 03/07/2023.
//

#include "VisitorForClassName.h"
#include "../../../Model/hierarchy/SpedizioneCargo.h"

VisitorForClassName::VisitorForClassName() : className("") {}

void VisitorForClassName::visit(const SpedizioneCargo *s) {
    className = "SPEDIZIONECARGO";
    className += ((s->getTipologiaTrasporto() == SpedizioneCargo::TipologiaTrasporto::AEREO)? "A":"B");
}

void VisitorForClassName::visit(const SpedizionePremium *) {
    className = "SPEDIZIONEPREMIUM";
}

void VisitorForClassName::visit(const SpedizioneEconomica *) {
    className = "SPEDIZIONEECONOMICA";
}

void VisitorForClassName::visit(const SpedizioneAssicurata *) {
    className = "SPEDIZIONEASSICURATA";
}

void VisitorForClassName::visit(const SpedizioneInternazionale *) {
    className = "SPEDIZIONEINTERNAZIONALE";
}

std::string VisitorForClassName::getClassName() const {
    return className;
}
