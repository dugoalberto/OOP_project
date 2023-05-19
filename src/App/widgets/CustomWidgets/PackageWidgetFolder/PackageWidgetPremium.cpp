//
// Created by utente on 12/05/2023.
//

#include <QRegularExpressionValidator>
#include <QDate>
#include "PackageWidgetPremium.h"
#include <iostream>

PackageWidgetPremium::PackageWidgetPremium(Package* pkg, std::vector<int> dataOra, bool toEdit, QWidget* parent) : PackageWidgetBase(pkg, toEdit, parent) {
    QHBoxLayout* thirdRow = new QHBoxLayout();
    mainLyt->addSpacing(20);
    QVBoxLayout* orderLabel = new QVBoxLayout();
    orderLabel->setAlignment(Qt::AlignCenter);
    QLabel* lblDataOra = new QLabel("Data e Ora di consegna");
    orderLabel->addWidget(lblDataOra);

    txtGiorno = new QComboBox();
    txtGiorno->setPlaceholderText("DD");
    txtGiorno->setEnabled(toEdit);
    for(int i = 1; i <=31; i++)
        txtGiorno->addItem(QString::number(i,10).rightJustified(2,'0'));
    if(dataOra[0] != -1)
        txtGiorno->setCurrentText(QString::number(dataOra[0],10).rightJustified(2,'0'));
    else txtGiorno->setCurrentText("01");
    connect(txtGiorno, &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);

    txtMese = new QComboBox();
    txtMese->setPlaceholderText("MM");
    txtMese->setEnabled(toEdit);
    for(int i = 1; i <= 12; i++)
        txtMese->addItem(QString::number(i,10).rightJustified(2,'0'));
    if(dataOra[1] != -1)
        txtMese->setCurrentText(QString::number(dataOra[1],10).rightJustified(2,'0'));
    else txtMese->setCurrentText("01");
    connect(txtMese,  &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);


    txtAnno = new QComboBox();
    txtAnno->setPlaceholderText("AAAA");
    txtAnno->setEnabled(toEdit);
    for(int i = 2023; i <= 2025; i++)
        txtAnno->addItem(QString::number(i));
    if(dataOra[2] != -1)
        txtAnno->setCurrentText(QString::number(dataOra[2],10).rightJustified(2,'0'));
    else txtAnno->setCurrentText("2023");
    connect(txtAnno, &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);


    txtOre = new QComboBox();
    txtOre->setPlaceholderText("HH");
    txtOre->setEnabled(toEdit);
    for(int i = 0; i <= 24; i++)
        txtOre->addItem(QString::number(i,10).rightJustified(2,'0'));
    if(dataOra[3] != -1)
        txtOre->setCurrentText(QString::number(dataOra[3],10).rightJustified(2,'0'));
    else txtOre->setCurrentText("00");
    connect(txtOre, &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);

    txtMinuti = new QComboBox();
    txtMinuti->setPlaceholderText("mm");
    txtMinuti->setEnabled(toEdit);
    for(int i = 0; i < 60; i+=15)
        txtMinuti->addItem(QString::number(i,10).rightJustified(2,'0'));
    if(dataOra[4] != -1)
        txtMinuti->setCurrentText(QString::number(dataOra[4],10).rightJustified(2,'0'));
    else txtMinuti->setCurrentText("00");
    connect(txtMinuti, &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);

    //GIORNO MESE ANNO
    thirdRow->addWidget(txtGiorno);
    thirdRow->addWidget(new QLabel("/"));
    thirdRow->addWidget(txtMese);
    thirdRow->addWidget(new QLabel("/"));
    thirdRow->addWidget(txtAnno);


    //ORE e MINUTI
    QHBoxLayout* fourthRow = new QHBoxLayout();
    fourthRow->setAlignment(Qt::AlignHCenter);
    txtOre->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    txtMinuti->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    fourthRow->addWidget(txtOre);
    fourthRow->addWidget(new QLabel(":"));
    fourthRow->addWidget(txtMinuti);

    orderLabel->addLayout(thirdRow);
    orderLabel->addLayout(fourthRow);
    mainLyt->addLayout(orderLabel);
}

