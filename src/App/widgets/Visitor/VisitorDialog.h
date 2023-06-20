//
// Created by Alberto Dugo on 24/05/2023.
//

#ifndef DUGO_PROGETTO_VISITORDIALOG_H
#define DUGO_PROGETTO_VISITORDIALOG_H

#include <QDialog>

class Filiale;
class Assicurazione;

class VisitorDialog {
private:
    QDialog* dialog;
public:
    void visit(const Filiale*, bool);
    void visit(const Assicurazione*, bool);
    QDialog* getWidget() const;
};


#endif //DUGO_PROGETTO_VISITORDIALOG_H
