//
// Created by Alberto Dugo on 06/05/23.
//

#ifndef PROJECT_SPEDIZIONITOTALI_H
#define PROJECT_SPEDIZIONITOTALI_H

#include <Qt>
#include <QLineEdit>
#include "myButton.h"
#include <QDialog>
#include <QLabel>

class SpedizioniTotali  : public QWidget{
    Q_OBJECT
private:
    QLineEdit *m_lineEdit;
    myButton *backhome;
public:
    explicit SpedizioniTotali(QWidget *parent = nullptr);
};



#endif //PROJECT_SPEDIZIONITOTALI_H
