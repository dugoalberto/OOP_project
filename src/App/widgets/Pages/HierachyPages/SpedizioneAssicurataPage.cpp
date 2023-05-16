//
// Created by utente on 12/05/2023.
//

#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include "SpedizioneAssicurataPage.h"
#include "../../../../Librerie/FileManager.h"

SpedizioneAssicurataPage::SpedizioneAssicurataPage(SpedizioneAssicurata *spe, bool toEdit, QWidget *parent): HierachyPageInterface(spe, parent) {
    QVBoxLayout* lytMain = new QVBoxLayout(this);

    QVBoxLayout* lytIndirizzi = new QVBoxLayout();
    mittente = new AddressWidget();
    lytIndirizzi->addWidget(mittente);
    destinatario = new AddressWidget(nullptr, false, AddressWidget::Sender::DESTINATARIO);
    lytIndirizzi->addWidget(destinatario);
    QGroupBox* grpAddress = new QGroupBox();
    grpAddress->setLayout(lytIndirizzi);

    lytMain->addWidget(grpAddress);
    //seconda riga
    QHBoxLayout* lowerRow = new QHBoxLayout();

    QVBoxLayout* lytPackage = new QVBoxLayout();
    package = new PackageWidgetAssicurata();
    lytPackage->addWidget(package);
    QGroupBox* grpPackage = new QGroupBox();
    grpPackage->setLayout(lytPackage);
    lowerRow->addWidget(grpPackage);

    //PARTE DESCRIZIONE
    QVBoxLayout* lytFilialiDescrizioni = new QVBoxLayout();
    lytFilialiDescrizioni->setAlignment(Qt::AlignCenter);

    QHBoxLayout* lytFilialiStato = new QHBoxLayout();

    QVBoxLayout* lytFiliale = new QVBoxLayout();
    lytFiliale->setAlignment(Qt::AlignCenter);
    possibiliFiliali = new QComboBox();
    filiali = FileManager::readFiliali();
    for(auto it = filiali.begin(); it != filiali.end(); ++it)
        possibiliFiliali->addItem(QString::fromStdString((*it).getCitta()));
    possibiliFiliali->setCurrentIndex(0);

    QVBoxLayout* lytStato = new QVBoxLayout();
    lytStato->setAlignment(Qt::AlignCenter);
    possibiliStati = new QComboBox();
    std::string stati[5] = {"In spedizione", "In arrivo", "In partenza", "In filiale", "Consegnato"};
    for(int i = 0; i < 5; i++){
        possibiliStati->addItem(QString::fromStdString(stati[i]));
    }
    lytFiliale->addWidget(new QLabel("Filiali presenti:"));
    lytFiliale->addWidget(possibiliFiliali);

    lytStato->addWidget(new QLabel("Stato spedizione:"));
    lytStato->addWidget(possibiliStati);

    lytFilialiStato->addLayout(lytFiliale);
    lytFilialiStato->addLayout(lytStato);
    lytFilialiDescrizioni->addLayout(lytFilialiStato);

    txtDescrizione = new QTextEdit();
    txtDescrizione->setPlaceholderText("Inserire descrizione (opzionale)");
    txtDescrizione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lytFilialiDescrizioni->addWidget(txtDescrizione);

    QGroupBox* grpFilialeStatoDescrizione = new QGroupBox();
    grpFilialeStatoDescrizione->setLayout(lytFilialiDescrizioni);
    lowerRow->addWidget(grpFilialeStatoDescrizione);

    //parte pulsanti
    QVBoxLayout* lytPulsanti = new QVBoxLayout();
    btnAnnulla = new MyButton("Annulla");
    btnAnnulla->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    btnAnnulla->setFixedWidth(180);
    btnConferma = new MyButton("Conferma");
    btnConferma->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    btnConferma->setFixedWidth(180);
    lytPulsanti->addWidget(btnAnnulla);
    lytPulsanti->addWidget(btnConferma);

    QGroupBox* grpPulsanti = new QGroupBox();
    grpPulsanti->setLayout(lytPulsanti);
    lowerRow->addWidget(grpPulsanti);

    connect(btnAnnulla, &QPushButton::clicked, this, &HierachyPageInterface::BackSlot);
    connect(btnConferma, &QPushButton::clicked, this, &HierachyPageInterface::CreaSlot);

    lytMain->addLayout(lowerRow);
}

void SpedizioneAssicurataPage::CreaSlot() {
    if( mittente->ConvalidaInput() &&
        destinatario->ConvalidaInput() &&
        package->ConvalidaInput()){

        Assicurazione* toSet = package->getAssicurazione();
        toSet->setNumeroServizi(package->getNumeroServiziSelezionati());
        SpedizioneAssicurata* nuova = new SpedizioneAssicurata(-1,
                                                               *mittente->getAddress(),
                                                               *mittente->getAddress(),
                                                               *package->getPackage(),
                                                               Stato(possibiliStati->currentText().toStdString(), filiali[possibiliFiliali->currentIndex()]),
                                                               txtDescrizione->toPlainText().toStdString(),
                                                               *toSet);
        emit HierachyPageInterface::CreaSignal(nuova);

    }

}