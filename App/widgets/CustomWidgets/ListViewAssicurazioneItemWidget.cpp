//
// Created by utente on 12/05/2023.
//

#include <QHBoxLayout>
#include <QLabel>
#include "ListViewAssicurazioneItemWidget.h"
#include "myButton.h"

ListViewAssicurazioneItemWidget::ListViewAssicurazioneItemWidget(Assicurazione *ass, QWidget *parent) : QWidget(parent), obj(ass){
    QHBoxLayout* lytMain = new QHBoxLayout(this);

    QLabel* lblNome = new QLabel(QString::fromStdString(obj->getNomeAssicurazione()));
    lblNome->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QLabel* lblPrezzo = new QLabel(QString::number(obj->getPrezzo(), 'f', 2));
    lblPrezzo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    myButton* btnEdit = new myButton("Modifica");
    myButton* btnDelete = new myButton("Elimina");

    lytMain->addWidget(lblNome);
    lytMain->addWidget(lblPrezzo);
    lytMain->addWidget(btnEdit);
    lytMain->addWidget(btnDelete);

    connect(btnEdit, &QPushButton::clicked, this, &ListViewAssicurazioneItemWidget::ModificaSlot);
    connect(btnDelete, &QPushButton::clicked, this, &ListViewAssicurazioneItemWidget::EliminaSlot);
}

void ListViewAssicurazioneItemWidget::ModificaSlot() {
    emit ModificaSignal(obj);
}

void ListViewAssicurazioneItemWidget::EliminaSlot() {
    emit EliminaSignal(obj);
}

void ListViewAssicurazioneItemWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    emit VisualizzaSignal(obj);
}