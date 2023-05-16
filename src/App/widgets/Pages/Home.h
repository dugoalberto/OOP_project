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
#include "../CustomWidgets/MyButton.h"
#include "../../../Model/hierarchy/Spedizione.h"
#include "../../../Collection/ArrayList.h"
//#include "CreaSpedizione.h"
//#include "SpedizioniTotali.h"

class Home : public QWidget{
Q_OBJECT
private:
    MyButton *spedizioneButton;
    MyButton *statoSpedizioneButton;
    MyButton *filiere;

    ArrayList<Spedizione*> lstElements;
public:
    explicit Home(ArrayList<Spedizione*>&, QWidget *parent = nullptr);

    QLineEdit* txtSearchBar;
    MyButton* btnOrderButton;
    MyButton* btnNewSpedizione;
    QListWidget* lstSpedizioni;
    QCheckBox* CbTypesArray[5];
    QCheckBox* CbStatoArray[5];

    MyButton *getSpedizioneButton();
    MyButton *getstatoSpedizioneButton();
    MyButton *getFiliere();

    void loadListView();
    int SearchSpedizioneById(int id);
public
slots:
    void FilterSelectedSlot();
    void SearchbarModifiedSlot();
    void AddNewSpedizioneSlot(Spedizione*);
};



#endif //PROJECT_HOME_H
