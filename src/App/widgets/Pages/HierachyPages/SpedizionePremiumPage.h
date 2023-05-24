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
#include "../../CustomWidgets/MyButton.h"
#include "../../CustomWidgets/AddressWidget.h"
#include "../../CustomWidgets/PackageWidgetFolder/PackageWidgetPremium.h"


class SpedizionePremiumPage : public HierachyPageInterface{
private:
    AddressWidget* mittente;
    AddressWidget* destinatario;
    PackageWidgetPremium* package;

    QComboBox* possibiliFiliali;
    QComboBox* possibiliStati;
    QTextEdit* txtDescrizione;
    MyButton* btnAnnulla;
    MyButton* btnConferma;
    std::vector<Filiale*> filiali;

    bool ConvalidaInput();
public:
    SpedizionePremiumPage(SpedizionePremium* = nullptr, bool toEdit = false, QWidget* parent = nullptr);
public slots:
    void CreaSlot() override;
    void ModificaSlot();
};


#endif //DUGO_PROGETTO_SPEDIZIONEPREMIUMPAGE_H
