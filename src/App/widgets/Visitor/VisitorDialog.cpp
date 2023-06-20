//
// Created by Alberto Dugo on 24/05/2023.
//

#include "VisitorDialog.h"
#include "../CustomWidgets/CustomDialog/DialogFiliale.h"
#include "../CustomWidgets/CustomDialog/DialogAssicurazione.h"

void VisitorDialog::visit(const Filiale *f, bool toEdit) {
    dialog = new DialogFiliale(const_cast<Filiale*>(f), toEdit);
}

void VisitorDialog::visit(const Assicurazione *f, bool toEdit) {
    dialog = new DialogAssicurazione(const_cast<Assicurazione*>(f), toEdit);
}


QDialog* VisitorDialog::getWidget() const {
    return dialog;
}