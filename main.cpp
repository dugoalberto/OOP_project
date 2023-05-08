#include <QApplication>
#include <QPushButton>
#include "Collection/ArrayList.cpp"
#include "App/windows/Home.h"
#include "App/widgets/StackTracer.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    StackTracer st(nullptr);
    st.resize(1000,600);
    st.show();
    return app.exec();
}
