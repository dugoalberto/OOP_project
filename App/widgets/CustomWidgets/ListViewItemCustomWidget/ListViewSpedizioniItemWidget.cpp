//
// Created by utente on 11/05/2023.
//

#include "ListViewSpedizioniItemWidget.h"

ListViewSpedizioniItemWidget::ListViewSpedizioniItemWidget(Spedizione *s, QWidget *parent) : QWidget(parent), obj(s){

    QHBoxLayout* lytMain = new QHBoxLayout(this);

    QLabel* lblSprite = new QLabel();

    lblSprite->setPixmap((new QPixmap(QString::fromStdString("../Assets/Sprite/"+obj->getTypeName()+".png")))->scaled(60,60));
    lblSprite->setObjectName("lblSprite");

    lblTrackingNumber = new QLabel(QString::number(obj->getTrakingNumber()));
    lblTrackingNumber->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    lblStato = new QLabel(QString::fromStdString(obj->getStato().getDescStato()));
    lblStato->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    lblPrezzo = new QLabel(QString::number(obj->getCosto(), 'f', 2));
    lblPrezzo->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    lytMain->addWidget(lblSprite);
    lytMain->addWidget(lblTrackingNumber);
    lytMain->addWidget(lblStato);
    lytMain->addWidget(lblPrezzo);

    btnEdit = new MyButton("Modifica");
    btnDelete = new MyButton("Elimina");

    lytMain->addWidget(btnEdit);
    lytMain->addWidget(btnDelete);

    connect(btnEdit, &QPushButton::clicked, this, &ListViewSpedizioniItemWidget::ModificaSlot);
    connect(btnDelete, &QPushButton::clicked, this, &ListViewSpedizioniItemWidget::EliminaSlot);
}

void ListViewSpedizioniItemWidget::ModificaSlot() {
    emit ModificaSignal(obj);
}

void ListViewSpedizioniItemWidget::EliminaSlot() {
    emit EliminaSignal(obj);
}

void ListViewSpedizioniItemWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    emit VisualizzaSignal(obj);
}