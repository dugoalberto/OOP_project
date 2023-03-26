//
// Created by Alberto Dugo on 10/03/23.
//

#include "SpedizionePremium.h"

SpedizionePremium::SpedizionePremium(int trakingNumber, const Address &mittente, const Address &destinatario,
                                     const Package &pacco, int peso, double volume, const Stato &stato,
                                     const string &descrizione, double costo, int anno, int mese, int giorni, int ore, int minuti)
                                     :Spedizione(trakingNumber, mittente, destinatario, pacco, peso, volume, stato, descrizione, costo) {
    arrivo_tm.tm_year = anno - 1900; //l'anno è "shiftato" di 1900 in tm struct
    arrivo_tm.tm_mon = mese - 1; // partono da 0 in tm struct
    arrivo_tm.tm_mday = giorni;
    arrivo_tm.tm_hour = ore;
    arrivo_tm.tm_min = minuti;
}

void SpedizionePremium::setOrario(int year, int month, int day, int hours, int minuti) {
    //uso un target per simulare l'orario di arrivo senza modificare il precedente
    std::tm target_tm = {0};
    target_tm.tm_year = year - 1900;
    target_tm.tm_mon = month - 1;
    target_tm.tm_mday = day;
    target_tm.tm_hour = hours;
    target_tm.tm_min = minuti;
    std::time_t target = std::mktime(&target_tm);

    //lancio exc se orario di arrivo in passato
    if (std::difftime(target, tday) < 0) {
        throw std::invalid_argument("Invalid arrival time: cannot be in the past.");
    }
    //aggiorno l'orario di arrivo se non è stata lanciata exc
    this->arrivo_tm = target_tm;
}
/*
 * std::asctime` restituisce una stringa di caratteri terminata da un carattere di nuova linea,
 * quindi potresti voler rimuovere il carattere di nuova linea aggiungendo `.substr(0,24)`
 * alla fine della chiamata di `std::asctime` per ottenere solo la parte della stringa che rappresenta la data e l'ora.*/
ostream &operator<<(ostream &os, const SpedizionePremium &premium) {
    os << static_cast<const Spedizione &>(premium)
    << "\noridine: " << std::asctime(&premium.ordine_tm)
    << "arrivo: " <<std::asctime(&premium.arrivo_tm);
    return os;
}
