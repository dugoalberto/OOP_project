//
// Created by Alberto Dugo on 02/05/23.
//

#ifndef PROJECT_HOME_H
#define PROJECT_HOME_H


#include <QMainWindow>
#include <QVBoxLayout>
#include "SpedizioneButton.h"
#include "StatoSpedizioneButton.h"

class Home : public QMainWindow{
Q_OBJECT
private:
    SpedizioneButton *spedizioneButton;
    StatoSpedizioneButton *statoSpedizioneButton;
public:
    Home(QWidget *parent, const Qt::WindowFlags &flags) : QMainWindow(parent, flags){
        spedizioneButton = new SpedizioneButton();
        statoSpedizioneButton = new StatoSpedizioneButton();
        setCentralWidget(new QWidget(this));
        QVBoxLayout *layout = new QVBoxLayout(centralWidget());
        layout->addWidget(spedizioneButton);
        layout->addWidget(statoSpedizioneButton);
    }
};


#endif //PROJECT_HOME_H
