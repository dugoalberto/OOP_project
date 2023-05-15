//
// Created by utente on 10/05/2023.
//

#ifndef DUGO_PROGETTO_HIERACHYPAGEINTERFACE_H
#define DUGO_PROGETTO_HIERACHYPAGEINTERFACE_H

#include <QWidget>

class Spedizione;

class HierachyPageInterface : public QWidget{
    Q_OBJECT
private:
    Spedizione* obj;
public:
    HierachyPageInterface(Spedizione* = nullptr, QWidget* parent = nullptr);
public slots:
    void BackSlot();
    virtual void ModificaSlot();
    virtual void CreaSlot();
signals:
    void BackSignal();
    void ModificaSignal(Spedizione* obj);
    void CreaSignal(Spedizione* obj);
};


#endif //DUGO_PROGETTO_HIERACHYPAGEINTERFACE_H
