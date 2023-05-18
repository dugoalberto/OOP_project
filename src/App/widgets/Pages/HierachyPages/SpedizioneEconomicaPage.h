//
// Created by utente on 19/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONEECONOMICAPAGE_H
#define DUGO_PROGETTO_SPEDIZIONEECONOMICAPAGE_H

#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include "HierachyPageInterface.h"
#include "../../../../Model/SupportClasses/Filiale.h"
#include "../../../../Collection/ArrayList.h"
#include "../../CustomWidgets/MyButton.h"
#include "../../../../Model/hierarchy/SpedizioneEconomica.h"
#include "../../CustomWidgets/AddressWidget.h"
#include "../../CustomWidgets/PackageWidgetFolder/PackageWidgetBase.h"


class SpedizioneEconomicaPage : public HierachyPageInterface{

    AddressWidget* mittente;
    AddressWidget* destinatario;
    PackageWidgetBase* package;

    QComboBox* possibiliFiliali;
    QComboBox* possibiliStati;
    QTextEdit* txtDescrizione;
    MyButton* btnAnnulla;
    MyButton* btnConferma;
    std::vector<Filiale> filiali;

    bool ConvalidaInput() const;
public:
    SpedizioneEconomicaPage(SpedizioneEconomica * = nullptr, bool toEdit = false, QWidget *parent = nullptr);
public slots:
    void CreaSlot() override;
    void ModificaSlot();

};


#endif //DUGO_PROGETTO_SPEDIZIONEECONOMICAPAGE_H
