//
// Created by Alberto Dugo on 12/05/2023.
//

#include <QHBoxLayout>
#include <QLabel>
#include "ListViewAssicurazioneItemWidget.h"
#include "../MyButton.h"

ListViewAssicurazioneItemWidget::ListViewAssicurazioneItemWidget(Assicurazione *ass, QWidget *parent) : QWidget(parent), obj(ass){
    QHBoxLayout* lytMain = new QHBoxLayout(this);

    QLabel* lblNome = new QLabel(QString::fromStdString(obj->getNomeAssicurazione()));
    lblNome->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QLabel* lblPrezzo = new QLabel(QString::number(obj->getPrezzo(), 'f', 2));
    lblPrezzo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    MyButton* btnEdit = new MyButton("Modifica");
    MyButton* btnDelete = new MyButton("Elimina");

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