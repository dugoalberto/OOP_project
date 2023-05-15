//
// Created by utente on 12/05/2023.
//

#ifndef DUGO_PROGETTO_SELEZIONETIPOPAGE_H
#define DUGO_PROGETTO_SELEZIONETIPOPAGE_H


#include <QWidget>
#include "../CustomWidgets/MyButton.h"
#include "HierachyPages/HierachyPageInterface.h"

class SelezioneTipoPage : public QWidget {
    Q_OBJECT
private:
    template <class T>
    void loadView(std::vector<T> &lst, QListWidget *wiew) const;
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
signals:
    void backSignal();
    void EconomicaSignal(HierachyPageInterface*);
    void PremiumSignal(HierachyPageInterface*);
    void CargoSignal(HierachyPageInterface*);
    void InternazionaleSignal(HierachyPageInterface*);
    void AssicurataSignal(HierachyPageInterface*);
};


#endif //DUGO_PROGETTO_SELEZIONETIPOPAGE_H