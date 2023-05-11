//
// Created by utente on 11/05/2023.
//

#include "ListViewItemWidget.h"

ListViewItemWidget::ListViewItemWidget(Spedizione *s, QWidget *parent) : QWidget(parent), obj(s){

    QHBoxLayout* lytMain = new QHBoxLayout(this);

    QLabel* lblSprite = new QLabel();
    //TODO verificare che la spedizione sia di tipo cargo essendoci aereo e barca come sprite
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

    btnEdit = new myButton("Modifica");
    btnDelete = new myButton("Elimina");

    lytMain->addWidget(btnEdit);
    lytMain->addWidget(btnDelete);

    connect(btnEdit, &QPushButton::clicked, this, &ListViewItemWidget::ModificaSlot);
    connect(btnDelete, &QPushButton::clicked, this, &ListViewItemWidget::EliminaSlot);
}

void ListViewItemWidget::ModificaSlot() {
    emit ModificaSignal(obj);
}

void ListViewItemWidget::EliminaSlot() {
    emit EliminaSignal(obj);
}

void ListViewItemWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    emit VisualizzaSignal(obj);
}