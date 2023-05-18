//
// Created by utente on 10/05/2023.
//

#ifndef DUGO_PROGETTO_VISITOR_H
#define DUGO_PROGETTO_VISITOR_H

#include "../Pages/HierachyPages/HierachyPageInterface.h"

class SpedizionePremium;
class SpedizioneEconomica;
class SpedizioneCargo;
class SpedizioneInternazionale;
class SpedizioneAssicurata;

class Visitor {
private:
    HierachyPageInterface* widget;
public:
    void visit(const SpedizionePremium*, bool);
    void visit(const SpedizioneEconomica*, bool);
    void visit(const SpedizioneCargo*, bool);
    void visit(const SpedizioneInternazionale*, bool);
    void visit(const SpedizioneAssicurata*, bool);
    HierachyPageInterface* getWidget() const;
};


#endif //DUGO_PROGETTO_VISITOR_H
