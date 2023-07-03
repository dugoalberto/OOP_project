//
// Created by Alberto Dugo on 12/05/2023.
//
#include "SelezioneTipoPage.h"
#include "HierachyPages/SpedizioneInternazionalePage.h"
#include "../Visitor/VisitorDialog.h"
#include "../CustomWidgets/CustomDialog/DialogFiliale.h"
#include "../CustomWidgets/CustomDialog/DialogAssicurazione.h"

SelezioneTipoPage::SelezioneTipoPage(QWidget *parent) : QWidget(parent){
    QVBoxLayout* lytMain = new QVBoxLayout(this);

    QGroupBox* grpSpedizione = new QGroupBox();
    QVBoxLayout* lytSpedizioni = new QVBoxLayout();
    QGridLayout* firstRow = new QGridLayout();
    MyButton* btnback = new MyButton("<<");
    connect(btnback, &QPushButton::clicked, this, &SelezioneTipoPage::btnBackSlot);
    btnback->setFixedSize(50,50);
    firstRow->addWidget(btnback,0,0);
    firstRow->addWidget(new QLabelTitle("Nuova Spedizione"),0,1,Qt::AlignCenter);
    QWidget* vuoto = new QWidget();
    vuoto->setFixedSize(btnback->size());
    firstRow->addWidget(vuoto,0,2);

    QHBoxLayout* secondRow = new QHBoxLayout();
    MyButton* btnEconomica = new MyButton("Economica");
    connect(btnEconomica, &QPushButton::clicked, this, &SelezioneTipoPage::btnEconomicaPressedSlot);
    secondRow->addWidget(btnEconomica);
    MyButton* btnPremium = new MyButton("Premium");
    connect(btnPremium, &QPushButton::clicked, this, &SelezioneTipoPage::btnPremiumPressedSlot);
    secondRow->addWidget(btnPremium);
    MyButton* btnCargo = new MyButton("Cargo (anche internazionale)");
    connect(btnCargo, &QPushButton::clicked, this, &SelezioneTipoPage::btnCargoPressedSlot);
    secondRow->addWidget(btnCargo);
    MyButton* btnInternazionale = new MyButton("Internazionale");
    connect(btnInternazionale, &QPushButton::clicked, this, &SelezioneTipoPage::btnInternazionalePressedSlot);
    secondRow->addWidget(btnInternazionale);
    MyButton* btnAssicurata = new MyButton("Assicurata");
    connect(btnAssicurata, &QPushButton::clicked, this, &SelezioneTipoPage::btnAssicurataPressedSlot);
    secondRow->addWidget(btnAssicurata);

    lytSpedizioni->addLayout(firstRow);
    lytSpedizioni->addSpacing(20);
    lytSpedizioni->addLayout(secondRow);
    grpSpedizione->setLayout(lytSpedizioni);
    lytMain->addWidget(grpSpedizione);

    //Lower Part
    //filiali
    QHBoxLayout* lowerRow = new QHBoxLayout();

    QVBoxLayout* lytFiliali = new QVBoxLayout();
    lytFiliali->setAlignment(Qt::AlignCenter);

    QGroupBox* grpFiliali = new QGroupBox();
    QHBoxLayout* firstRowFiliali = new QHBoxLayout();
    MyButton* btnAddFiliale = new MyButton("+");
    connect(btnAddFiliale, &QPushButton::clicked, this, &SelezioneTipoPage::btnAddFilialePressedSlot);
    firstRowFiliali->addWidget(new QLabelTitle("Filiali"));
    firstRowFiliali->addWidget(btnAddFiliale);

    lstFiliali = FileManagerJSON::readFiliali();
    viewFiliali = new QListWidget();
    loadFiliali();

    lytFiliali->addLayout(firstRowFiliali);
    lytFiliali->addWidget(viewFiliali);
    grpFiliali->setLayout(lytFiliali);
    lowerRow->addWidget(grpFiliali);

    //Assicurazioni
    QVBoxLayout* lytAssicurazioni = new QVBoxLayout();
    lytAssicurazioni->setAlignment(Qt::AlignCenter);

    QGroupBox* grpAssicurazioni = new QGroupBox();
    QHBoxLayout* firstRowAssicurazioni = new QHBoxLayout();
    MyButton* btnAddAssicurazione = new MyButton("+");
    connect(btnAddAssicurazione, &QPushButton::clicked, this, &SelezioneTipoPage::btnAddAssicurazioneSlot);
    firstRowAssicurazioni->addWidget(new QLabelTitle("Assicurazioni"));
    firstRowAssicurazioni->addWidget(btnAddAssicurazione);

    lstAssicurazioni = FileManagerJSON::readAssicurazioni();
    viewAssicurazioni = new QListWidget();
    loadAssicurazioni();

    lytAssicurazioni->addLayout(firstRowAssicurazioni);
    lytAssicurazioni->addWidget(viewAssicurazioni);
    grpAssicurazioni->setLayout(lytAssicurazioni);
    lowerRow->addWidget(grpAssicurazioni);

    lytMain->addLayout(lowerRow);
}

