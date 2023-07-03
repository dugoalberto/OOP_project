//
// Created by Alberto Dugo on 02/05/23.
//

#include <iostream>
#include "Home.h"

Home::Home(FileManagerJSON *file, ArrayList<Spedizione *>* lst, QWidget *parents) : QWidget(parents), fm(file), lstElements(lst){
    QHBoxLayout* MainLayout = new QHBoxLayout(this);

    //LAYOUT PARTE SINISTRA
    QGroupBox* grpSideMenu = new QGroupBox();
    QVBoxLayout* lytSideMenu = new QVBoxLayout();
    lytSideMenu->addStretch();
    QLabelTitle* lblFiltri = new QLabelTitle("Fitri");
    lblFiltri->setAlignment(Qt::AlignCenter);
    lytSideMenu->addWidget(lblFiltri);

    std::string listaTipi[] = {"Economica","Premium","Cargo","Internazionale","Assicurata"};
    for(int i = 0; i < 5; i++){
        CbTypesArray[i] = new QCheckBox(QString::fromStdString(listaTipi[i]));
        CbTypesArray[i]->setCheckState(Qt::Checked);
        connect(CbTypesArray[i], &QCheckBox::stateChanged, this, &Home::FilterSelectedSlot);
        lytSideMenu->addWidget(CbTypesArray[i]);
    }

    lytSideMenu->addStretch();
    QLabelTitle* lblStato = new QLabelTitle("Stato");
    lblStato->setAlignment(Qt::AlignHCenter);
    lytSideMenu->addWidget(lblStato);

    std::string listaStati[] = {"In spedizione","In arrivo","In partenza","In filiale","Consegnato"};
    for(int i = 0; i < 5; i++){
        CbStatoArray[i] = new QCheckBox(QString::fromStdString(listaStati[i]));
        CbStatoArray[i]->setCheckState(Qt::Checked);
        connect(CbStatoArray[i], &QCheckBox::stateChanged, this, &Home::FilterSelectedSlot);
        lytSideMenu->addWidget(CbStatoArray[i]);
    }

    lytSideMenu->addStretch();
    grpSideMenu->setLayout(lytSideMenu);

    //LAYOUT PARTE DESTRA
    QGroupBox* grpRight = new QGroupBox();
    QVBoxLayout* lytView = new QVBoxLayout();

    QHBoxLayout* lytRowSearch = new QHBoxLayout();
    txtSearchBar = new QLineEdit();
    txtSearchBar->setPlaceholderText("Search");
    txtSearchBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    txtSearchBar->setObjectName("searchBar");
    connect(txtSearchBar, &QLineEdit::textChanged, this, &Home::SearchbarModifiedSlot);

    btnNewSpedizione = new MyButton(QString::fromStdString("+"));
    btnNewSpedizione->setMinimumWidth(100);

    lytRowSearch->addWidget(txtSearchBar);
    lytRowSearch->addWidget(btnNewSpedizione);
    lytView->addLayout(lytRowSearch);

    lstSpedizioni = new QListWidget();
    lstSpedizioni->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    loadListView();
    lytView->addWidget(lstSpedizioni);

    grpRight->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    grpRight->setLayout(lytView);

    //END
    MainLayout->addWidget(grpSideMenu);
    MainLayout->addWidget(grpRight);
    MainLayout->setAlignment(Qt::AlignVCenter);
}

void Home::loadListView() {
    lstSpedizioni->clear();
    for(auto it = lstElements->begin(); it != lstElements->end(); ++it){
        bool toBeInsert = false;
        for(int j = 0; j < 5; j++)
            if(CbTypesArray[j]->isChecked() && ((*it)->getTypeName() == "SPEDIZIONE" + CbTypesArray[j]->text().toUpper().toStdString() || (*it)->getTypeName() == "SPEDIZIONE" + CbTypesArray[j]->text().toUpper().toStdString() + "A"
                                                                                                                                      || (*it)->getTypeName() == "SPEDIZIONE" + CbTypesArray[j]->text().toUpper().toStdString() + "B"))
                for(int k = 0; k < 5; k++)
                    if(CbStatoArray[k]->isChecked() && (*it)->getStato()->getDescStato() == CbStatoArray[k]->text().toStdString())
                        if(QString::fromStdString(std::to_string((*it)->getTrakingNumber())).contains(txtSearchBar->text()))
                            toBeInsert = true;

        if(toBeInsert) {
            QListWidgetItem *item = new QListWidgetItem();
            ListViewSpedizioniItemWidget *widget = new ListViewSpedizioniItemWidget(*it);
            connect(widget, &ListViewSpedizioniItemWidget::VisualizzaSignal, this, &Home::VisualizzaSpedizioneSlot);
            connect(widget, &ListViewSpedizioniItemWidget::ModificaSignal, this, &Home::ModificaSpedizioneSlot);
            connect(widget, &ListViewSpedizioniItemWidget::EliminaSignal, this, &Home::EliminaSlot);
            item->setSizeHint(widget->sizeHint());
            lstSpedizioni->addItem(item);
            lstSpedizioni->setItemWidget(item, widget);
        }
    }
}

MyButton* Home::getSpedizioneButton() {
    return btnNewSpedizione;
}

MyButton *Home::getstatoSpedizioneButton() {
    return statoSpedizioneButton;
}

MyButton *Home::getFiliere() {
    return filiere;
}

void Home::FilterSelectedSlot() {
    loadListView();
}

void Home::SearchbarModifiedSlot() {
    loadListView();
}

void Home::AddNewSpedizioneSlot(Spedizione* spedizione) {

    int n = rand() % (9999-1000+1)+1000;
    while(lstElements->search(n) != -1){
        n = rand() % (9999-1000+1)+1000;
    }
    spedizione->setTrakingNumber(n);
    lstElements->add(spedizione);
    fm->saveData(*lstElements);
}

void Home::ModificaSpedizioneAggiornataSlot(Spedizione* spedizione){
    int index = lstElements->search(spedizione->getTrakingNumber());
    Spedizione* s = *lstElements->get(index);
    s->modifica(spedizione);
    fm->saveData(*lstElements);
}

void Home::VisualizzaSpedizioneSlot(const Spedizione *spe) {
    Visitor* visitor = new Visitor;
    spe->Accept(visitor, false);
    emit VisualizzaSpedizioneSignal(visitor->getWidget());
}

void Home::ModificaSpedizioneSlot (const Spedizione *spe) {
    Visitor* visitor = new Visitor;
    spe->Accept(visitor, true);
    emit ModificaSpedizioneSignal(visitor->getWidget());
}

void Home::EliminaSlot(const Spedizione *spe) {
    int index = lstElements->search(spe->getTrakingNumber());
    lstElements->remove(index);
    fm->saveData(*lstElements);
    loadListView();
}