//
// Created by utente on 12/05/2023.
//

#ifndef DUGO_PROGETTO_LISTVIEWFILIALEITEMWIDGET_H
#define DUGO_PROGETTO_LISTVIEWFILIALEITEMWIDGET_H


#include <QWidget>
#include "../../../../Model/SupportClasses/Filiale.h"
#include "../MyButton.h"

class ListViewFilialeItemWidget : public QWidget{
Q_OBJECT
private:
    Filiale* obj;
public:
    ListViewFilialeItemWidget(Filiale*, QWidget* = nullptr);
    void mouseDoubleClickEvent(QMouseEvent *event);
public slots:
    void ModificaSlot();
    void EliminaSlot();
    signals:
    void VisualizzaSignal(Filiale*);
    void ModificaSignal(Filiale*);
    void EliminaSignal(Filiale*);
};


#endif //DUGO_PROGETTO_LISTVIEWFILIALEITEMWIDGET_H
