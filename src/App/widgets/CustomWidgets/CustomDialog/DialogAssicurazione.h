//
// Created by Alberto Dugo on 24/05/2023.
//

#ifndef DUGO_PROGETTO_DIALOGASSICURAZIONE_H
#define DUGO_PROGETTO_DIALOGASSICURAZIONE_H


#include <QDialog>
#include <QLineEdit>
#include "../../../../Model/SupportClasses/Assicurazione.h"

class DialogAssicurazione : public QDialog{
Q_OBJECT
protected:
    Assicurazione* assicurazione;
    QLineEdit* txtNome;
    QLineEdit* txtNumero;
public:
    DialogAssicurazione(Assicurazione* = nullptr, bool = false, QWidget* = nullptr);
    bool ConvalidaInput();
public slots:
    void ModificaAssicurazioneSlot();
    void textChangedSlot();
    void AggiungiAssicurazioneSlot();
signals:
    void AssicurazioneModificataSignal();
    void AggiungiAssicurazioneSignal(Assicurazione *);
};


#endif //DUGO_PROGETTO_DIALOGASSICURAZIONE_H
