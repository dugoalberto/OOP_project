#include <QApplication>
#include <QPushButton>
#include "Collection/ArrayList.cpp"
#include "App/widgets/Home.h"
#include "App/widgets/StackTracer.h"
int main(int argc, char *argv[]) {
    ArrayList<SpedizionePremium> sptot;
    SpedizionePremium *sp1 = new SpedizionePremium();
    sptot.add(*sp1);
    sptot.getDim();
    sptot.get(1);
    QApplication app(argc, argv);
    StackTracer st(nullptr);
    st.resize(1000,600);
    st.show();
    return app.exec();
}
