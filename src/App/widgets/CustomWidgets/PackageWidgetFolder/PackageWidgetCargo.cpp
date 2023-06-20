//
// Created by Alberto Dugo on 12/05/2023.
//

#include "PackageWidgetCargo.h"
#include <iostream>
PackageWidgetCargo::PackageWidgetCargo(Package *pkg, const std::string& tipo, bool toEdit, QWidget *parent) : PackageWidgetBase(pkg, toEdit, parent){

    QHBoxLayout* thirdRow = new QHBoxLayout();
    thirdRow->addWidget(new QLabel("Modalità di trasporto:"));
    thirdRow->setAlignment(Qt::AlignCenter);

    QHBoxLayout* fourthRow = new QHBoxLayout();
    std::string tipologie[2] = {"Aereo","Barca"};
    for(int i = 0; i < 2; i++){
        checkBoxs[i] = new QCheckBox(QString::fromStdString(tipologie[i]));
        if(tipologie[i] == tipo)
            checkBoxs[i]->setCheckState(Qt::Checked);
        fourthRow->addWidget(checkBoxs[i]);
        connect(checkBoxs[i], &QCheckBox::clicked, this, &PackageWidgetCargo::CheckBoxPressedSlot);
    }
    fourthRow->setAlignment(Qt::AlignCenter);
    mainLyt->addSpacing(20);
    mainLyt->addLayout(thirdRow);
    mainLyt->addLayout(fourthRow);
}

void PackageWidgetCargo::CheckBoxPressedSlot() {
    std::string clickedCheckBox = qobject_cast<QCheckBox*>(sender())->text().toStdString();
    for(int i = 0; i < 2; i++) {
        if (checkBoxs[i] != qobject_cast<QCheckBox*>(sender()))
            checkBoxs[i]->setChecked(false);
    }
}

SpedizioneCargo::TipologiaTrasporto PackageWidgetCargo::getCheckedBox() const {
    for(int i = 0; i < 2; i++){
        if(checkBoxs[i]->isChecked()){
            return (checkBoxs[i]->text().toUpper().toStdString() == "AEREO")? SpedizioneCargo::TipologiaTrasporto::AEREO : SpedizioneCargo::TipologiaTrasporto::BARCA;
        }
    }

    return SpedizioneCargo::TipologiaTrasporto::AEREO;
}
