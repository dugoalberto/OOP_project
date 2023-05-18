//
// Created by utente on 12/05/2023.
//
#include "SelezioneTipoPage.h"

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

    std::vector<Filiale> lstFiliali = FileManager::readFiliali();
    QListWidget* viewFiliali = new QListWidget();
    loadView(lstFiliali, viewFiliali);

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

    std::vector<Assicurazione> lstAssicurazioni = FileManager::readAssicurazioni();
    QListWidget* viewAssicurazioni = new QListWidget();
    loadView(lstAssicurazioni, viewAssicurazioni);

    lytAssicurazioni->addLayout(firstRowAssicurazioni);
    lytAssicurazioni->addWidget(viewAssicurazioni);
    grpAssicurazioni->setLayout(lytAssicurazioni);
    lowerRow->addWidget(grpAssicurazioni);

    lytMain->addLayout(lowerRow);
}

template<class T>
void SelezioneTipoPage::loadView(std::vector<T> &lst, QListWidget *wiew) const {
    for(auto it = lst.begin(); it != lst.end(); ++it) {
        QListWidgetItem *item = new QListWidgetItem();
        QWidget* widget = nullptr;
        if (dynamic_cast<Filiale*>(&(*it))){
            widget = new ListViewFilialeItemWidget(dynamic_cast<Filiale *>(&(*it)));
        }
        else if(dynamic_cast<Assicurazione*>(&(*it))){
            widget = new ListViewAssicurazioneItemWidget(dynamic_cast<Assicurazione*>(&(*it)));
        }
        item->setSizeHint(widget->sizeHint());
        wiew->addItem(item);
        wiew->setItemWidget(item, widget);
    }
}

void SelezioneTipoPage::btnBackSlot() {
    emit backSignal();
}

void SelezioneTipoPage::btnEconomicaPressedSlot() {
    emit EconomicaSignal(new SpedizioneAssicurataPage(nullptr, false, nullptr));
}

void SelezioneTipoPage::btnPremiumPressedSlot() {
    emit PremiumSignal(new SpedizioneAssicurataPage(nullptr, false, nullptr));
}

void SelezioneTipoPage::btnCargoPressedSlot() {
    emit CargoSignal(new SpedizioneAssicurataPage(nullptr, false, nullptr));
}

void SelezioneTipoPage::btnInternazionalePressedSlot() {
    emit InternazionaleSignal(new SpedizioneAssicurataPage(nullptr, false, nullptr));
}

void SelezioneTipoPage::btnAssicurataPressedSlot() {
    emit AssicurataSignal(new SpedizioneAssicurataPage(nullptr, true, nullptr));
}

void SelezioneTipoPage::btnAddAssicurazioneSlot() {
    //TODO
}

void SelezioneTipoPage::btnAddFilialePressedSlot() {
    //TODO
}