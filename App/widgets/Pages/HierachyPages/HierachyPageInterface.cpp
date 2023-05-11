//
// Created by utente on 10/05/2023.
//
#include <iostream>
#include "HierachyPageInterface.h"
HierachyPageInterface::HierachyPageInterface(const Spedizione *s, QWidget *parent) : QWidget(parent), obj(s){}

void HierachyPageInterface::BackSlot() {
    emit BackSignal();
}

void HierachyPageInterface::ModificaSlot() {
    std::cout << "Damn modifica Slot" << std::endl;
    emit ModificaSignal(obj);
}

void HierachyPageInterface::CreaSlot() {
    emit CreaSignal(obj);
}