//
// Created by utente on 12/05/2023.
//

#include <QComboBox>
#include <QTextLine>
#include "PackageWidgetAssicurata.h"
#include "../../../../Librerie/FileManager.h"

PackageWidgetAssicurata::PackageWidgetAssicurata(Package *pkg, Assicurazione* ass, std::vector<std::string>* vec, bool toEdit, QWidget *parent) : PackageWidgetBase(pkg, toEdit, parent), assicurazione(ass), alreadyCheckedService(vec){
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
    cmbAssicurazioniPossibili->setEnabled(toEdit);

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
        connect(checkBoxs[i], &QCheckBox::stateChanged, this, &PackageWidgetAssicurata::checkBoxSelectedSlot);
        checkBoxs[i]->setEnabled(toEdit);
    }

    if(alreadyCheckedService){
        for(int i = 0; i < 3; i++){
            for(auto it = alreadyCheckedService->begin(); it != alreadyCheckedService->end(); ++it)
                if((*it) == checkBoxs[i]->text().toStdString())
                    checkBoxs[i]->setCheckState(Qt::Checked);
        }
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

Assicurazione* PackageWidgetAssicurata::getAssicurazione() {
    if(assicurazione)
        return assicurazione;
    else return &lstAssicurazioni[cmbAssicurazioniPossibili->currentIndex()];
}

void PackageWidgetAssicurata::AssicurazioneChosenChangedSlot() {
    txtCostoPerServizio->setText(QString::number(lstAssicurazioni[cmbAssicurazioniPossibili->currentIndex()].getPrezzo(), 'f', 2));
}

float PackageWidgetAssicurata::PrezzoTotaleAssicurazione() const {
    int tot = 0;
    for(int i = 0; i < 3; i++)
        if(checkBoxs[i]->isChecked())
            tot+=assicurazione->getPrezzo();
    return tot;
}

std::vector<std::string>* PackageWidgetAssicurata::getServiziSelezionati() const {
    std::vector<std::string>* res = new std::vector<std::string>();
    for(int i = 0; i < 3; i++)
        if(checkBoxs[i]->isChecked()) res->push_back(checkBoxs[i]->text().toStdString());
    return res;
}

bool PackageWidgetAssicurata::ConvalidaInput() const {
    int numeroSelezionate = getServiziSelezionati()->size();
    if(numeroSelezionate == 0)
        for(int i = 0; i <3; i++)
            checkBoxs[i]->setStyleSheet("QCheckBox::indicator{ border: 2px solid red; }");
    return PackageWidgetBase::ConvalidaInput() && numeroSelezionate > 0;
}

void PackageWidgetAssicurata::checkBoxSelectedSlot() {
    for(int i = 0; i < 3; i++)
        checkBoxs[i]->setStyleSheet("QCheckBox::indicator::unchecked{"
                                    "    border: 2px solid #2B2E3B;"
                                    "    background-color: #384354;"
                                    "}");
}
