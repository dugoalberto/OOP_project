#include <QApplication>
#include "Collection/ArrayList.cpp"
#include "App/widgets/StackTracer.h"
#include "Librerie/DataPersistence.h"
#include "Librerie/FileManager.h"
int main(int argc, char *argv[]) {
    SpedizionePremium *sp1 = new SpedizionePremium(1,
                                                   Address("Mario Rossi","via esempio1", "Citta1", "C1", "IT", 1000),
                                                   Address("Luisa Gialli", "via esempio2", "Citta2", "C2", "IT", 2000),
                                                   Package("Esempio contenuto", 400), 50, 20,
                                                   Stato("in spedizione", Filiale("via filiale", "citta filiale", "numero tel filiale")),
                                                   "esempio descrizione");
    sp1->setOrario(2025,12,1,21,45);

    FileManager* fm = new FileManager("fileDiProva");
    ArrayList<Spedizione*> nuovo = fm->readFromFile();
    nuovo.add(sp1);
    fm->saveData(nuovo);

    QApplication app(argc, argv);
    StackTracer st(nullptr);
    st.resize(1000,600);
    st.show();
    return app.exec();
}
