//
// Created by utente on 12/05/2023.
//

#include <QDoubleValidator>
#include "PackageWidgetBase.h"
#include "../QLabelTitle.h"

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
    txtValore->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,6}+(\\.[0-9]{1,2})"), this));

    secondRow->addWidget(txtContenuto);
    secondRow->addWidget(txtValore);

    mainLyt->addLayout(firstRow);
    mainLyt->addSpacing(20);
    mainLyt->addLayout(secondRow);
    mainLyt->setAlignment(Qt::AlignCenter);
}

Package* PackageWidgetBase::getPackage() const {
    return package;
}