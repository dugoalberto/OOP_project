//
// Created by Alberto Dugo on 12/05/2023.
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

public:
    PackageWidgetBase(Package* = nullptr, bool toEdit = false, QWidget* parent = nullptr);
    Package* getPackage() const;
    virtual bool ConvalidaInput() const;
public slots:
    void textChangedSlot();
};


#endif //DUGO_PROGETTO_PACKAGEWIDGETBASE_H
