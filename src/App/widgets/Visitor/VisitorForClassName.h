//
// Created by Alberto Dugo on 03/07/2023.
//

#ifndef DUGO_PROGETTO_VISITORFORCLASSNAME_H
#define DUGO_PROGETTO_VISITORFORCLASSNAME_H


#include <string>

class SpedizioneAssicurata;
class SpedizioneEconomica;
class SpedizionePremium;
class SpedizioneInternazionale;
class SpedizioneCargo;

class VisitorForClassName {
private:
    std::string className;
public:
    VisitorForClassName();
    void visit(const SpedizioneAssicurata*);
    void visit(const SpedizioneEconomica*);
    void visit(const SpedizionePremium*);
    void visit(const SpedizioneInternazionale*);
    void visit(const SpedizioneCargo*);
    std::string getClassName() const;
};


#endif //DUGO_PROGETTO_VISITORFORCLASSNAME_H
