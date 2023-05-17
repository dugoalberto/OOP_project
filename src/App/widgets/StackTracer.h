//
// Created by Alberto Dugo on 08/05/23.
//

#ifndef PROJECT_STACKTRACER_H
#define PROJECT_STACKTRACER_H


#include <QStackedWidget>
#include "Pages/Home.h"
#include "Pages/HierachyPages/SpedizioneAssicurataPage.h"
#include "Pages/SelezioneTipoPage.h"
#include "../../Librerie/FileManager.h"

class StackTracer : public QStackedWidget{
private:
    Home *homePage;
    SelezioneTipoPage* selezioneTipoPage;
public:
    explicit StackTracer(QWidget *parent = nullptr) : QStackedWidget(parent) {
            homePage = new Home(this);
            selezioneTipoPage = new SelezioneTipoPage();

            addWidget(homePage);
            addWidget(selezioneTipoPage);


            connect(homePage->getSpedizioneButton(), &QPushButton::clicked, this, &StackTracer::switchToSelezioneTipoPage);
            connect(homePage, &Home::SaveOnFileSignal, this, &StackTracer::switchToSelezioneTipoPage);
            connect(selezioneTipoPage, &SelezioneTipoPage::backSignal, this, &StackTracer::switchToHomePage);
            connect(selezioneTipoPage, &SelezioneTipoPage::AssicurataSignal, this, &StackTracer::switchToSelectedCreatingPage);
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
        //TODO FARLO ANCHE PER L'ALTRO PULSANTE DENTRO LE SCHERMATE
        setCurrentWidget(nuovaPagina);
    }
    void addNewSpedizioneSlot(Spedizione* spedizione){
        cout << "Nuova spedizione arrivata e aggiunta" << endl;
        homePage->AddNewSpedizioneSlot(spedizione);
        homePage->loadListView();
        switchToHomePage();
    }
    /*
    void switchToSpedizioniTotali() {
        setCurrentWidget(spedizioniTotali);
    }
    void switchToFiliali() {
        setCurrentWidget(filiali);
    }*/
};


#endif //PROJECT_STACKTRACER_H
