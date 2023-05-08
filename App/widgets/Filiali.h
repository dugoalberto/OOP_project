//
// Created by Alberto Dugo on 06/05/23.
//

#ifndef PROJECT_FILIALI_H
#define PROJECT_FILIALI_H

#include <Qt>
#include <QLineEdit>
#include "myButton.h"
#include <QDialog>
#include <QLabel>

class Filiali : public QWidget{
    Q_OBJECT
private:
    QLineEdit *m_lineEdit;
    myButton *backHomeButton;
public:
    //TODO da modificare backHome, fargli il suo costruttore al posto di nullptr
    explicit Filiali(QWidget *parent = nullptr);
    myButton* getHomePageButton();
};


#endif //PROJECT_FILIALI_H
