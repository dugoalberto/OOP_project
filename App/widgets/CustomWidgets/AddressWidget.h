//
// Created by utente on 12/05/2023.
//

#ifndef DUGO_PROGETTO_ADDRESSWIDGET_H
#define DUGO_PROGETTO_ADDRESSWIDGET_H


#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include "../../../Model/SupportClasses/Address.h"
#include "QLabelTitle.h"

class AddressWidget : public QWidget{
Q_OBJECT
private:
    Address* address;
    QLabelTitle* lblAddress;
    QLineEdit* txtNome;
    QLineEdit* txtIndirizzo;
    QLineEdit* txtCitta;
    QLineEdit* txtProvincia;
    QLineEdit* txtStato;
    QLineEdit* txtCap;

public:
    enum Sender{
        MITTENTE,
        DESTINATARIO
    };
    AddressWidget(Address* = nullptr, bool toEdit = false, Sender = Sender::MITTENTE, bool international = false, QWidget* parent = nullptr);
    Address* getAddress() const;

    void setField(bool toBeEdited);
};


#endif //DUGO_PROGETTO_ADDRESSWIDGET_H
