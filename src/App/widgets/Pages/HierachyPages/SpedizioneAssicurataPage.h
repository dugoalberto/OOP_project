//
// Created by utente on 12/05/2023.
//

#ifndef DUGO_PROGETTO_SPEDIZIONEASSICURATAPAGE_H
#define DUGO_PROGETTO_SPEDIZIONEASSICURATAPAGE_H


#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include "HierachyPageInterface.h"
#include "../../../../Model/SupportClasses/Filiale.h"
#include "../../../../Collection/ArrayList.h"
#include "../../CustomWidgets/MyButton.h"
#include "../../../../Model/hierarchy/SpedizioneAssicurata.h"
#include "../../CustomWidgets/AddressWidget.h"
#include "../../CustomWidgets/PackageWidgetFolder/PackageWidgetAssicurata.h"

class SpedizioneAssicurataPage : public HierachyPageInterface {
Q_OBJECT
private:
    AddressWidget* mittente;
    AddressWidget* destinatario;
    PackageWidgetAssicurata* package;

    QComboBox* possibiliFiliali;
    QComboBox* possibiliStati;
    QTextEdit* txtDescrizione;
    MyButton* btnAnnulla;
    MyButton* btnConferma;
    std::vector<Filiale*> filiali;

    bool ConvalidaInput() const;
public:
    SpedizioneAssicurataPage(SpedizioneAssicurata * = nullptr, bool toEdit = false, QWidget *parent = nullptr);
public slots:
    void CreaSlot() override;
    void ModificaSlot();
};


#endif //DUGO_PROGETTO_SPEDIZIONEASSICURATAPAGE_H
