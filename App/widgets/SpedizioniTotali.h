//
// Created by Alberto Dugo on 06/05/23.
//

#ifndef PROJECT_SPEDIZIONITOTALI_H
#define PROJECT_SPEDIZIONITOTALI_H

#include <Qt>
#include <QLineEdit>
#include "myButton.h"
#include "../../Collection/ArrayList.h"
#include "../../Model/Spedizione.h"
#include "SpedizioneWidget.h"
#include <QDialog>
#include <QLabel>
class SpedizioniTotali  : public QWidget{
    Q_OBJECT
private:
    //ArrayList<SpedizionePremium> spedizioniTot;
    myButton *backHomeButton;
public:
    explicit SpedizioniTotali(QWidget *parent = nullptr);
    myButton* getHomePageButton();
};



#endif //PROJECT_SPEDIZIONITOTALI_H
