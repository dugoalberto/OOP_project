//
// Created by Alberto Dugo on 24/05/2023.
//

#include <QRegularExpressionValidator>
#include <QLabel>
#include "DialogAssicurazione.h"
#include "../MyButton.h"

DialogAssicurazione::DialogAssicurazione(Assicurazione *a, bool toEdit, QWidget *parent) : QDialog(parent), assicurazione(a) {
    QHBoxLayout* mainLyt = new QHBoxLayout(this);

    txtNome = new QLineEdit();
    txtNome->setPlaceholderText("Nome Assicurazione");
    txtNome->setEnabled(toEdit);
    connect(txtNome, &QLineEdit::textChanged, this, &DialogAssicurazione::textChangedSlot);

    txtNumero = new QLineEdit();
    txtNumero->setPlaceholderText("Costo per servizio");
    txtNumero->setEnabled(toEdit);
    txtNumero->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,6}+(\\.[0-9]{1,2})?"), this));
    connect(txtNumero, &QLineEdit::textChanged, this, &DialogAssicurazione::textChangedSlot);

    if(a) {
        txtNome->setText(QString::fromStdString(a->getNomeAssicurazione()));
        txtNumero->setText(QString::number(a->getPrezzo(), 'f', 2));
    }

    mainLyt->addWidget(txtNome);
    mainLyt->addWidget(txtNumero);

    if(toEdit){
        MyButton* btnModifica = new MyButton((assicurazione)? "Salva Modifiche" : "Aggiungi Filiale");
        if(assicurazione)
            connect(btnModifica, &QPushButton::clicked, this, &DialogAssicurazione::ModificaAssicurazioneSlot);
        else connect(btnModifica, &QPushButton::clicked, this, &DialogAssicurazione::AggiungiAssicurazioneSlot);
        mainLyt->addWidget(btnModifica);
    }
}

//Covalida i campi di input affinchè siano inseriti solo valori coerenti e consistenti
//mostrando graficamente un avviso all'utente
bool DialogAssicurazione::ConvalidaInput() {
    if(txtNome->text().isEmpty()) txtNome->setStyleSheet("QLineEdit{ border: 2px solid red; }");
    if(!txtNumero->hasAcceptableInput()) txtNumero->setStyleSheet("QLineEdit{ border: 2px solid red; }");

    return  !txtNome->text().isEmpty() &&
            txtNumero->hasAcceptableInput();
}

void DialogAssicurazione::ModificaAssicurazioneSlot() {

    if(ConvalidaInput()){
        assicurazione->setNomeAssicurazione(txtNome->text().toStdString());
        assicurazione->setPrezzo(txtNumero->text().toFloat());
        close();
        emit AssicurazioneModificataSignal();
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

void DialogAssicurazione::textChangedSlot() {
    QLineEdit* send = dynamic_cast<QLineEdit*>(sender());
    send->setStyleSheet("QLineEdit{ border: 2px solid #0078D7; } QLineEdit{ border: 1px solid #555555; }");
}

void DialogAssicurazione::AggiungiAssicurazioneSlot() {

    if(ConvalidaInput()){
        close();
        emit AggiungiAssicurazioneSignal(new Assicurazione(   txtNome->text().toStdString(),
                                                        txtNumero->text().toFloat()));
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