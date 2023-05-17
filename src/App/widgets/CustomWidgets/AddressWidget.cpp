//
// Created by utente on 12/05/2023.
//

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QRegularExpressionValidator>
#include "AddressWidget.h"
#include <iostream>

AddressWidget::AddressWidget(Address *obj, bool toEdit, Sender sender, bool international, QWidget* parent) : QWidget(parent), address(obj) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QHBoxLayout* firstRow = new QHBoxLayout();
    lblAddress = new QLabelTitle((sender==Sender::MITTENTE)? "Mittente":"Destinatario");
    firstRow->addWidget(lblAddress);
    firstRow->addStretch();
    mainLayout->addLayout(firstRow);

    QHBoxLayout* secondRow = new QHBoxLayout();
    txtNome = new QLineEdit(QString::fromStdString((obj)? obj->getNomeCognome():""));
    txtNome->setPlaceholderText("Nome e Cognome");
    connect(txtNome, &QLineEdit::textChanged, this, &AddressWidget::textChangedSlot);

    txtIndirizzo = new QLineEdit(QString::fromStdString((obj)? obj->getIndirizzo():""));
    txtIndirizzo->setPlaceholderText("Via");
    connect(txtIndirizzo, &QLineEdit::textChanged, this, &AddressWidget::textChangedSlot);

    txtCitta = new QLineEdit(QString::fromStdString((obj)? obj->getCitta():""));
    txtCitta->setPlaceholderText("Città");
    connect(txtCitta, &QLineEdit::textChanged, this, &AddressWidget::textChangedSlot);

    txtProvincia = new QLineEdit(QString::fromStdString((obj)? obj->getProvincia():""));
    txtProvincia->setPlaceholderText("Provincia");
    connect(txtProvincia, &QLineEdit::textChanged, this, &AddressWidget::textChangedSlot);

    txtCap = new QLineEdit(QString::fromStdString((obj)? to_string(obj->getCap()):""));
    txtCap->setPlaceholderText("Cap");
    txtCap->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{5}"), this));
    connect(txtCap, &QLineEdit::textChanged, this, &AddressWidget::textChangedSlot);

    txtStato = new QLineEdit(QString::fromStdString((obj)? obj->getNazione():""));
    txtStato->setPlaceholderText("Stato");
    txtStato->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Z]{2}"), this));
    connect(txtStato, &QLineEdit::textChanged, this, &AddressWidget::textChangedSlot);

    setField(toEdit);

    secondRow->addWidget(txtNome);
    secondRow->addWidget(txtIndirizzo);
    secondRow->addWidget(txtCitta);
    secondRow->addWidget(txtProvincia);
    secondRow->addWidget(txtCap);
    if(international)
        secondRow->addWidget(txtStato);
    else txtStato->setText("IT");

    mainLayout->addLayout(secondRow);
}

void AddressWidget::setField(bool toBeEdited){
    txtNome->setReadOnly(address && !toBeEdited);
    txtIndirizzo->setReadOnly(address && !toBeEdited);
    txtCitta->setReadOnly(address && !toBeEdited);
    txtProvincia->setReadOnly(address && !toBeEdited);
    txtCap->setReadOnly(address && !toBeEdited);
    txtStato->setReadOnly(address && !toBeEdited);
}

Address* AddressWidget::getAddress() const {
    if(address != nullptr)
        return address;
    else if(ConvalidaInput()) return new Address(txtNome->text().toStdString(),
                            txtIndirizzo->text().toStdString(),
                            txtCitta->text().toStdString(),
                            txtProvincia->text().toStdString(),
                            std::stoi(txtCap->text().toStdString()),
                            txtStato->text().toStdString());
    else return nullptr;
}

bool AddressWidget::ConvalidaInput() const {
    if(txtNome->text().isEmpty()) txtNome->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(txtCitta->text().isEmpty()) txtCitta->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(txtIndirizzo->text().isEmpty()) txtIndirizzo->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(txtStato->text().isEmpty()) txtStato->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(!txtCap->hasAcceptableInput()) txtCap->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(txtProvincia->text().isEmpty()) txtProvincia->setStyleSheet("QLineEdit{ border: 2px solid red; }");

    return  !txtNome->text().isEmpty() &&
            !txtIndirizzo->text().isEmpty() &&
            !txtProvincia->text().isEmpty() &&
            !txtCitta->text().isEmpty() &&
            txtCap->hasAcceptableInput();
}

void AddressWidget::textChangedSlot() {
    QLineEdit* txtSender = dynamic_cast<QLineEdit *>(sender());
    txtSender->setStyleSheet("QLineEdit{ border: 2px solid #0078D7; } QLineEdit{ border: 1px solid #555555; }");
}
