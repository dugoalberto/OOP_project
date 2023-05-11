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
    explicit myButton(const QString &text = nullptr, QWidget *parent = nullptr) {
        setText(text);
    }


};
#endif //PROJECT_MYBUTTON_H
