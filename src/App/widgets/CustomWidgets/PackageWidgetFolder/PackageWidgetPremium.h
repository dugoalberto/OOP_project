//
// Created by utente on 12/05/2023.
//

#ifndef DUGO_PROGETTO_PACKAGEWIDGETPREMIUM_H
#define DUGO_PROGETTO_PACKAGEWIDGETPREMIUM_H


#include <QComboBox>
#include "PackageWidgetBase.h"

class PackageWidgetPremium : public PackageWidgetBase{
private:
    QComboBox* txtGiorno;
    QComboBox* txtMese;
    QComboBox* txtAnno;
    QComboBox* txtOre;
    QComboBox* txtMinuti;
public:
    PackageWidgetPremium(Package* = nullptr, std::vector<int> dataOra = std::vector<int>{-1,-1,-1,-1,-1}, bool = false, QWidget* = nullptr);

    QComboBox *getTxtGiorno() const;

    QComboBox *getTxtMese() const;

    QComboBox *getTxtAnno() const;

    QComboBox *getTxtOre() const;

    QComboBox *getTxtMinuti() const;

    bool ConvalidaInput() const override;

public slots:
    void textChangedSlot();

};


#endif //DUGO_PROGETTO_PACKAGEWIDGETPREMIUM_H
