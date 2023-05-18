//
// Created by utente on 10/05/2023.
//

#include "Visitor.h"
#include "../Pages/HierachyPages/SpedizioneAssicurataPage.h"
#include "../Pages/HierachyPages/SpedizionePremiumPage.h"
#include "../Pages/HierachyPages/SpedizioneInternazionalePage.h"
#include "../Pages/HierachyPages/SpedizioneCargoPage.h"
#include "../Pages/HierachyPages/SpedizioneEconomicaPage.h"

void Visitor::visit(const SpedizioneAssicurata *obj, bool toEdit) {
    widget = new SpedizioneAssicurataPage(const_cast<SpedizioneAssicurata*>(obj), toEdit);
}

void Visitor::visit(const SpedizioneEconomica *obj, bool toEdit) {
    widget = new SpedizioneEconomicaPage(const_cast<SpedizioneEconomica*>(obj), toEdit);
}

void Visitor::visit(const SpedizionePremium *obj, bool toEdit) {
    widget = new SpedizionePremiumPage(const_cast<SpedizionePremium*>(obj), toEdit);
}

void Visitor::visit(const SpedizioneCargo *obj, bool toEdit) {
    widget = new SpedizioneCargoPage(const_cast<SpedizioneCargo*>(obj), toEdit);
}

void Visitor::visit(const SpedizioneInternazionale *obj, bool toEdit) {
    widget = new SpedizioneInternazionalePage(const_cast<SpedizioneInternazionale*>(obj), toEdit);
}

HierachyPageInterface* Visitor::getWidget() const {
    return widget;
}