void SelezioneTipoPage::loadFiliali() {
    viewFiliali->clear();
    for(auto it = lstFiliali.begin(); it != lstFiliali.end(); ++it) {
        QListWidgetItem *item = new QListWidgetItem();
        ListViewFilialeItemWidget* widget = new ListViewFilialeItemWidget(*it);
        connect(widget, &ListViewFilialeItemWidget::VisualizzaSignal, this, &SelezioneTipoPage::VisualizzaFilialeSlot);
        connect(widget, &ListViewFilialeItemWidget::ModificaSignal, this, &SelezioneTipoPage::ModificaFilialeSlot);
        connect(widget, &ListViewFilialeItemWidget::EliminaSignal, this, &SelezioneTipoPage::EliminaFilialeSlot);

        item->setSizeHint(widget->sizeHint());
        viewFiliali->addItem(item);
        viewFiliali->setItemWidget(item, widget);
    }
}

void SelezioneTipoPage::loadAssicurazioni() const {
    viewAssicurazioni->clear();
    for(auto it = lstAssicurazioni.begin(); it != lstAssicurazioni.end(); ++it) {
        QListWidgetItem *item = new QListWidgetItem();
        ListViewAssicurazioneItemWidget* widget =  new ListViewAssicurazioneItemWidget(*it);
        connect(widget, &ListViewAssicurazioneItemWidget::VisualizzaSignal, this, &SelezioneTipoPage::VisualizzaAssicurazioneSlot);
        connect(widget, &ListViewAssicurazioneItemWidget::ModificaSignal, this, &SelezioneTipoPage::ModificaAssicurazioneSlot);
        connect(widget, &ListViewAssicurazioneItemWidget::EliminaSignal, this, &SelezioneTipoPage::EliminaAssicurazioneSlot);
        item->setSizeHint(widget->sizeHint());
        viewAssicurazioni->addItem(item);
        viewAssicurazioni->setItemWidget(item, widget);
    }
}

void SelezioneTipoPage::btnBackSlot() {
    emit backSignal();
}

void SelezioneTipoPage::btnEconomicaPressedSlot() {
    emit EconomicaSignal(new SpedizioneEconomicaPage(nullptr, true, nullptr));
}

void SelezioneTipoPage::btnPremiumPressedSlot() {
    emit PremiumSignal(new SpedizionePremiumPage(nullptr, true, nullptr));
}

void SelezioneTipoPage::btnCargoPressedSlot() {
    emit CargoSignal(new SpedizioneCargoPage(nullptr, true, nullptr));
}

void SelezioneTipoPage::btnInternazionalePressedSlot() {
    emit InternazionaleSignal(new SpedizioneInternazionalePage(nullptr, true, nullptr));
}

void SelezioneTipoPage::btnAssicurataPressedSlot() {
    emit AssicurataSignal(new SpedizioneAssicurataPage(nullptr, true, nullptr));
}

void SelezioneTipoPage::VisualizzaFilialeSlot(Filiale* f) {
    VisitorDialog* visitor = new VisitorDialog();
    f->Accept(visitor, false);
    QDialog* dialog = visitor->getWidget();
    dialog->show();
}

void SelezioneTipoPage::ModificaFilialeSlot(Filiale* f) {
    VisitorDialog* visitor = new VisitorDialog();
    f->Accept(visitor,true);
    QDialog* dialog = visitor->getWidget();
    connect(dynamic_cast<DialogFiliale*>(dialog), &DialogFiliale::FilialeModificataSignal, this, &SelezioneTipoPage::reloadFilialiSlot);
    dialog->show();
}

