//
// Created by utente on 12/05/2023.
//

#ifndef DUGO_PROGETTO_LISTVIEWASSICURAZIONEITEMWIDGET_H
#define DUGO_PROGETTO_LISTVIEWASSICURAZIONEITEMWIDGET_H


#include <QWidget>
#include "../../../../Model/SupportClasses/Assicurazione.h"

class ListViewAssicurazioneItemWidget : public QWidget{
    Q_OBJECT
private:
    Assicurazione* obj;
public:
    ListViewAssicurazioneItemWidget(Assicurazione*, QWidget* parent = nullptr);
    void mouseDoubleClickEvent(QMouseEvent *event);
public
    slots:
    void ModificaSlot();
    void EliminaSlot();
signals:
    void VisualizzaSignal(Assicurazione*);
    void ModificaSignal(Assicurazione*);
    void EliminaSignal(Assicurazione*);
};


#endif //DUGO_PROGETTO_LISTVIEWASSICURAZIONEITEMWIDGET_H