QComboBox *PackageWidgetPremium::getTxtGiorno() const {
    return txtGiorno;
}

QComboBox *PackageWidgetPremium::getTxtMese() const {
    return txtMese;
}

QComboBox *PackageWidgetPremium::getTxtAnno() const {
    return txtAnno;
}

QComboBox *PackageWidgetPremium::getTxtOre() const {
    return txtOre;
}

QComboBox *PackageWidgetPremium::getTxtMinuti() const {
    return txtMinuti;
}

bool PackageWidgetPremium::ConvalidaInput() const {
    if(txtGiorno->currentText().isEmpty()) txtGiorno->setStyleSheet("QComboBox{ border: 2px solid red; }");
    if(txtMese->currentText().isEmpty()) txtMese->setStyleSheet("QComboBox{ border: 2px solid red; }");
    if(txtAnno->currentText().isEmpty()) txtAnno->setStyleSheet("QComboBox{ border: 2px solid red; }");
    if(txtOre->currentText().isEmpty()) txtOre->setStyleSheet("QComboBox{ border: 2px solid red; }");
    if(txtMinuti->currentText().isEmpty()) txtMinuti->setStyleSheet("QComboBox{ border: 2px solid red; }");


    return  PackageWidgetBase::ConvalidaInput() &&
            !txtGiorno->currentText().isEmpty() &&
            !txtMese->currentText().isEmpty() &&
            !txtAnno->currentText().isEmpty() &&
            !txtOre->currentText().isEmpty() &&
            !txtMinuti->currentText().isEmpty();

}

void PackageWidgetPremium::textChangedSlot() {
    QComboBox* txtSender = dynamic_cast<QComboBox *>(sender());
    txtSender->setStyleSheet("QComboBox{ border: 1px solid #555555; }");

    QDate* currData = new QDate(txtAnno->currentText().toInt(), txtMese->currentText().toInt(), txtGiorno->currentText().toInt());
    QDate* data = nullptr;
    if(txtSender == txtGiorno || txtSender == txtAnno){
        disconnect(txtMese, &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);
        txtMese->clear();
        for(int i = 1; i <= 12; i++){
            data = new QDate(txtAnno->currentText().toInt(), i, txtGiorno->currentText().toInt());
            if(data->isValid()) {
                txtMese->addItem(QString::number(i, 10).rightJustified(2, '0'));
            }
        }

        if(currData->isValid()){
            txtGiorno->setCurrentText(QString::number(currData->day(),10).rightJustified(2,'0'));
            txtMese->setCurrentText(QString::number(currData->month(),10).rightJustified(2,'0'));
        }

        connect(txtMese, &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);
    } else if(txtSender == txtMese || txtSender == txtAnno){
        disconnect(txtGiorno, &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);
        txtGiorno->clear();
        for(int i = 1; i <= 31; i++){
            data = new QDate(txtAnno->currentText().toInt(), txtMese->currentText().toInt(), i);
            if(data->isValid()) {
                txtGiorno->addItem(QString::number(i, 10).rightJustified(2, '0'));
            }
        }

        if(currData->isValid()){
            txtGiorno->setCurrentText(QString::number(currData->day(),10).rightJustified(2,'0'));
            txtMese->setCurrentText(QString::number(currData->month(),10).rightJustified(2,'0'));
        }

        connect(txtGiorno, &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);
    } else if(txtSender == txtAnno){
        disconnect(txtAnno, &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);
        
        txtAnno->clear();
        for(int i = 2023; i <= 2025; i++){
            data = new QDate(i, txtMese->currentText().toInt(), txtGiorno->currentText().toInt());
            if(data->isValid()) {
                txtAnno->addItem(QString::number(i, 10).rightJustified(2, '0'));
            }
        }

        if(currData->isValid()){
            txtAnno->setCurrentText(QString::number(currData->year(),10).rightJustified(4,'0'));
        }else txtAnno->setCurrentText("2024");

        connect(txtAnno, &QComboBox::currentIndexChanged, this, &PackageWidgetPremium::textChangedSlot);
    }
}
