//
// Created by Alberto Dugo on 10/03/23.
//

#include "SpedizionePremium.h"
std::string SpedizionePremium::typeName = "SPEDIZIONEPREMIUM";
float SpedizionePremium::baseCost = 9.99f;

SpedizionePremium::SpedizionePremium(int trakingNumber, Address *mittente, Address *destinatario,
                                     Package *pacco, Stato *stato, const string &descrizione, int anno,
                                     int meseanno, int giornianno, int oreanno, int minutianno)
                                     : Spedizione(trakingNumber, mittente, destinatario, pacco, stato, descrizione) {
    if(anno != -1){
        arrivo_tm.tm_year = anno; //l'anno è "shiftato" di 1900 in tm struct
        arrivo_tm.tm_mon = meseanno; // partono da 0 in tm struct
        arrivo_tm.tm_mday = giornianno;
        arrivo_tm.tm_hour = oreanno;
        arrivo_tm.tm_min = minutianno;
    }else{
        arrivo_tm.tm_year += 1900; //l'anno è "shiftato" di 1900 in tm struct
        arrivo_tm.tm_mon += 1; // partono da 0 in tm struct
    }
}

void SpedizionePremium::setOrario(int year, int month, int day, int hours, int minuti) {
    arrivo_tm.tm_year = year;
    arrivo_tm.tm_mon = month;
    arrivo_tm.tm_mday = day;
    arrivo_tm.tm_hour = hours;
    arrivo_tm.tm_min = minuti;
}

SpedizionePremium::~SpedizionePremium() {}

float SpedizionePremium::getCosto() const {
    return baseCost;
}

std::string SpedizionePremium::toSaveFormat() const {
    std::string res =
    typeName + Spedizione::SEPARATOR +
    Spedizione::toSaveFormat() + SEPARATOR +
    std::to_string(ordine_tm.tm_year) + SEPARATOR +
    std::to_string(ordine_tm.tm_mon) + SEPARATOR +
    std::to_string(ordine_tm.tm_mday) + SEPARATOR +
    std::to_string(ordine_tm.tm_hour) + SEPARATOR +
    std::to_string(ordine_tm.tm_min) + SEPARATOR +
    std::to_string(arrivo_tm.tm_year) + SEPARATOR +
    std::to_string(arrivo_tm.tm_mon) + SEPARATOR +
    std::to_string(arrivo_tm.tm_mday) + SEPARATOR +
    std::to_string(arrivo_tm.tm_hour) + SEPARATOR +
    std::to_string(arrivo_tm.tm_min)
    ;
    return res;
}

json SpedizionePremium::toSaveFormat(int) const {
    json jsonData = Spedizione::toSaveFormat(1);

    jsonData["TypeName"] = typeName;
    jsonData["ordine_data"] = {
            {"anno", ordine_tm.tm_year},
            {"mese", ordine_tm.tm_mon},
            {"giorno", ordine_tm.tm_mday},
            {"ora", ordine_tm.tm_hour},
            {"minuti", ordine_tm.tm_min}
    };

    jsonData["arrivo_data"] = {
            {"anno", arrivo_tm.tm_year},
            {"mese", arrivo_tm.tm_mon},
            {"giorno", arrivo_tm.tm_mday},
            {"ora", arrivo_tm.tm_hour},
            {"minuti", arrivo_tm.tm_min}
    };

    return jsonData;
}

void SpedizionePremium::Accept(Visitor *visitor, bool toEdit) const {
    visitor->visit(this, toEdit);
}

void SpedizionePremium::Accept(VisitorForClassName *visitor) const {
    visitor->visit(this);
}

std::vector<int> SpedizionePremium::getOrario() const {
    return std::vector<int>{arrivo_tm.tm_mday, arrivo_tm.tm_mon, arrivo_tm.tm_year, arrivo_tm.tm_hour, arrivo_tm.tm_min};
}

void SpedizionePremium::copy(Spedizione *spe) {
    Spedizione::copy(spe);
    std::vector<int> res = (dynamic_cast<SpedizionePremium*>(spe))->getOrario();
    setOrario(res[2],res[1],res[0],res[3],res[4]);
}