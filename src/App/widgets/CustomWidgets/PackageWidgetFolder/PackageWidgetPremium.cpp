//
// Created by utente on 12/05/2023.
//

#include <QRegularExpressionValidator>
#include "PackageWidgetPremium.h"

PackageWidgetPremium::PackageWidgetPremium(Package* pkg, std::vector<int> dataOra, bool toEdit, QWidget* parent) : PackageWidgetBase(pkg, toEdit, parent) {
    QHBoxLayout* thirdRow = new QHBoxLayout();
    mainLyt->addSpacing(20);
    QVBoxLayout* orderLabel = new QVBoxLayout();
    orderLabel->setAlignment(Qt::AlignCenter);
    QLabel* lblDataOra = new QLabel("Data e Ora di consegna");
    orderLabel->addWidget(lblDataOra);

    txtGiorno = new QLineEdit((dataOra[0]!=-1)? QString::number(dataOra[0]):"");
    txtGiorno->setPlaceholderText("DD");
    connect(txtGiorno, &QLineEdit::textChanged, this, &PackageWidgetPremium::textChangedSlot);
    txtGiorno->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{2}"), this));
    txtGiorno->setEnabled(toEdit);
    txtMese = new QLineEdit((dataOra[1]!=-1)? QString::number(dataOra[1]):"");
    txtMese->setPlaceholderText("MM");
    connect(txtMese, &QLineEdit::textChanged, this, &PackageWidgetPremium::textChangedSlot);
    txtMese->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{2}"), this));
    txtMese->setEnabled(toEdit);
    txtAnno = new QLineEdit((dataOra[2]!=-1)? QString::number(dataOra[2]):"");
    txtAnno->setPlaceholderText("AAAA");
    connect(txtAnno, &QLineEdit::textChanged, this, &PackageWidgetPremium::textChangedSlot);
    txtAnno->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{4}"), this));
    txtAnno->setEnabled(toEdit);
    txtOre = new QLineEdit((dataOra[3]!=-1)? QString::number(dataOra[3]):"");
    txtOre->setPlaceholderText("HH");
    connect(txtOre, &QLineEdit::textChanged, this, &PackageWidgetPremium::textChangedSlot);
    txtOre->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{2}"), this));
    txtOre->setEnabled(toEdit);
    txtMinuti = new QLineEdit((dataOra[4]!=-1)? QString::number(dataOra[4]):"");
    txtMinuti->setPlaceholderText("mm");
    connect(txtMinuti, &QLineEdit::textChanged, this, &PackageWidgetPremium::textChangedSlot);
    txtMinuti->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{2}"), this));
    txtMinuti->setEnabled(toEdit);
    //GIORNO MESE ANNO
    thirdRow->addWidget(txtGiorno);
    thirdRow->addWidget(txtMese);
    thirdRow->addWidget(txtAnno);

    //ORE e MINUTI
    QHBoxLayout* fourthRow = new QHBoxLayout();
    fourthRow->setAlignment(Qt::AlignHCenter);
    txtOre->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    txtMinuti->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    fourthRow->addWidget(txtOre);
    fourthRow->addWidget(txtMinuti);

    orderLabel->addLayout(thirdRow);
    orderLabel->addLayout(fourthRow);
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

bool PackageWidgetPremium::ConvalidaInput() const {
    if(!txtGiorno->hasAcceptableInput()) txtGiorno->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(!txtMese->hasAcceptableInput()) txtMese->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(!txtAnno->hasAcceptableInput()) txtAnno->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(!txtOre->hasAcceptableInput()) txtOre->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(!txtMinuti->hasAcceptableInput()) txtMinuti->setStyleSheet("QLineEdit{ border: 2px solid red; }");


    return  PackageWidgetBase::ConvalidaInput() &&
            txtGiorno->hasAcceptableInput() &&
            txtMese->hasAcceptableInput() &&
            txtAnno->hasAcceptableInput() &&
            txtOre->hasAcceptableInput() &&
            txtMinuti->hasAcceptableInput();

}

void PackageWidgetPremium::textChangedSlot() {
    QLineEdit* txtSender = dynamic_cast<QLineEdit *>(sender());
    txtSender->setStyleSheet("QLineEdit{ border: 2px solid #0078D7; } QLineEdit{ border: 1px solid #555555; }");
}
