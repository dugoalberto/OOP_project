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

    txtValore = new QLineEdit((pkg)?QString::fromStdString(to_string((pkg)->getValore())):"");
    txtValore->setPlaceholderText("Valore in €");
    txtValore->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,6}+(\\.[0-9]{1,2})?"), this));

    secondRow->addWidget(txtContenuto);
    secondRow->addWidget(txtValore);

    QHBoxLayout* thirdRow = new QHBoxLayout();
    txtPeso = new QLineEdit((pkg)?QString::number((pkg)->getPeso()):"");
    txtPeso->setPlaceholderText("Peso (Kg)");
    txtPeso->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,6}+(\\.[0-9]{1,2})?"), this));

    txtVolume = new QLineEdit((pkg)?QString::number((pkg)->getVolume()):"");
    txtVolume->setPlaceholderText("Volume (m^3)");
    txtVolume->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,6}+(\\.[0-9]{1,2})?"), this));

    thirdRow->addWidget(txtPeso);
    thirdRow->addWidget(txtVolume);

    mainLyt->addLayout(firstRow);
    mainLyt->addLayout(secondRow);
    mainLyt->addLayout(thirdRow);
    mainLyt->setAlignment(Qt::AlignCenter);
}

Package* PackageWidgetBase::getPackage() const {
    if(package) return package;
    else if(ConvalidaInput()) return new Package(txtContenuto->text().toStdString(),
                                                 txtValore->text().toFloat(),
                                                 txtPeso->text().toFloat(),
                                                 txtVolume->text().toFloat());
    else return nullptr;
}

bool PackageWidgetBase::ConvalidaInput() const {
    return  !txtContenuto->text().isEmpty() &&
            txtValore->hasAcceptableInput() &&
            txtPeso->hasAcceptableInput() &&
            txtVolume->hasAcceptableInput();
}