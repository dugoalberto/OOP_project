//
// Created by Alberto Dugo on 18/05/2023.
//

#include "SpedizioneCargoPage.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QDialog>
#include "../../../../Librerie/FileManagerJSON.h"

SpedizioneCargoPage::SpedizioneCargoPage(SpedizioneCargo *spe, bool toEdit, QWidget *parent) : HierachyPageInterface(spe, parent) {
    QVBoxLayout* lytMain = new QVBoxLayout(this);

    QVBoxLayout* lytIndirizzi = new QVBoxLayout();
    mittente = new AddressWidget(((spe)? spe->getMittente(): nullptr), toEdit, AddressWidget::Sender::MITTENTE, true);
    lytIndirizzi->addWidget(mittente);
    destinatario = new AddressWidget(((spe)? spe->getDestinatario(): nullptr), toEdit, AddressWidget::Sender::DESTINATARIO, true);
    lytIndirizzi->addWidget(destinatario);
    QGroupBox* grpAddress = new QGroupBox();
    grpAddress->setLayout(lytIndirizzi);

    lytMain->addWidget(grpAddress);
    //seconda riga
    QHBoxLayout* lowerRow = new QHBoxLayout();

    QVBoxLayout* lytPackage = new QVBoxLayout();
    package = new PackageWidgetCargo((spe)? spe->getPacco():nullptr, (spe)? (spe->getTipologiaTrasporto() == 0)? "Aereo" : "Barca" : "",toEdit);
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
    filiali = FileManagerJSON::readFiliali();
    if(spe) possibiliFiliali->addItem(QString::fromStdString(spe->getStato()->getFiliale().getCitta()));
    for(auto it = filiali.begin(); it != filiali.end(); ++it)
        possibiliFiliali->addItem(QString::fromStdString((*it)->getCitta()));
    possibiliFiliali->setCurrentIndex(0);
    possibiliFiliali->setEditable(false);
    possibiliFiliali->setEnabled(toEdit);

    QVBoxLayout* lytStato = new QVBoxLayout();
    lytStato->setAlignment(Qt::AlignCenter);
    possibiliStati = new QComboBox();
    if(spe)  possibiliStati->addItem(QString::fromStdString(spe->getStato()->getDescStato()));
    std::string stati[5] = {"In spedizione", "In arrivo", "In partenza", "In filiale", "Consegnato"};
    for(int i = 0; i < 5; i++){
        possibiliStati->addItem(QString::fromStdString(stati[i]));
    }
    possibiliStati->setCurrentIndex(0);
    possibiliStati->setEditable(false);
    possibiliStati->setEnabled(toEdit);
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
    txtDescrizione->setEnabled(toEdit);
    if(spe) txtDescrizione->setText(QString::fromStdString(spe->getDescrizione()));

    QGroupBox* grpFilialeStatoDescrizione = new QGroupBox();
    grpFilialeStatoDescrizione->setLayout(lytFilialiDescrizioni);
    lowerRow->addWidget(grpFilialeStatoDescrizione);

    //parte pulsanti
    QVBoxLayout* lytPulsanti = new QVBoxLayout();
    btnAnnulla = new MyButton((toEdit)? "Annulla":"Torna alla Home");
    btnAnnulla->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    btnAnnulla->setFixedWidth(180);
    btnConferma = new MyButton("Conferma");
    btnConferma->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    btnConferma->setFixedWidth(180);
    lytPulsanti->addWidget(btnAnnulla);

    if(toEdit)
        lytPulsanti->addWidget(btnConferma);

    QGroupBox* grpPulsanti = new QGroupBox();
    grpPulsanti->setLayout(lytPulsanti);
    lowerRow->addWidget(grpPulsanti);

    if(!spe)
        connect(btnAnnulla, &QPushButton::clicked, this, &HierachyPageInterface::BackSlot);
    else connect(btnAnnulla, &QPushButton::clicked, this, &HierachyPageInterface::toHomeSlot);

    if(!spe)
        connect(btnConferma, &QPushButton::clicked, this, &HierachyPageInterface::CreaSlot);
    else connect(btnConferma, &QPushButton::clicked, this, &SpedizioneCargoPage::ModificaSlot);

    lytMain->addLayout(lowerRow);
}


void SpedizioneCargoPage::CreaSlot() {
    if( mittente->ConvalidaInput() &
        destinatario->ConvalidaInput() &
        package->ConvalidaInput()){

        if(mittente->getAddress()->getNazione() == "IT" && mittente->getAddress()->getNazione() == destinatario->getAddress()->getNazione()){
            QDialog dialog;
            QLabel *dialogLabel = new QLabel("Attenzione: Non si tratta di una spedizione internazionale! Scegliere le opzioni Spedizione Economica, Premium o Assicurata in base alle esigenze");
            QHBoxLayout *dialogLayout = new QHBoxLayout;
            dialogLayout->addWidget(dialogLabel);
            dialog.setLayout(dialogLayout);
            dialog.exec();
        }else {
            SpedizioneCargo *nuova = new SpedizioneCargo(-1,
                                                         mittente->getAddress(),
                                                         destinatario->getAddress(),
                                                         package->getPackage(),
                                                         new Stato(possibiliStati->currentText().toStdString(),
                                                                   *filiali[possibiliFiliali->currentIndex()]),
                                                         txtDescrizione->toPlainText().toStdString(),
                                                         package->getCheckedBox()
            );
            emit HierachyPageInterface::CreaSignal(nuova);
        }
    }else{
        QDialog dialog;
        QLabel *dialogLabel = new QLabel("Attenzione: tutti i campi devono essere inseriti");
        QHBoxLayout *dialogLayout = new QHBoxLayout;
        dialogLayout->addWidget(dialogLabel);
        dialog.setLayout(dialogLayout);
        dialog.exec();
    }
}

void SpedizioneCargoPage::ModificaSlot() {
    if( mittente->ConvalidaInput() &
        destinatario->ConvalidaInput() &
        package->ConvalidaInput()){

        if(mittente->getAddress()->getNazione() == "IT" && mittente->getAddress()->getNazione() == destinatario->getAddress()->getNazione()){
            QDialog dialog;
            QLabel *dialogLabel = new QLabel("Attenzione: Non si tratta di una spedizione internazionale! Scegliere le opzioni Spedizione Economica, Premium o Assicurata in base alle esigenze");
            QHBoxLayout *dialogLayout = new QHBoxLayout;
            dialogLayout->addWidget(dialogLabel);
            dialog.setLayout(dialogLayout);
            dialog.exec();
        }else
        emit HierachyPageInterface::ModificaSignal(new SpedizioneCargo(obj->getTrakingNumber(),
                                                                                mittente->getAddress(),
                                                                                destinatario->getAddress(),
                                                                                package->getPackage(),
                                                                                new Stato(possibiliStati->currentText().toStdString(),
                                                                                          *filiali[possibiliFiliali->currentIndex()]),
                                                                                txtDescrizione->toPlainText().toStdString(),
                                                                                package->getCheckedBox()
                                                                                ));

    }else{
        QDialog dialog;
        QLabel *dialogLabel = new QLabel("Attenzione: tutti i campi devono essere inseriti");
        QHBoxLayout *dialogLayout = new QHBoxLayout;
        dialogLayout->addWidget(dialogLabel);
        dialog.setLayout(dialogLayout);
        dialog.exec();
    }
}