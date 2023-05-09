//
// Created by Alberto Dugo on 02/05/23.
//

#include <QLabel>
#include <QtWidgets>
#include <QMainWindow>
#include "Home.h"
#include "StackTracer.h"

Home::Home(QWidget *parents) : QWidget(parents){
    creaButton();
    creaLayout();

    //connect(spedizioneButton, &QPushButton::clicked, this, &StackTracer::switchToCreaSpedizionePage);

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
    // Widget centrale
    auto *centralWidget = new QWidget(this);
    auto *layout1 = new QGridLayout(centralWidget);
    centralWidget->setLayout(layout1);

    // Widget di contenimento per il widget centrale
    auto *wrapperWidget = new QWidget(this);
    auto *wrapperLayout = new QVBoxLayout(wrapperWidget);
    wrapperLayout->addWidget(centralWidget);

    // Layout verticale principale
    auto *layout2 = new QVBoxLayout(this);
    layout2->addWidget(wrapperWidget);

    // SPEDIZIONI BUTTON
    auto *leftWidget = new QWidget(this);
    auto *layoutL = new QHBoxLayout(leftWidget);
    layoutL->addWidget(spedizioneButton);
    layout1->addWidget(leftWidget, 0, 0, Qt::AlignCenter);

    // STATO SPEDIZIONI
    auto *rightWidget = new QWidget(this);
    auto *layoutR = new QHBoxLayout(rightWidget);
    layoutR->addWidget(statoSpedizioneButton);
    layout1->addWidget(rightWidget, 0, 1, Qt::AlignCenter);

    // FILIERE
    auto *topWidget = new QWidget(this);
    auto *topLayout = new QHBoxLayout();  // Layout orizzontale per il layout in alto
    topLayout->addWidget(filiere);
    topWidget->setLayout(topLayout);
    layout1->addWidget(topWidget, 0, 0, 1, 3 , Qt::AlignTop | Qt::AlignRight); // Aggiungi il layout in alto al layout del widget centrale

    // Imposta il layout principale
    setLayout(layout2);
}

myButton* Home::getSpedizioneButton() {
    return spedizioneButton;
}

myButton *Home::getstatoSpedizioneButton() {
    return statoSpedizioneButton;
}

myButton *Home::getFiliere() {
    return filiere;
}
