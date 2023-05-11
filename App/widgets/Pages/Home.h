//
// Created by Alberto Dugo on 02/05/23.
//

#ifndef PROJECT_HOME_H
#define PROJECT_HOME_H


#include <QMainWindow>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QListWidget>
#include <QListWidgetItem>
#include "../CustomWidgets/myButton.h"
#include "../../../Model/hierarchy/Spedizione.h"
#include "../../../Collection/ArrayList.h"
//#include "CreaSpedizione.h"
//#include "SpedizioniTotali.h"

class Home : public QWidget{
Q_OBJECT
private:
    myButton *spedizioneButton;
    myButton *statoSpedizioneButton;
    myButton *filiere;

    ArrayList<Spedizione*> lstElements;
public:
    explicit Home(ArrayList<Spedizione*>&, QWidget *parent = nullptr);

    QLineEdit* txtSearchBar;
    myButton* btnOrderButton;
    myButton* btnNewSpedizione;
    QListWidget* lstSpedizioni;
    QCheckBox* CbTypesArray[5];
    QCheckBox* CbStatoArray[5];

    myButton *getSpedizioneButton();
    myButton *getstatoSpedizioneButton();
    myButton *getFiliere();

    void loadListView();
public
slots:
    void FilterSelectedSlot();
    void SearchbarModifiedSlot();
};



#endif //PROJECT_HOME_H
