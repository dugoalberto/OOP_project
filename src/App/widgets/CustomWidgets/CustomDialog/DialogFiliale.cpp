//
// Created by Alberto Dugo on 24/05/2023.
//

#include <QRegularExpressionValidator>
#include <QLabel>
#include "DialogFiliale.h"
#include "../MyButton.h"

DialogFiliale::DialogFiliale(Filiale *f, bool toEdit, QWidget *parent) : QDialog(parent), filiale(f) {
    QHBoxLayout* mainLyt = new QHBoxLayout(this);

    txtNome = new QLineEdit();
    txtNome->setPlaceholderText("Città filiale");
    txtNome->setEnabled(toEdit);
    connect(txtNome, &QLineEdit::textChanged, this, &DialogFiliale::textChangedSlot);

    txtProvincia = new QLineEdit();
    txtProvincia->setPlaceholderText("Provincia");
    txtProvincia->setEnabled(toEdit);
    txtProvincia->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Za-z]{2}"), this));
    connect(txtProvincia, &QLineEdit::textChanged, this, &DialogFiliale::textChangedSlot);

    txtNumero = new QLineEdit();
    txtNumero->setPlaceholderText("Numero di telefono");
    txtNumero->setEnabled(toEdit);
    txtNumero->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{10}"), this));
    connect(txtNumero, &QLineEdit::textChanged, this, &DialogFiliale::textChangedSlot);

    if(f) {
        txtNome->setText(QString::fromStdString(f->getCitta()));
        txtProvincia->setText(QString::fromStdString(f->getProvincia()));
        txtNumero->setText(QString::fromStdString(f->getNumeroTel()).rightJustified(10, '0'));
    }

    mainLyt->addWidget(txtNome);
    mainLyt->addWidget(txtProvincia);
    mainLyt->addWidget(txtNumero);

    if(toEdit){
        MyButton* btnModifica = new MyButton((filiale)? "Salva Modifiche" : "Aggiungi Filiale");
        if(filiale)
            connect(btnModifica, &QPushButton::clicked, this, &DialogFiliale::ModificaFilialeSlot);
        else connect(btnModifica, &QPushButton::clicked, this, &DialogFiliale::AggiungiFilialeSlot);
        mainLyt->addWidget(btnModifica);
    }
}

//Covalida i campi di input affinchè siano inseriti solo valori coerenti e consistenti
//mostrando graficamente un avviso all'utente
bool DialogFiliale::ConvalidaInput() {
    if(txtNome->text().isEmpty()) txtNome->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(!txtProvincia->hasAcceptableInput()) txtProvincia->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(!txtNumero->hasAcceptableInput()) txtNumero->setStyleSheet("QLineEdit{ border: 2px solid red; }");

    return  !txtNome->text().isEmpty() &&
            txtProvincia->hasAcceptableInput() &&
            txtNumero->hasAcceptableInput();
}

void DialogFiliale::ModificaFilialeSlot() {

    if(ConvalidaInput()){
        filiale->setCitta(txtNome->text().toStdString());
        filiale->setProvincia(txtProvincia->text().toStdString());
        filiale->setNumeroTel(txtNumero->text().toStdString());
        close();
        emit FilialeModificataSignal();
    }
    else {
        QDialog dialog;
        QLabel *dialogLabel = new QLabel("Attenzione: tutti i campi devono essere inseriti");
        QHBoxLayout *dialogLayout = new QHBoxLayout;
        dialogLayout->addWidget(dialogLabel);
        dialog.setLayout(dialogLayout);
        dialog.exec();
    }
}

void DialogFiliale::textChangedSlot() {
    QLineEdit* send = dynamic_cast<QLineEdit*>(sender());
    send->setStyleSheet("QLineEdit{ border: 2px solid #0078D7; } QLineEdit{ border: 1px solid #555555; }");
}

void DialogFiliale::AggiungiFilialeSlot() {

    if(ConvalidaInput()){
        close();
        emit AggiungiFilialeSignal(new Filiale(txtNome->text().toStdString(),
                                                 txtProvincia->text().toStdString(),
                                                 txtNumero->text().toStdString()));
    }
    else {
        QDialog dialog;
        QLabel *dialogLabel = new QLabel("Attenzione: tutti i campi devono essere inseriti");
        QHBoxLayout *dialogLayout = new QHBoxLayout;
        dialogLayout->addWidget(dialogLabel);
        dialog.setLayout(dialogLayout);
        dialog.exec();
    }
}