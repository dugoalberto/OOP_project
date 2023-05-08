//
// Created by Alberto Dugo on 02/05/23.
//

#include <QLabel>
#include "Home.h"
#include "../widgets/CreaSpedizione.h"

Home::Home(QMainWindow *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags){
    creaButton();
    creaLayout();
    //spedizione
    SpedizioneWidget();
    connect(spedizioneButton, &myButton::clicked, this, &Home::onSpedizioneButtonClicked);

    //visualizza spedizioni
    SpedizioneWidget();
    connect(statoSpedizioneButton, &myButton::clicked, this, &Home::onSpedizioniTotaliClicked);





}
//HOME
void Home::creaButton(){
    spedizioneButton = new myButton(nullptr, QSize(200,100), QString("spedizone_bottone_HomePage"), QString("Spedizione"));
    spedizioneButton->setToolTip("nuova Spedizione");

    statoSpedizioneButton = new myButton(nullptr, QSize(200,100), QString("stato_spedizone_bottone_HomePage"), QString("stato Spedizione"));
    statoSpedizioneButton->setToolTip("visualizza lo stato di una particolare spedizione");

    filiere = new myButton(nullptr, QSize(200,100), QString("filiere_bottone_HomePage"), QString("filiere"));
    filiere->setToolTip("visualizza tutte le filiere");
}
void Home::creaLayout() {
    auto *centralWidget = new QWidget(this);
    auto *layout = new QGridLayout(centralWidget);
    setCentralWidget(centralWidget);
    // SPEDIIZIONI BUTTON
    auto *leftWidget = new QWidget(this);
    auto *layoutL = new QHBoxLayout(leftWidget);
    layoutL->addWidget(spedizioneButton);
    layout->addWidget(leftWidget, 0, 0, Qt::AlignCenter);
    //STATO SPEDIIZIONI
    auto *rightWidget = new QWidget(this);
    auto *layoutR = new QHBoxLayout(rightWidget);
    layoutR->addWidget(statoSpedizioneButton);
    layout->addWidget(rightWidget, 0, 1, Qt::AlignCenter);
    //FILIERE
    auto *topWidget = new QWidget(this);
    auto *topLayout = new QHBoxLayout();  // Layout orizzontale per il layout in alto
    topLayout->addWidget(filiere);
    topWidget->setLayout(topLayout);
    layout->addWidget(topWidget, 0, 0, 1, 3 , Qt::AlignTop | Qt::AlignRight); // Aggiungi il layout in alto al layout verticale principale
    //BACK BUTTON
    /*
    auto *topLeftWidget = new QWidget(this);
    auto *topLeftLayout = new QHBoxLayout();
    topLeftLayout->addWidget(backHomeButtone);
    topLeftWidget->setLayout(topLeftLayout);
    layout->addWidget(topLeftWidget, 0, 0, Qt::AlignTop | Qt::AlignLeft);
    topLeftWidget->setVisible(false);*/

}

//spedizione
void Home::SpedizioneWidget(){
    creaSpedizioneWidget = new CreaSpedizione(this);
    creaSpedizioneWidget->setFixedSize(400, 400);
    creaSpedizioneWidget->setHidden(true);
}

//visualiza spedizioni
void Home::SpedizioniTotaliWidget(){
    spedizioniTotali = new SpedizioniTotali(this);
    spedizioniTotali->setFixedSize(400, 400);
    spedizioniTotali->setHidden(true);
}

//Filiali
//TODO

//bottoneback
//dato che è associato alla finestra home, dovresti creare un widget



//slots
void Home::onSpedizioneButtonClicked() {
    spedizioneButton->setVisible(false);
    centralWidget()->setVisible(false);
    creaSpedizioneWidget->setVisible(true);
}
void Home::onSpedizioniTotaliClicked() {
    statoSpedizioneButton->setHidden(true);
    centralWidget()->setHidden(true);
    statoSpedizioneButton->setHidden(false);
}