#include <QApplication>
#include <QFile>
#include "Collection/ArrayList.cpp"
#include "App/widgets/StackTracer.h"
#include "Librerie/DataPersistence.h"
#include "Librerie/FileManager.h"

#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {
    srand(time(0));
    int n = rand() % (9999-1000+1)+1000;
    SpedizionePremium *sp1 = new SpedizionePremium(n,
                                                   Address("Mario Rossi","via esempio1", "Citta1", "C1", "IT", 1000),
                                                   Address("Luisa Gialli", "via esempio2", "Citta2", "C2", "IT", 2000),
                                                   Package("Esempio contenuto", 400), 50, 20,
                                                   Stato("In spedizione", Filiale("via filiale", "citta filiale", "numero tel filiale")),
                                                   "esempio descrizione");
    sp1->setOrario(2025,12,1,21,45);

    FileManager* fm = new FileManager("fileDiProva");
    ArrayList<Spedizione*> nuovo = fm->readFromFile();
    nuovo.add(sp1);
    fm->saveData(nuovo);

    QApplication app(argc, argv);
    QFile stylesheet("../styleFile.qss");
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));
    StackTracer st(nuovo, nullptr);
    st.resize(1000,600);
    st.setMinimumSize(800,500);
    st.show();
    return app.exec();
}
