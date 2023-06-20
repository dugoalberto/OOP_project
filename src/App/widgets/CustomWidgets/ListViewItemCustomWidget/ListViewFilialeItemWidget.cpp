//
// Created by Alberto Dugo on 12/05/2023.
//

#include <QLabel>
#include "ListViewFilialeItemWidget.h"
#include <iostream>
ListViewFilialeItemWidget::ListViewFilialeItemWidget(Filiale* fil, QWidget* parent) : QWidget(parent), obj(fil) {
    QHBoxLayout* lytMain = new QHBoxLayout(this);

    QLabel* lblCitta = new QLabel(QString::fromStdString(obj->getCitta()));
    lblCitta->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QLabel* lblProvincia = new QLabel(QString::fromStdString(obj->getProvincia()));
    lblProvincia->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QLabel* lblTelefono = new QLabel(QString::fromStdString(obj->getNumeroTel()));
    lblTelefono->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    MyButton* btnEdit = new MyButton("Modifica");
    MyButton* btnDelete = new MyButton("Elimina");

    lytMain->addWidget(lblCitta);
    lytMain->addWidget(lblProvincia);
    lytMain->addWidget(lblTelefono);
    lytMain->addWidget(btnEdit);
    lytMain->addWidget(btnDelete);

    connect(btnEdit, &QPushButton::clicked, this, &ListViewFilialeItemWidget::ModificaSlot);
    connect(btnDelete, &QPushButton::clicked, this, &ListViewFilialeItemWidget::EliminaSlot);
}

void ListViewFilialeItemWidget::ModificaSlot() {
    emit ModificaSignal(obj);
}

void ListViewFilialeItemWidget::EliminaSlot() {
    emit EliminaSignal(obj);
}

void ListViewFilialeItemWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    emit VisualizzaSignal(obj);
}
