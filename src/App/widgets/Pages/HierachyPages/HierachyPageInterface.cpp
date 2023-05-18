//
// Created by utente on 10/05/2023.
//
#include <iostream>
#include "HierachyPageInterface.h"
HierachyPageInterface::HierachyPageInterface(Spedizione *s, QWidget *parent) : QWidget(parent), obj(s){}

void HierachyPageInterface::BackSlot() {
    emit BackSignal();
}

void HierachyPageInterface::ModificaSlot() {
    emit ModificaSignal(obj);
}

void HierachyPageInterface::CreaSlot() {
    emit CreaSignal(obj);
}

void HierachyPageInterface::toHomeSlot() {
    emit toHomeSignal();
}