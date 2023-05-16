#include <QApplication>
#include <QFile>
#include "src/Collection/ArrayList.cpp"
#include "src/App/widgets/StackTracer.h"
#include "src/Librerie/FileManager.h"
#include "src/Model/hierarchy/SpedizioneEconomica.h"
#include "src/Model/hierarchy/SpedizioneCargo.h"
#include "src/Model/hierarchy/SpedizioneInternazionale.h"
#include "src/Model/hierarchy/SpedizioneAssicurata.h"

#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {/*
    srand(time(0));
    int n = rand() % (9999-1000+1)+1000;
    SpedizionePremium *sp1 = new SpedizionePremium(n,
                                                   Address("Mario Rossi", "via esempio1", "Citta1", "C1", 1000, "IT"),
                                                   Address("Luisa Gialli", "via esempio2", "Citta2", "C2", 2000, "IT"),
                                                   Package("Esempio contenuto", 400, 50, 20),
                                                   Stato("In spedizione", Filiale("via f","citta f","cel f")),
                                                   "descrizione"
    );
    sp1->setOrario(2025,12,1,21,45);

    n = rand() % (9999-1000+1)+1000;
    SpedizioneEconomica *se1 = new SpedizioneEconomica(n,
                                                       Address("Marco Verdi", "via esempio3", "Citta3", "C3", 1000,
                                                               "IT"),
                                                       Address("Luisa Gialli", "via esempio4", "Citta4", "C4", 2000,
                                                               "IT"),
                                                       Package("Esempio contenuto economica", 40, 3, 2),
                                                       Stato("In partenza", Filiale("via f","citta f","cel f")),
                                                       "descrizione"
    );

    n = rand() % (9999-1000+1)+1000;
    SpedizioneCargo *sc1 = new SpedizioneCargo(n,
                                               Address("Marco Verdi", "via esempio5", "Citta5", "C5", 1000, "IT"),
                                               Address("Luisa Gialli", "via esempio6", "Citta6", "C6", 2000, "IT"),
                                               Package("Esempio contenuto economica", 40, 3, 2),
                                               Stato("Consegnato", Filiale("via f","citta f","cel f")),
                                               "descrizione",
                                               SpedizioneCargo::TipologiaTrasporto::AEREO
    );

    n = rand() % (9999-1000+1)+1000;
    SpedizioneCargo *sc2 = new SpedizioneCargo(n,
                                               Address("Marco Verdi", "via esempio7", "Citta7", "C3", 1000, "IT"),
                                               Address("Luisa Gialli", "via esempio8", "Citta8", "C4", 2000, "IT"),
                                               Package("Esempio contenuto cargo", 40, 3, 2),
                                               Stato("In partenza", Filiale("via f","citta f","cel f")),
                                               "descrizione",
                                               SpedizioneCargo::TipologiaTrasporto(1)
    );

    n = rand() % (9999-1000+1)+1000;
    SpedizioneInternazionale *si1 = new SpedizioneInternazionale(n,
                                                                 Address("Marco Verdi", "via esempio3", "Citta3", "C3",
                                                                         1000,
                                                                         "FR"),
                                                                 Address("Luisa Gialli", "via esempio4", "Citta4", "C4",
                                                                         2000,
                                                                         "UK"),
                                                                 Package("Esempio contenuto internazionale", 40, 3, 2),
                                                                 Stato("Consegnato", Filiale("via f","citta f","cel f")),
                                                                 "descrizione"
    );

    n = rand() % (9999-1000+1)+1000;
    SpedizioneInternazionale *si2 = new SpedizioneInternazionale(n,
                                                                 Address("Marco Verdi", "via esempio3", "Citta3", "C3",
                                                                         1000,
                                                                         "BA"),
                                                                 Address("Luisa Gialli", "via esempio4", "Citta4", "C4",
                                                                         2000,
                                                                         "BB"),
                                                                 Package("Esempio contenuto internazionale", 40, 3, 2),
                                                                 Stato("In filiale", Filiale("via f","citta f","cel f")),
                                                                 "descrizione"
    );

    n = rand() % (9999-1000+1)+1000;
    SpedizioneAssicurata *sa1 = new SpedizioneAssicurata(n,
                                                         Address("Marco Verdi", "via esempio3", "Citta3", "C3", 1000,
                                                                 "BA"),
                                                         Address("Luisa Gialli", "via esempio4", "Citta4", "C4", 2000,
                                                                 "BB"),
                                                         Package("Esempio contenuto internazionale", 40, 3, 2),
                                                         Stato("In filiale", Filiale("via f","citta f","cel f")),
                                                         "descrizione",
                                                         Assicurazione("Assicurazione Costosa", 101)
    );

    n = rand() % (9999-1000+1)+1000;
    SpedizioneAssicurata *sa2 = new SpedizioneAssicurata(n,
                                                         Address("Marco Verdi", "via esempio3", "Citta3", "C3", 1000,
                                                                 "BA"),
                                                         Address("Luisa Gialli", "via esempio4", "Citta4", "C4", 2000,
                                                                 "BB"),
                                                         Package("Esempio contenuto internazionale", 40, 3, 2),
                                                         Stato("Consegnato", Filiale("via f","citta f","cel f")),
                                                         "descrizione",
                                                         Assicurazione("Assicurazione Economica", 53)
    );
*/
    FileManager* fm = new FileManager("fileDiProva");
    ArrayList<Spedizione*> nuovo = fm->readSpedizioni();
    /*nuovo.add(sp1);
    nuovo.add(se1);
    nuovo.add(sc1);
    nuovo.add(sc2);
    nuovo.add(si1);
    nuovo.add(si2);
    nuovo.add(sa1);
    nuovo.add(sa2);*/
    fm->saveData(nuovo);

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("Assets/Icon/icon.png"));
    QFile stylesheet("styleFile.qss");
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));
    StackTracer st(nuovo, nullptr);
    st.resize(1000,600);
    st.setMinimumSize(1000,600);
    st.show();
    return app.exec();
}
