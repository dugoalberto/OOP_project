//
// Created by Alberto Dugo on 10/05/2023.
//

#ifndef DUGO_PROGETTO_HIERACHYPAGEINTERFACE_H
#define DUGO_PROGETTO_HIERACHYPAGEINTERFACE_H

#include <QWidget>

class Spedizione;

class HierachyPageInterface : public QWidget{
    Q_OBJECT
protected:
    Spedizione* obj;
public:
    HierachyPageInterface(Spedizione* = nullptr, QWidget* parent = nullptr);
public slots:
    void BackSlot();
    void toHomeSlot();
    virtual void ModificaSlot();
    virtual void CreaSlot();
signals:
    void BackSignal();
    void ModificaSignal(Spedizione* obj);
    void CreaSignal(Spedizione* obj);
    void toHomeSignal();
};


#endif //DUGO_PROGETTO_HIERACHYPAGEINTERFACE_H
