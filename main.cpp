#include <QApplication>
#include <QFile>
#include "src/Collection/ArrayList.cpp"
#include "src/App/widgets/StackTracer.h"

#include "src/Librerie/FileManagerJSON.h"

int main(int argc, char *argv[]) {
/*

    FileManager* fm = new FileManager("fileDiProva");
    ArrayList<Spedizione*>* lstElements = new ArrayList<Spedizione*>(fm->readSpedizioni());

    FileManagerJSON* fileJson = new FileManagerJSON("JSON_SAVE");
    ArrayList<Spedizione*>* lstDaJSON = new ArrayList<Spedizione*>(fileJson->readSpedizioni(1));
*/
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
