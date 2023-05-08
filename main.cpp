#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "Model/Address.h"
#include "Model/SpedizionePremium.h"
#include "Collection/ArrayList.h"
#include "Collection/ArrayList.cpp"
#include "App/windows/Home.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Home home(nullptr, Qt::WindowFlags());
    home.resize(1000, 600);
    home.show();
    return app.exec();
}