void SelezioneTipoPage::VisualizzaAssicurazioneSlot(Assicurazione* a) {
    VisitorDialog* visitor = new VisitorDialog();
    a->Accept(visitor, false);
    QDialog* dialog = visitor->getWidget();
    dialog->show();
}

void SelezioneTipoPage::reloadFilialiSlot() {
    FileManagerJSON::saveFiliali(lstFiliali);
    loadFiliali();
}

void SelezioneTipoPage::reloadAssicurazioneSlot() {
    FileManagerJSON::saveAssicurazioni(lstAssicurazioni);
    loadAssicurazioni();
}

//
// FILIALE
//

void SelezioneTipoPage::btnAddFilialePressedSlot() {
    DialogFiliale* dialog = new DialogFiliale(nullptr, true);
    connect(dialog, &DialogFiliale::AggiungiFilialeSignal, this, &SelezioneTipoPage::AggiungiFilialeSlot);
    dialog->show();
}

void SelezioneTipoPage::AggiungiFilialeSlot(Filiale *f) {
    int pos = -1;
    for(unsigned int i = 0; i < lstFiliali.size(); ++i){
        if(lstFiliali[i]->getCitta() == f->getCitta())
            pos = i;
    }
    if(pos == -1)
        lstFiliali.push_back(f);
    else{
        QDialog dialog;
        QLabel *dialogLabel = new QLabel("Attenzione: La filiale di questa città è già presente!");
        QHBoxLayout *dialogLayout = new QHBoxLayout;
        dialogLayout->addWidget(dialogLabel);
        dialog.setLayout(dialogLayout);
        dialog.exec();
    }
    reloadFilialiSlot();
}

void SelezioneTipoPage::EliminaFilialeSlot(Filiale *f) {
    for (unsigned int i = 0; i < lstFiliali.size(); ++i){
        if (lstFiliali[i]->getCitta() == f->getCitta()) {
            lstFiliali.erase(lstFiliali.begin() + i);
            continue;
        }
    }
    reloadFilialiSlot();
}

//
// ASSICURAZIONE
//

void SelezioneTipoPage::btnAddAssicurazioneSlot() {
    DialogAssicurazione* dialog = new DialogAssicurazione(nullptr, true);
    connect(dialog, &DialogAssicurazione::AggiungiAssicurazioneSignal, this, &SelezioneTipoPage::AggiungiAssicurazioneSlot);
    dialog->show();
}

void SelezioneTipoPage::EliminaAssicurazioneSlot(Assicurazione *a) {
    for (unsigned int i = 0; i < lstAssicurazioni.size(); ++i){
        if (lstAssicurazioni[i]->getNomeAssicurazione() == a->getNomeAssicurazione()) {
            lstAssicurazioni.erase(lstAssicurazioni.begin() + i);
            continue;
        }
    }
    reloadAssicurazioneSlot();
}

void SelezioneTipoPage::AggiungiAssicurazioneSlot(Assicurazione *a) {
    int pos = -1;
    for(unsigned int i = 0; i < lstAssicurazioni.size(); ++i){
        if(lstAssicurazioni[i]->getNomeAssicurazione() == a->getNomeAssicurazione())
            pos = i;
    }
    if(pos == -1)
        lstAssicurazioni.push_back(a);
    else{
        QDialog dialog;
        QLabel *dialogLabel = new QLabel("Attenzione: Nome assicurazione già presente!");
        QHBoxLayout *dialogLayout = new QHBoxLayout;
        dialogLayout->addWidget(dialogLabel);
        dialog.setLayout(dialogLayout);
        dialog.exec();
    }
    reloadAssicurazioneSlot();
}

void SelezioneTipoPage::ModificaAssicurazioneSlot(Assicurazione *a) {
    VisitorDialog* visitor = new VisitorDialog();
    a->Accept(visitor,true);
    QDialog* dialog = visitor->getWidget();
    connect(dynamic_cast<DialogAssicurazione*>(dialog), &DialogAssicurazione::AssicurazioneModificataSignal, this, &SelezioneTipoPage::reloadAssicurazioneSlot);
    dialog->show();
}