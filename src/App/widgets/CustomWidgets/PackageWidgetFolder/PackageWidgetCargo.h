//
// Created by Alberto Dugo on 12/05/2023.
//

#ifndef DUGO_PROGETTO_PACKAGEWIDGETCARGO_H
#define DUGO_PROGETTO_PACKAGEWIDGETCARGO_H


#include <QCheckBox>
#include "PackageWidgetBase.h"
#include "../../../../Model/hierarchy/SpedizioneCargo.h"

class PackageWidgetCargo : public PackageWidgetBase{
private:
    QCheckBox *checkBoxs[2];
public:
    PackageWidgetCargo(Package* = nullptr,const std::string& = "", bool toEdit = false, QWidget* parent = nullptr);
    SpedizioneCargo::TipologiaTrasporto getCheckedBox() const;

public
    slots:
    void CheckBoxPressedSlot();
};


#endif //DUGO_PROGETTO_PACKAGEWIDGETCARGO_H
