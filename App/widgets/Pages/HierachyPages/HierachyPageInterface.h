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
    const Spedizione* obj;
public:
    HierachyPageInterface(const Spedizione* = nullptr, QWidget* parent = nullptr);
public slots:
    void BackSlot();
    void ModificaSlot();
    void CreaSlot();
signals:
    void BackSignal();
    void ModificaSignal(const Spedizione* obj);
    void CreaSignal(const Spedizione* obj);
};


#endif //DUGO_PROGETTO_HIERACHYPAGEINTERFACE_H
