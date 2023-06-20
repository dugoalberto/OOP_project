//
// Created by Alberto Dugo on 12/05/2023.
//

#ifndef DUGO_PROGETTO_PACKAGEWIDGETASSICURATA_H
#define DUGO_PROGETTO_PACKAGEWIDGETASSICURATA_H


#include <QCheckBox>
#include "PackageWidgetBase.h"
#include "../../../../Model/SupportClasses/Assicurazione.h"
#include "../../../../Collection/ArrayList.h"
#include "../AddressWidget.h"

class PackageWidgetAssicurata : public PackageWidgetBase{
private:
    Assicurazione* assicurazione;
    QCheckBox *checkBoxs[3];
    std::vector<Assicurazione*> lstAssicurazioni;
    QComboBox* cmbAssicurazioniPossibili;
    QLineEdit* txtCostoPerServizio;
    std::vector<std::string>* alreadyCheckedService;
public:
    PackageWidgetAssicurata(Package* = nullptr, Assicurazione* = nullptr, std::vector<std::string>* = nullptr,bool toEdit = false, QWidget* = nullptr);
    float addedCost() const;
    Assicurazione* getAssicurazione();
    bool ConvalidaInput() const override;
    float PrezzoTotaleAssicurazione() const;
    std::vector<std::string>* getServiziSelezionati() const;
public slots:
    void AssicurazioneChosenChangedSlot();
    void checkBoxSelectedSlot();
};


#endif //DUGO_PROGETTO_PACKAGEWIDGETASSICURATA_H
