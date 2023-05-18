//
// Created by Alberto Dugo on 10/03/23.
//

#include "SpedizionePremium.h"
std::string SpedizionePremium::typeName = "SPEDIZIONEPREMIUM";

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

    /*
    //uso un target per simulare l'orario di arrivo senza modificare il precedente
    std::tm target_tm = {0};
    target_tm.tm_year = year;
    target_tm.tm_mon = month;
    target_tm.tm_mday = day;
    target_tm.tm_hour = hours;
    target_tm.tm_min = minuti;
    std::time_t target = std::mktime(&target_tm);

    //lancio exc se orario di arrivo in passato
    if (std::difftime(target, tday) < 0) {
        throw std::invalid_argument("Invalid arrival time: cannot be in the past.");
    }
    //aggiorno l'orario di arrivo se non è stata lanciata exc
    this->arrivo_tm = target_tm;*/
    arrivo_tm.tm_year = year;
    arrivo_tm.tm_mon = month;
    arrivo_tm.tm_mday = day;
    arrivo_tm.tm_hour = hours;
    arrivo_tm.tm_min = minuti;
}
/*
 * std::asctime` restituisce una stringa di caratteri terminata da un carattere di nuova linea,
 * quindi potresti voler rimuovere il carattere di nuova linea aggiungendo `.substr(0,24)`
 * alla fine della chiamata di `std::asctime` per ottenere solo la parte della stringa che rappresenta la data e l'ora.*/

/*
ostream &operator<<(ostream &os, const SpedizionePremium &premium) {
    os << static_cast<const Spedizione &>(premium)
    << "\noridine: " << std::asctime(&premium.ordine_tm)
    << "arrivo: " <<std::asctime(&premium.arrivo_tm);
    return os;
}*/

SpedizionePremium::~SpedizionePremium() {}
/*
json SpedizionePremium::objectToJson() {
    json j;
    j.merge_patch(Spedizione::objectToJson()) ;

    std::stringstream buffer;
    buffer << std::put_time(&arrivo_tm, "%Y-%m-%d %H:%M:%S");
    std::string str = buffer.str();
    j["arrivo"] = str;
    return j;
}

SpedizionePremium* SpedizionePremium::jsonToObject(const json &dati) {
    return new SpedizionePremium(dati["trakingNumber"], Address::jsonToObject(dati["mittente"]), Address::jsonToObject(dati["destinatario"]), Package::jsonToObject(dati["pacco"]), dati["peso"], dati["volume"], Stato::jsonToObject(dati["stato"]), dati["descrizione"],std::stoi(dati["arrivo"].get<std::string>().substr(0,4)),std::stoi(dati["arrivo"].get<std::string>().substr(5,2)),std::stoi(dati["arrivo"].get<std::string>().substr(8,2)),std::stoi(dati["arrivo"].get<std::string>().substr(11,2)),std::stoi(dati["arrivo"].get<std::string>().substr(14,2)));
}*/

float SpedizionePremium::getCosto() const {
    return 50;
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

std::string SpedizionePremium::getTypeName() const {
    return typeName;
}

void SpedizionePremium::Accept(Visitor *visitor, bool toEdit) const {
    visitor->visit(this, toEdit);
}

std::vector<int> SpedizionePremium::getOrario() const {
    return std::vector<int>{arrivo_tm.tm_mday, arrivo_tm.tm_mon, arrivo_tm.tm_year, arrivo_tm.tm_hour, arrivo_tm.tm_min};
}

void SpedizionePremium::modifica(Spedizione *spe) {
    Spedizione::modifica(spe);
    std::vector<int> res = (dynamic_cast<SpedizionePremium*>(spe))->getOrario();
    setOrario(res[2],res[1],res[0],res[3],res[4]);
}