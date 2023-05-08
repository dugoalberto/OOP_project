//
// Created by Alberto Dugo on 02/05/23.
//

#ifndef PROJECT_HOME_H
#define PROJECT_HOME_H


#include <QMainWindow>
#include <QVBoxLayout>
#include "../widgets/myButton.h"
#include "../widgets/CreaSpedizione.h"
#include "../widgets/SpedizioniTotali.h"

class Home : public QMainWindow{
Q_OBJECT
private:
    myButton *spedizioneButton;
    myButton *statoSpedizioneButton;
    myButton *filiere;
    myButton *backHomeButton;

    CreaSpedizione *creaSpedizioneWidget;
    SpedizioniTotali *spedizioniTotali;


public:
    explicit Home(QMainWindow *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    void creaLayout();
    void creaButton();

    //widgets
    void SpedizioneWidget();
    void SpedizioniTotaliWidget();


    private slots:
        void onSpedizioneButtonClicked();
        void onSpedizioniTotaliClicked();

};



#endif //PROJECT_HOME_H
