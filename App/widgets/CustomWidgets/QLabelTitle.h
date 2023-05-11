//
// Created by utente on 10/05/2023.
//

#ifndef DUGO_PROGETTO_QLABELTITLE_H
#define DUGO_PROGETTO_QLABELTITLE_H


#include <QLabel>

class QLabelTitle : public QLabel{
Q_OBJECT
public:
    QLabelTitle(const std::string& str, QWidget* parent = nullptr) : QLabel(QString::fromStdString(str),parent) {}
};


#endif //DUGO_PROGETTO_QLABELTITLE_H
