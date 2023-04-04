#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "Model/Address.h"
#include "Model/SpedizionePremium.h"
#include "Collection/ArrayList.h"
#include "Collection/ArrayList.cpp"
int main(int argc, char *argv[]) {
    std::time_t ordine = std::time(nullptr); //utilizzato per vedere in quanto tempo arriva il pacco, ordine è l'orario nel quale è stato ordinata la spedizione
    std::tm ordine_tm = *std::localtime(&ordine);
    std::time_t arrivo = std::time(nullptr); //orario è in secondi dall'epoch, con localtime lo trasformo in un formato più user-friendly
    std::tm arrivo_tm = *std::localtime(&arrivo);

    std::cout << std::asctime(&ordine_tm);
    int min = 15 , day = 2, hour = 12;
    arrivo_tm.tm_mday = ordine_tm.tm_mday + day;
    arrivo_tm.tm_min = ordine_tm.tm_min + min;
    arrivo_tm.tm_hour = ordine_tm.tm_hour + hour;

    Address addressMittente("nomeC","indirizzo", "città", "provincia", "nazione", 30030);
    Address addressDestinatario("nomeC","indirizzo", "città", "provincia", "nazione", 313032);
    Filiale filiale("citta", "provincia", "numerotel");
    Package package("contenuto", 12); //Contenuto, valore
    Stato stato("desctato", filiale);
    Spedizione spedizione(12231, addressMittente, addressDestinatario, package, 12, 12,stato,"provaSpedione", 123);
    SpedizionePremium spedizionePremium(12231, addressMittente, addressDestinatario, package, 12, 12,stato,"provaSpedione", 123, 2023,05,12,12,43);

    ArrayList<Spedizione> prova2(10);
    prova2.add(spedizione);
    prova2.add(spedizionePremium);
    cout << prova2.toString();
}
