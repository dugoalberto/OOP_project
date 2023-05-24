//
// Created by utente on 18/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONECARGOPAGE_H
#define DUGO_PROGETTO_SPEDIZIONECARGOPAGE_H

#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include "HierachyPageInterface.h"
#include "../../../../Model/SupportClasses/Filiale.h"
#include "../../../../Collection/ArrayList.h"
#include "../../CustomWidgets/MyButton.h"
#include "../../../../Model/hierarchy/SpedizioneCargo.h"
#include "../../CustomWidgets/AddressWidget.h"
#include "../../CustomWidgets/PackageWidgetFolder/PackageWidgetCargo.h"

class SpedizioneCargoPage : public HierachyPageInterface{
    AddressWidget* mittente;
    AddressWidget* destinatario;
    PackageWidgetCargo* package;

    QComboBox* possibiliFiliali;
    QComboBox* possibiliStati;
    QTextEdit* txtDescrizione;
    MyButton* btnAnnulla;
    MyButton* btnConferma;
    std::vector<Filiale*> filiali;

    bool ConvalidaInput() const;
public:
    SpedizioneCargoPage(SpedizioneCargo * = nullptr, bool toEdit = false, QWidget *parent = nullptr);
public slots:
    void CreaSlot() override;
    void ModificaSlot();
};


#endif //DUGO_PROGETTO_SPEDIZIONECARGOPAGE_H
