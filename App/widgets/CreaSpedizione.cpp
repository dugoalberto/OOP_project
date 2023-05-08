//
// Created by Alberto Dugo on 06/05/23.
//
#include "CreaSpedizione.h"

CreaSpedizione::CreaSpedizione(QWidget *parent) : QWidget(parent)
{
    // Aggiungi un layout verticale alla finestra
    auto *layout = new QGridLayout(this);

    // Aggiungi una label per descrivere la textbox
    auto *label = new QLabel("Inserisci il tuo nome:", this);
    layout->addWidget(label);

    // Aggiungi la textbox alla finestra
    m_lineEdit = new QLineEdit(this);
    layout->addWidget(m_lineEdit);

    backHomeButtone = new myButton(nullptr, QSize(50,50), QString("back_home_btn"), QString("back"));
    auto *topLeftWidget = new QWidget(this);
    auto *topLeftLayout = new QHBoxLayout();
    topLeftLayout->addWidget(backHomeButtone);
    topLeftWidget->setLayout(topLeftLayout);
    layout->addWidget(topLeftWidget, 0, 0, Qt::AlignTop|Qt::AlignLeft);
    topLeftWidget->setVisible(true);
    connect(backHomeButtone, &myButton::clicked, this, &CreaSpedizione::backToHomeClicked);

    // Imposta il titolo della finestra
    setWindowTitle("Crea Spedizione");
}
void CreaSpedizione::backToHomeClicked() {
    //ritorniamo alla homepage
    backHomeButtone->setVisible(false);
}