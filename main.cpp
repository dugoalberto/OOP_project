#include <QApplication>
#include <QFile>
#include "src/Collection/ArrayList.cpp"
#include "src/App/widgets/StackTracer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("src/Assets/Icon/icon.png"));
    QFile stylesheet("styleFile.qss");
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));
    StackTracer st;
    st.resize(1000,600);
    st.setMinimumSize(1000,600);
    st.show();
    return app.exec();
}
