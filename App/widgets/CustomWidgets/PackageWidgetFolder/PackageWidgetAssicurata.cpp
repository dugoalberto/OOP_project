//
// Created by utente on 12/05/2023.
//

#include <QComboBox>
#include <QTextLine>
#include "PackageWidgetAssicurata.h"
#include "../../../../Librerie/FileManager.h"

PackageWidgetAssicurata::PackageWidgetAssicurata(Package *pkg, bool toEdit, QWidget *parent) : PackageWidgetBase(pkg, toEdit, parent){
    QHBoxLayout* thirdRow = new QHBoxLayout();

    //PARTE SINISTRA
    mainLyt->addSpacing(35);
    QVBoxLayout* lytComboBoxAssicurazioni = new QVBoxLayout();
    lytComboBoxAssicurazioni->setAlignment(Qt::AlignCenter);
    cmbAssicurazioniPossibili = new QComboBox();

    lstAssicurazioni = FileManager::readAssicurazioni();
    for(auto it = lstAssicurazioni.begin(); it != lstAssicurazioni.end(); ++it)
        cmbAssicurazioniPossibili->addItem(QString::fromStdString((*it).getNomeAssicurazione()));
    cmbAssicurazioniPossibili->setCurrentIndex(0);

    txtCostoPerServizio = new QLineEdit();
    txtCostoPerServizio->setReadOnly(true);
    txtCostoPerServizio->setText(QString::number(lstAssicurazioni[cmbAssicurazioniPossibili->currentIndex()].getPrezzo(),'f',2));

    lytComboBoxAssicurazioni->addWidget(new QLabel("Assicurazioni:"));
    lytComboBoxAssicurazioni->addWidget(cmbAssicurazioniPossibili);
    lytComboBoxAssicurazioni->addSpacing(20);
    lytComboBoxAssicurazioni->addWidget(new QLabel("Prezzo per singolo servizio:"));
    lytComboBoxAssicurazioni->addWidget(txtCostoPerServizio);

    connect(cmbAssicurazioniPossibili, &QComboBox::currentIndexChanged, this, &PackageWidgetAssicurata::AssicurazioneChosenChangedSlot);

    //PARTE DESTRA
    QVBoxLayout* lytScelte = new QVBoxLayout();
    lytScelte->setAlignment(Qt::AlignCenter);
    lytScelte->addWidget(new QLabel("Servizi Presenti:"));
    std::string sceltePossibili[3] = {"Furto", "Perdita", "Danni"};
    for(int i = 0; i < 3; i++){
        checkBoxs[i] = new QCheckBox(QString::fromStdString(sceltePossibili[i]));
        lytScelte->addWidget(checkBoxs[i]);
    }

    thirdRow->addLayout(lytComboBoxAssicurazioni);
    thirdRow->addLayout(lytScelte);
    mainLyt->addLayout(thirdRow);
}

float PackageWidgetAssicurata::addedCost() const {
    int totServizi = 0;
    for(int i = 0; i < 3; i++){
        if(checkBoxs[i]->isChecked())
            totServizi++;
    }

    return totServizi*assicurazione->getPrezzo();
}

Assicurazione* PackageWidgetAssicurata::getAssicurazione() const {
    return assicurazione;
}

void PackageWidgetAssicurata::AssicurazioneChosenChangedSlot() {
    txtCostoPerServizio->setText(QString::number(lstAssicurazioni[cmbAssicurazioniPossibili->currentIndex()].getPrezzo(), 'f', 2));
}