//
// Created by Alberto Dugo on 02/05/23.
//

#ifndef PROJECT_HOME_H
#define PROJECT_HOME_H

#include <QVBoxLayout>
#include <QCheckBox>
#include <QListWidget>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QGroupBox>
#include "../CustomWidgets/MyButton.h"
#include "../CustomWidgets/QLabelTitle.h"
#include "../../../Model/hierarchy/Spedizione.h"
#include "../../../Collection/ArrayList.h"
#include "../../../Librerie/FileManagerJSON.h"
#include "../CustomWidgets/ListViewItemCustomWidget/ListViewSpedizioniItemWidget.h"

class Home : public QWidget{
Q_OBJECT
private:
    MyButton *spedizioneButton;
    MyButton *statoSpedizioneButton;
    MyButton *filiere;

    FileManagerJSON* fm;
    ArrayList<Spedizione*>* lstElements;
public:
    explicit Home(FileManagerJSON *file, ArrayList<Spedizione *>* lst, QWidget *parent = nullptr);

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
public
slots:
    void FilterSelectedSlot();
    void SearchbarModifiedSlot();
    void AddNewSpedizioneSlot(Spedizione*);
    void VisualizzaSpedizioneSlot(const Spedizione*);
    void ModificaSpedizioneSlot(const Spedizione*);
    void ModificaSpedizioneAggiornataSlot(Spedizione *spedizione);
    void EliminaSlot(const Spedizione*);
signals:
    void SaveOnFileSignal();
    void VisualizzaSpedizioneSignal(HierachyPageInterface*);
    void ModificaSpedizioneSignal(HierachyPageInterface*);
};



#endif //PROJECT_HOME_H
