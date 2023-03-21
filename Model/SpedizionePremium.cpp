//
// Created by Alberto Dugo on 10/03/23.
//

#include "SpedizionePremium.h"

SpedizionePremium::SpedizionePremium(int trakingNumber, const Address &mittente, const Address &destinatario,
                                     const Package &pacco, int peso, double volume, const Stato &stato,
                                     const string &descrizione, double costo, int anno, int mese, int giorni, int ore, int minuti)
                                     :Spedizione(trakingNumber, mittente, destinatario, pacco, peso, volume, stato, descrizione, costo) {
    arrivo_tm.tm_year = anno - 1900;
    arrivo_tm.tm_mon = mese - 1;
    arrivo_tm.tm_mday = giorni;
    arrivo_tm.tm_hour = ore;
    arrivo_tm.tm_min = minuti;
}

void SpedizionePremium::setOrario(int year, int month, int day, int hours, int minuti) {
    std::time_t tday = std::time(nullptr); //orario di oggi, mi serve per vedere se cambia l'orario e lo mette nel passato
    //TODO provarlo con entrambe le versioni
    /*
    if( year < ordine_tm.tm_year || month < ordine_tm.tm_mon ||
        ( month == ordine_tm.tm_mon &&  day < ordine_tm.tm_mday) ) throw;*/
    if (std::difftime(std::mktime(&this->arrivo_tm), tday) < 0) {
        throw std::invalid_argument("Invalid arrival time: cannot be in the past.");
    }
    this->arrivo_tm.tm_year = year;
    this->arrivo_tm.tm_mon = month;
    this->arrivo_tm.tm_mday= day;
    this->arrivo_tm.tm_min = minuti;
}
