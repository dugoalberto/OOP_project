//
// Created by utente on 24/05/2023.
//

#ifndef DUGO_PROGETTO_DIALOGFILIALE_H
#define DUGO_PROGETTO_DIALOGFILIALE_H


#include <QDialog>
#include <QHBoxLayout>
#include <QLineEdit>
#include "../../../../Model/SupportClasses/Filiale.h"

class DialogFiliale : public QDialog {
Q_OBJECT
protected:
    Filiale* filiale;
    QLineEdit* txtNome;
    QLineEdit* txtProvincia;
    QLineEdit* txtNumero;
public:
    DialogFiliale(Filiale* = nullptr, bool = false, QWidget* = nullptr);
    bool ConvalidaInput();
public slots:
    void ModificaFilialeSlot();
    void textChangedSlot();
    void AggiungiFilialeSlot();
    signals:
    void FilialeModificataSignal();
    void AggiungiFilialeSignal(Filiale *);
};


#endif //DUGO_PROGETTO_DIALOGFILIALE_H
