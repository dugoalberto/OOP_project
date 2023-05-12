//
// Created by utente on 12/05/2023.
//

#include "PackageWidgetCargo.h"
PackageWidgetCargo::PackageWidgetCargo(Package *pkg, bool toEdit, QWidget *parent) : PackageWidgetBase(pkg, toEdit, parent){

    QHBoxLayout* thirdRow = new QHBoxLayout();

    std::string tipologie[2] = {"Aereo","Barca"};
    for(int i = 0; i < 2; i++){
        checkBoxs[i] = new QCheckBox(QString::fromStdString(tipologie[i]));
        thirdRow->addWidget(checkBoxs[i]);
    }
    thirdRow->setAlignment(Qt::AlignCenter);
    mainLyt->addLayout(thirdRow);
}

void PackageWidgetCargo::CheckBoxPressedSlot() {
    std::string clickedCheckBox = qobject_cast<QCheckBox*>(sender())->text().toStdString();
    for(int i = 0; i < 2; i++)
        if(checkBoxs[i]->text().toStdString() != clickedCheckBox)
            checkBoxs[i]->setCheckState(Qt::Unchecked);
}

SpedizioneCargo::TipologiaTrasporto PackageWidgetCargo::getCheckedBox() const {
    for(int i = 0; i < 2; i++){
        if(checkBoxs[i]->isChecked()){
            return (checkBoxs[i]->text().toUpper().toStdString() == "AEREO")? SpedizioneCargo::TipologiaTrasporto::AEREO : SpedizioneCargo::TipologiaTrasporto::BARCA;
        }
    }

    return SpedizioneCargo::TipologiaTrasporto::AEREO;
}
