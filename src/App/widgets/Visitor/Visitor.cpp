//
// Created by utente on 10/05/2023.
//

#include "Visitor.h"
#include "../Pages/HierachyPages/SpedizioneAssicurataPage.h"

void Visitor::visit(SpedizioneAssicurata *obj, bool toEdit) {
    widget = new SpedizioneAssicurataPage(obj, toEdit);
}

void Visitor::visit(SpedizioneEconomica *obj, bool toEdit) {
    //widget = new SpedizioneAssicurataPage(obj, toEdit);
}

void Visitor::visit(SpedizionePremium *obj, bool toEdit) {
    //widget = new SpedizioneAssicurataPage(obj, toEdit);
}

void Visitor::visit(SpedizioneCargo *obj, bool toEdit) {
    //widget = new SpedizioneAssicurataPage(obj, toEdit);
}

void Visitor::visit(SpedizioneInternazionale *obj, bool toEdit) {
    //widget = new SpedizioneAssicurataPage(obj, toEdit);
}