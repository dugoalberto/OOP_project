//
// Created by utente on 12/05/2023.
//

#ifndef DUGO_PROGETTO_PACKAGEWIDGETPREMIUM_H
#define DUGO_PROGETTO_PACKAGEWIDGETPREMIUM_H


#include "PackageWidgetBase.h"

class PackageWidgetPremium : public PackageWidgetBase{
private:
    QLineEdit* txtGiorno;
    QLineEdit* txtMese;
    QLineEdit* txtAnno;
    QLineEdit* txtOre;
    QLineEdit* txtMinuti;
public:
    PackageWidgetPremium(Package* = nullptr, std::vector<int> dataOra = std::vector<int>{-1,-1,-1,-1,-1}, bool = false, QWidget* = nullptr);

    QLineEdit *getTxtGiorno() const;

    QLineEdit *getTxtMese() const;

    QLineEdit *getTxtAnno() const;

    QLineEdit *getTxtOre() const;

    QLineEdit *getTxtMinuti() const;

    bool ConvalidaInput() const override;

public slots:
    void textChangedSlot();

};


#endif //DUGO_PROGETTO_PACKAGEWIDGETPREMIUM_H
