//
// Created by utente on 11/05/2023.
//

#ifndef DUGO_PROGETTO_LISTVIEWSPEDIZIONIITEMWIDGET_H
#define DUGO_PROGETTO_LISTVIEWSPEDIZIONIITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "../../../Model/hierarchy/Spedizione.h"
#include "myButton.h"

class ListViewSpedizioniItemWidget : public QWidget {
    Q_OBJECT
private:
    Spedizione* obj;
    QLabel* lblTrackingNumber;
    QLabel* lblStato;
    QLabel* lblPrezzo;

    myButton* btnEdit;
    myButton* btnDelete;
public:
    ListViewSpedizioniItemWidget(Spedizione*, QWidget* = nullptr);
    void mouseDoubleClickEvent(QMouseEvent *event);
public slots:
    void ModificaSlot();
    void EliminaSlot();
signals:
    void VisualizzaSignal(const Spedizione*);
    void ModificaSignal(Spedizione*);
    void EliminaSignal(const Spedizione*);
};


#endif //DUGO_PROGETTO_LISTVIEWSPEDIZIONIITEMWIDGET_H
