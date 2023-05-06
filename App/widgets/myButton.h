//
// Created by Alberto Dugo on 03/05/23.
//

#ifndef PROJECT_MYBUTTON_H
#define PROJECT_MYBUTTON_H


#include <QPushButton>
#include <QVBoxLayout>
#include <QFrame>

class myButton: public QPushButton{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
public:
    explicit myButton(QWidget *parent = nullptr, QSize h  = QSize(0,0), const QString& objName = nullptr, const QString& nome = nullptr){
        setFixedSize(h);
        setObjectName(objName);
        layout = new QVBoxLayout(this);
        layout -> setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(this);
        frame -> setContentsMargins(0, 0, 0, 0);
        frameLayout = new QVBoxLayout(frame);
        frameLayout -> setContentsMargins(0, 0, 0, 0);
        layout -> addWidget(frame);
        setText(nome);
        setStyleSheet("QPushButton {"
                      "color: black;"
                      "border-width: 2px;"
                      "border-style: solid;"
                      "border-radius: 10px;"
                      "border-color: rgb(210, 210, 210);"
                      "background-color: rgb(245, 245, 245);"
                      "}"
                      "QPushButton:hover {"
                      "border-style: outset;"
                      "}"
                      "QPushButton:pressed {"
                      "border-style: inset;"
                      "}");
    }
};
#endif //PROJECT_MYBUTTON_H
