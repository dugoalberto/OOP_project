#include <QApplication>
#include <QPushButton>
#include <iostream>


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

    std::cout << std::asctime(&arrivo_tm);
    std::cout << "il tuo pacco arriva tra: " << day<<" days , and " << hour <<':'<<min <<" hours";

}
