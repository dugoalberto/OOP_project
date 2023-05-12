//
// Created by utente on 12/05/2023.
//

#include "PackageWidgetPremium.h"

PackageWidgetPremium::PackageWidgetPremium(Package* pkg, bool toEdit, QWidget* parent) : PackageWidgetBase(pkg, toEdit, parent) {
    QHBoxLayout* thirdRow = new QHBoxLayout();

    QVBoxLayout* orderLabel = new QVBoxLayout();
    orderLabel->setAlignment(Qt::AlignCenter);
    QLabel* lblDataOra = new QLabel("Data e Ora di consegna");
    orderLabel->addWidget(lblDataOra);

    txtGiorno = new QLineEdit();
    txtMese = new QLineEdit();
    txtAnno = new QLineEdit();
    txtOre = new QLineEdit();
    txtMinuti = new QLineEdit();

    thirdRow->addWidget(txtGiorno);
    thirdRow->addWidget(txtMese);
    thirdRow->addWidget(txtAnno);
    thirdRow->addWidget(txtOre);
    thirdRow->addWidget(txtMinuti);

    orderLabel->addLayout(thirdRow);
    mainLyt->addLayout(orderLabel);
}

QLineEdit *PackageWidgetPremium::getTxtGiorno() const {
    return txtGiorno;
}

QLineEdit *PackageWidgetPremium::getTxtMese() const {
    return txtMese;
}

QLineEdit *PackageWidgetPremium::getTxtAnno() const {
    return txtAnno;
}

QLineEdit *PackageWidgetPremium::getTxtOre() const {
    return txtOre;
}

QLineEdit *PackageWidgetPremium::getTxtMinuti() const {
    return txtMinuti;
}
