//
// Created by utente on 12/05/2023.
//

#ifndef DUGO_PROGETTO_PACKAGEWIDGETBASE_H
#define DUGO_PROGETTO_PACKAGEWIDGETBASE_H


#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "../../../../Model/SupportClasses/Package.h"

class PackageWidgetBase : public QWidget{
Q_OBJECT

    PackageWidgetBase() {}

protected:
    Package* package;
    QVBoxLayout* mainLyt;
    QLineEdit* txtContenuto;
    QLineEdit* txtValore;
    QLineEdit* txtPeso;
    QLineEdit* txtVolume;

    virtual bool ConvalidaInput() const;
public:
    PackageWidgetBase(Package* = nullptr, bool toEdit = false, QWidget* parent = nullptr);
    Package* getPackage() const;
};


#endif //DUGO_PROGETTO_PACKAGEWIDGETBASE_H
