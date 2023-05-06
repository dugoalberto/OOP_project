//
// Created by Alberto Dugo on 06/05/23.
//

#ifndef PROJECT_CREASPEDIZIONE_H
#define PROJECT_CREASPEDIZIONE_H


#include <Qt>
#include <QLineEdit>
#include "myButton.h"
#include <QDialog>
#include <QLabel>

class CreaSpedizione : public QWidget{
    Q_OBJECT
private:
    QLineEdit *m_lineEdit;
    myButton *backhome;
public:
    CreaSpedizione(QWidget *parent = nullptr);
};


#endif //PROJECT_CREASPEDIZIONE_H
