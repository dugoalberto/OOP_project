//
// Created by Alberto Dugo on 02/05/23.
//

#ifndef PROJECT_HOME_H
#define PROJECT_HOME_H


#include <QMainWindow>
#include <QVBoxLayout>
#include "myButton.h"
#include "CreaSpedizione.h"
#include "SpedizioniTotali.h"

class Home : public QWidget{
Q_OBJECT
private:
    myButton *spedizioneButton;
    myButton *statoSpedizioneButton;
    myButton *filiere;


public:
    explicit Home(QWidget *parent = nullptr);
    void creaLayout();
    void creaButton();
    myButton* getSpedizioneButton();
    myButton* getstatoSpedizioneButton();
    myButton* getFiliere();
};



#endif //PROJECT_HOME_H
