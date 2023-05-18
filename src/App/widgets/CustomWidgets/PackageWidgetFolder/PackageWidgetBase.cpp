//
// Created by utente on 12/05/2023.
//

#include <QDoubleValidator>
#include "PackageWidgetBase.h"
#include "../QLabelTitle.h"
#include <iostream>

PackageWidgetBase::PackageWidgetBase(Package *pkg, bool toEdit, QWidget* parent) : QWidget(parent), package(pkg) {
    mainLyt = new QVBoxLayout(this);

    QHBoxLayout* firstRow = new QHBoxLayout();
    firstRow->setAlignment(Qt::AlignCenter);
    QLabelTitle* lblPacco = new QLabelTitle("PACCO");
    firstRow->addWidget(lblPacco);

    QHBoxLayout* secondRow = new QHBoxLayout();
    txtContenuto = new QLineEdit((pkg)?QString::fromStdString((pkg)->getContenuto()):"");
    txtContenuto->setPlaceholderText("Contenuto");
    txtContenuto->setEnabled(toEdit);
    connect(txtContenuto, &QLineEdit::textChanged, this, &PackageWidgetBase::textChangedSlot);

    txtValore = new QLineEdit((pkg)?QString::number((pkg)->getValore()):"");
    txtValore->setPlaceholderText("Valore in €");
    txtValore->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,6}+(\\.[0-9]{1,2})?"), this));
    txtValore->setEnabled(toEdit);
    connect(txtValore, &QLineEdit::textChanged, this, &PackageWidgetBase::textChangedSlot);

    secondRow->addWidget(txtContenuto);
    secondRow->addWidget(txtValore);

    QHBoxLayout* thirdRow = new QHBoxLayout();
    txtPeso = new QLineEdit((pkg)?QString::number((pkg)->getPeso()):"");
    txtPeso->setPlaceholderText("Peso (Kg)");
    txtPeso->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,6}+(\\.[0-9]{1,2})?"), this));
    txtPeso->setEnabled(toEdit);
    connect(txtPeso, &QLineEdit::textChanged, this, &PackageWidgetBase::textChangedSlot);

    txtVolume = new QLineEdit((pkg)?QString::number((pkg)->getVolume()):"");
    txtVolume->setPlaceholderText("Volume (m^3)");
    txtVolume->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,6}+(\\.[0-9]{1,2})?"), this));
    txtVolume->setEnabled(toEdit);
    connect(txtVolume, &QLineEdit::textChanged, this, &PackageWidgetBase::textChangedSlot);

    thirdRow->addWidget(txtPeso);
    thirdRow->addWidget(txtVolume);

    mainLyt->addLayout(firstRow);
    mainLyt->addLayout(secondRow);
    mainLyt->addLayout(thirdRow);
    mainLyt->setAlignment(Qt::AlignCenter);
}

Package* PackageWidgetBase::getPackage() const {
    if(ConvalidaInput()) return new Package(txtContenuto->text().toStdString(),
                                                 txtValore->text().toFloat(),
                                                 txtPeso->text().toFloat(),
                                                 txtVolume->text().toFloat());
    else return nullptr;
}

bool PackageWidgetBase::ConvalidaInput() const {
    if(!txtValore->hasAcceptableInput()) txtValore->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(!txtPeso->hasAcceptableInput()) txtPeso->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(!txtVolume->hasAcceptableInput()) txtVolume->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(txtContenuto->text().isEmpty()) txtContenuto->setStyleSheet("QLineEdit{ border: 2px solid red; }");

    return  !txtContenuto->text().isEmpty() &&
            txtValore->hasAcceptableInput() &&
            txtPeso->hasAcceptableInput() &&
            txtVolume->hasAcceptableInput();
}

void PackageWidgetBase::textChangedSlot(){
    QLineEdit* txtSender = dynamic_cast<QLineEdit *>(sender());
    txtSender->setStyleSheet("QLineEdit::focus{ border: 2px solid #0078D7; } QLineEdit{ border: 1px solid #555555; }");
}