//
// Created by Alberto Dugo on 08/05/23.
//

#ifndef PROJECT_STACKTRACER_H
#define PROJECT_STACKTRACER_H


#include <QStackedWidget>
#include "Pages/Home.h"
#include "Pages/HierachyPages/SpedizioneAssicurataPage.h"
#include "Pages/SelezioneTipoPage.h"
#include "../../Librerie/FileManagerJSON.h"

class StackTracer : public QStackedWidget{
private:
    Home *homePage;
    SelezioneTipoPage* selezioneTipoPage;

    ArrayList<Spedizione*>* lstElements;
    FileManagerJSON* fm;

public:
    explicit StackTracer(QWidget *parent = nullptr) : QStackedWidget(parent) {
            fm = new FileManagerJSON("JSON_SAVE");
            lstElements = new ArrayList<Spedizione*>(fm->readSpedizioni());

            homePage = new Home(fm, lstElements, this);
            selezioneTipoPage = new SelezioneTipoPage();

            addWidget(homePage);
            addWidget(selezioneTipoPage);


            connect(homePage->getSpedizioneButton(), &QPushButton::clicked, this, &StackTracer::switchToSelezioneTipoPage);
            connect(homePage, &Home::SaveOnFileSignal, this, &StackTracer::switchToSelezioneTipoPage);
            connect(selezioneTipoPage, &SelezioneTipoPage::backSignal, this, &StackTracer::switchToHomePage);
            connect(selezioneTipoPage, &SelezioneTipoPage::AssicurataSignal, this, &StackTracer::switchToSelectedCreatingPage);
            connect(selezioneTipoPage, &SelezioneTipoPage::PremiumSignal, this, &StackTracer::switchToSelectedCreatingPage);
            connect(selezioneTipoPage, &SelezioneTipoPage::InternazionaleSignal, this, &StackTracer::switchToSelectedCreatingPage);
            connect(selezioneTipoPage, &SelezioneTipoPage::CargoSignal, this, &StackTracer::switchToSelectedCreatingPage);
            connect(selezioneTipoPage, &SelezioneTipoPage::EconomicaSignal, this, &StackTracer::switchToSelectedCreatingPage);
            connect(homePage, &Home::VisualizzaSpedizioneSignal, this, &StackTracer::switchToSelectedCreatingPage);
            connect(homePage, &Home::ModificaSpedizioneSignal, this, &StackTracer::switchToSelectedCreatingPage);
    }
public slots:
    void switchToHomePage() {
        setCurrentWidget(homePage);
    }
    void switchToSelezioneTipoPage() {
        setCurrentWidget(selezioneTipoPage);
    }
    void switchToSelectedCreatingPage(HierachyPageInterface* nuovaPagina){
        addWidget(nuovaPagina);
        connect(nuovaPagina, &HierachyPageInterface::BackSignal, this, &StackTracer::switchToSelezioneTipoPage);
        connect(nuovaPagina, &HierachyPageInterface::CreaSignal, this, &StackTracer::addNewSpedizioneSlot);
        connect(nuovaPagina, &HierachyPageInterface::ModificaSignal, this, &StackTracer::ModificaSpedizioneSlot);
        connect(nuovaPagina, &HierachyPageInterface::toHomeSignal, this, &StackTracer::switchToHomePage);
        setCurrentWidget(nuovaPagina);
    }
    void addNewSpedizioneSlot(Spedizione* spedizione) {
        homePage->AddNewSpedizioneSlot(spedizione);
        homePage->loadListView();
        switchToHomePage();
    }
    void ModificaSpedizioneSlot(Spedizione* spedizione){
        homePage->ModificaSpedizioneAggiornataSlot(spedizione);
        homePage->loadListView();
        switchToHomePage();
    }
};


#endif //PROJECT_STACKTRACER_H
