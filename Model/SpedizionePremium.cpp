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
