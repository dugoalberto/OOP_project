//
// Created by Alberto Dugo on 08/05/23.
//

#ifndef PROJECT_STACKTRACER_H
#define PROJECT_STACKTRACER_H


#include <QStackedWidget>
//#include "Pages/CreaSpedizione.h"
#include "Pages/Home.h"
//#include "Pages/Filiali.h"

class StackTracer : public QStackedWidget{
private:
    Home *homePage;
    ArrayList<Spedizione*> lstSpedizioni;
    //CreaSpedizione *creaSpedizionePage;
    //SpedizioniTotali *spedizioniTotali;
    //Filiali *filiali;
public:
    explicit StackTracer(ArrayList<Spedizione*> lstS, QWidget *parent = nullptr) : QStackedWidget(parent), lstSpedizioni(lstS) {
            homePage = new Home(lstSpedizioni, this);
            //creaSpedizionePage = new CreaSpedizione(this);
            //spedizioniTotali = new SpedizioniTotali(this);
            //filiali = new Filiali(this);

            addWidget(homePage);
            //addWidget(creaSpedizionePage);
            //addWidget(spedizioniTotali);
            //addWidget(filiali);

/*
            connect(homePage->getSpedizioneButton(), &QPushButton::clicked, this, &StackTracer::switchToCreaSpedizionePage);
            connect(homePage->getstatoSpedizioneButton(), &QPushButton::clicked, this, &StackTracer::switchToSpedizioniTotali);
            connect(homePage->getFiliere(), &QPushButton::clicked, this, &StackTracer::switchToFiliali);
*/


        //backButton x tutti
        /*
            connect(creaSpedizionePage->getHomePageButton(), &QPushButton::clicked, this, &StackTracer::switchToHomePage);
            connect(spedizioniTotali->getHomePageButton(), &QPushButton::clicked, this, &StackTracer::switchToHomePage);
            connect(filiali->getHomePageButton(), &QPushButton::clicked, this, &StackTracer::switchToHomePage);*/



    }
public slots:
    void switchToHomePage() {
        setCurrentWidget(homePage);
    }/*
    void switchToCreaSpedizionePage() {
        setCurrentWidget(creaSpedizionePage);
    }
    void switchToSpedizioniTotali() {
        setCurrentWidget(spedizioniTotali);
    }
    void switchToFiliali() {
        setCurrentWidget(filiali);
    }*/
};


#endif //PROJECT_STACKTRACER_H
