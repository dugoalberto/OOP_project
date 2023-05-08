//
// Created by Alberto Dugo on 06/05/23.
//

#include "SpedizioniTotali.h"

SpedizioniTotali::SpedizioniTotali(QWidget *parent): QWidget(parent) {

    // Aggiungi un layout verticale alla finestra
    auto *layout = new QGridLayout(this);

    // Aggiungi una label per descrivere la textbox
    auto *label = new QLabel("Inserisci il tuo nome:", this);
    layout->addWidget(label);

    // Aggiungi la textbox alla finestra
    m_lineEdit = new QLineEdit(this);
    layout->addWidget(m_lineEdit);

    backHomeButton = new myButton(nullptr, QSize(50,50), QString("back_home_btn"), QString("back"));
    auto *topLeftWidget = new QWidget(this);
    auto *topLeftLayout = new QHBoxLayout();
    topLeftLayout->addWidget(backHomeButton);
    topLeftWidget->setLayout(topLeftLayout);
    layout->addWidget(topLeftWidget, 0, 0, Qt::AlignTop|Qt::AlignLeft);
    topLeftWidget->setVisible(true);

    // Imposta il titolo della finestra
    setWindowTitle("Crea Spedizione");
}
myButton *SpedizioniTotali::getHomePageButton() {
    return backHomeButton;
}
