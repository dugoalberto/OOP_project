//
// Created by utente on 10/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONEPREMIUMPAGE_H
#define DUGO_PROGETTO_SPEDIZIONEPREMIUMPAGE_H

#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include "../../../../Model/hierarchy/Spedizione.h"
#include "../../../../Model/hierarchy/SpedizionePremium.h"
#include "HierachyPageInterface.h"


class SpedizionePremiumPage : public HierachyPageInterface{
private:
    const SpedizionePremium* obj;
    QLineEdit* txtTrackingNumber;

    //mittente
    QLineEdit* txtMittenteNomeCognome;
    QLineEdit* txtMittenteAddress;
    QLineEdit* txtMittenteCitta;
    QLineEdit* txtMittenteProvincia;
    QLineEdit* txtMittenteNazione;
    QLineEdit* txtMittenteCap;

    //destinatario
    QLineEdit* txtDestinatarioAddress;
    QLineEdit* txtDestinatarioCitta;
    QLineEdit* txtDestinatarioProvincia;
    QLineEdit* txtDestinatarioNazione;
    QLineEdit* txtDestinatarioCap;

    QLineEdit* txtContenuto;
    QLineEdit* txtValore;

    QLineEdit* txtPeso;
    QLineEdit* txtVolume;

    QLineEdit* txtStato;
    QComboBox* txtFiliale;

    QTextEdit* txtDescrizione;
};


#endif //DUGO_PROGETTO_SPEDIZIONEPREMIUMPAGE_H
