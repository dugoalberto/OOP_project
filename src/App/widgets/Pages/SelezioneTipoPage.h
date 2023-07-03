//
// Created by Alberto Dugo on 12/05/2023.
//

#ifndef DUGO_PROGETTO_SELEZIONETIPOPAGE_H
#define DUGO_PROGETTO_SELEZIONETIPOPAGE_H


#include <QWidget>
#include <QListWidget>
#include <QGroupBox>
#include "../CustomWidgets/MyButton.h"
#include "HierachyPages/HierachyPageInterface.h"
#include "../CustomWidgets/QLabelTitle.h"
#include "../../../Model/SupportClasses/Filiale.h"
#include "../../../Librerie/FileManagerJSON.h"
#include "../CustomWidgets/ListViewItemCustomWidget/ListViewFilialeItemWidget.h"
#include "../CustomWidgets/ListViewItemCustomWidget/ListViewAssicurazioneItemWidget.h"
#include "HierachyPages/SpedizioneAssicurataPage.h"
#include "HierachyPages/SpedizionePremiumPage.h"
#include "HierachyPages/SpedizioneCargoPage.h"
#include "HierachyPages/SpedizioneEconomicaPage.h"

class SelezioneTipoPage : public QWidget {
    Q_OBJECT
private:
    std::vector<Filiale*> lstFiliali;
    QListWidget* viewFiliali;
    std::vector<Assicurazione*> lstAssicurazioni;
    QListWidget* viewAssicurazioni;
    void loadAssicurazioni() const;
    void loadFiliali();
public:
    SelezioneTipoPage(QWidget* parent = nullptr);
public
slots:
    void btnBackSlot();
    void btnEconomicaPressedSlot();
    void btnPremiumPressedSlot();
    void btnCargoPressedSlot();
    void btnInternazionalePressedSlot();
    void btnAssicurataPressedSlot();
    void btnAddFilialePressedSlot();
    void btnAddAssicurazioneSlot();

    void VisualizzaFilialeSlot(Filiale* f);
    void ModificaFilialeSlot(Filiale* f);
    void AggiungiFilialeSlot(Filiale *f);
    void EliminaFilialeSlot(Filiale* f);

    void VisualizzaAssicurazioneSlot(Assicurazione* a);
    void AggiungiAssicurazioneSlot(Assicurazione *a);
    void ModificaAssicurazioneSlot(Assicurazione *a);
    void EliminaAssicurazioneSlot(Assicurazione *a);

    void reloadFilialiSlot();
    void reloadAssicurazioneSlot();
signals:
    void backSignal();
    void EconomicaSignal(HierachyPageInterface*);
    void PremiumSignal(HierachyPageInterface*);
    void CargoSignal(HierachyPageInterface*);
    void InternazionaleSignal(HierachyPageInterface*);
    void AssicurataSignal(HierachyPageInterface*);
};


#endif //DUGO_PROGETTO_SELEZIONETIPOPAGE_H
