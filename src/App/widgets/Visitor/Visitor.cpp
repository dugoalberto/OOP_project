//
// Created by utente on 10/05/2023.
//

#include "Visitor.h"
#include "../Pages/HierachyPages/SpedizioneAssicurataPage.h"
#include "../Pages/HierachyPages/SpedizionePremiumPage.h"

void Visitor::visit(const SpedizioneAssicurata *obj, bool toEdit) {
    widget = new SpedizioneAssicurataPage(const_cast<SpedizioneAssicurata*>(obj), toEdit);
}

void Visitor::visit(const SpedizioneEconomica *obj, bool toEdit) {
    //widget = new SpedizioneAssicurataPage(obj, toEdit);
}

void Visitor::visit(const SpedizionePremium *obj, bool toEdit) {
    widget = new SpedizionePremiumPage(const_cast<SpedizionePremium*>(obj), toEdit);
}

void Visitor::visit(const SpedizioneCargo *obj, bool toEdit) {
    //widget = new SpedizioneAssicurataPage(obj, toEdit);
}

void Visitor::visit(const SpedizioneInternazionale *obj, bool toEdit) {
    //widget = new SpedizioneAssicurataPage(obj, toEdit);
}

HierachyPageInterface* Visitor::getWidget() const {
    return widget;
}