//
// Created by Alberto Dugo on 10/03/23.
//

#include "SpedizionePremium.h"

SpedizionePremium::SpedizionePremium(int trakingNumber, const Address &mittente, const Address &destinatario,
                                     const Package &pacco, int peso, double volume, const Stato &stato,
                                     const string &descrizione, double costo, int year, int month, int day, int hours, int minutes)
                                     :Spedizione(trakingNumber, mittente, destinatario, pacco, peso, volume, stato, descrizione, costo) {
    /*orario_tm.tm_year = year - 1900;
    orario_tm.tm_mon = month - 1;
    orario_tm.tm_mday = day;
    orario_tm.tm_hour = hours;
    orario_tm.tm_min = minutes;*/

}
