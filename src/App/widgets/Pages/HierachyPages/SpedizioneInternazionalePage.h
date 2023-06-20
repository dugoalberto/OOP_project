//
// Created by Alberto Dugo on 18/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONEINTERNAZIONALEPAGE_H
#define DUGO_PROGETTO_SPEDIZIONEINTERNAZIONALEPAGE_H

#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include "HierachyPageInterface.h"
#include "../../../../Model/SupportClasses/Filiale.h"
#include "../../../../Collection/ArrayList.h"
#include "../../CustomWidgets/MyButton.h"
#include "../../../../Model/hierarchy/SpedizioneInternazionale.h"
#include "../../CustomWidgets/AddressWidget.h"
#include "../../CustomWidgets/PackageWidgetFolder/PackageWidgetBase.h"

class SpedizioneInternazionalePage : public HierachyPageInterface{
    AddressWidget* mittente;
    AddressWidget* destinatario;
    PackageWidgetBase* package;

    QComboBox* possibiliFiliali;
    QComboBox* possibiliStati;
    QTextEdit* txtDescrizione;
    MyButton* btnAnnulla;
    MyButton* btnConferma;
    std::vector<Filiale*> filiali;

    bool ConvalidaInput() const;
public:
    SpedizioneInternazionalePage(SpedizioneInternazionale * = nullptr, bool toEdit = false, QWidget *parent = nullptr);
public slots:
    void CreaSlot() override;
    void ModificaSlot();
};


#endif //DUGO_PROGETTO_SPEDIZIONEINTERNAZIONALEPAGE_H
