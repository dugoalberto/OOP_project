//
// Created by Alberto Dugo on 06/05/23.
//
#include "CreaSpedizione.h"

CreaSpedizione::CreaSpedizione(QWidget *parent) : QWidget(parent)
{
    // Aggiungi un layout verticale alla finestra
    auto *layout = new QVBoxLayout(this);

    // Aggiungi una label per descrivere la textbox
    auto *label = new QLabel("Inserisci il tuo nome:", this);
    layout->addWidget(label);

    // Aggiungi la textbox alla finestra
    m_lineEdit = new QLineEdit(this);
    layout->addWidget(m_lineEdit);

    // Imposta il titolo della finestra
    setWindowTitle("Crea Spedizione");
}