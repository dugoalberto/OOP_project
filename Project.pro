QT += core widgets
CONFIG += c++11

OBJECTS_DIR = build/qmake
RCC_DIR = build/qmake/rcc
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
DESTDIR = ./

SOURCES += \
    main.cpp \
    Model/hierarchy/Spedizione.cpp \
    Model/SupportClasses/Address.cpp \
    Model/SupportClasses/Package.cpp \
    Model/SupportClasses/Stato.cpp \
    Model/SupportClasses/Filiale.cpp \
    Model/hierarchy/SpedizionePremium.cpp \
    Collection/ArrayList.cpp \
    Librerie/DataPersistence.cpp \
    App/widgets/Pages/Home.cpp \
    App/widgets/CustomWidgets/MyButton.cpp \
    App/widgets/StackTracer.cpp \
    Librerie/FileManager.cpp \
    App/widgets/CustomWidgets/QLabelTitle.cpp \
    App/widgets/Visitor/Visitor.cpp \
    App/widgets/Pages/HierachyPages/HierachyPageInterface.cpp \
    App/widgets/Pages/HierachyPages/SpedizionePremiumPage.cpp \
    App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewSpedizioniItemWidget.cpp \
    Model/hierarchy/SpedizioneEconomica.cpp \
    Model/hierarchy/SpedizioneCargo.cpp \
    Model/hierarchy/SpedizioneInternazionale.cpp \
    Model/hierarchy/SpedizioneAssicurata.cpp \
    Model/SupportClasses/Assicurazione.cpp \
    App/widgets/CustomWidgets/AddressWidget.cpp \
    App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetBase.cpp \
    App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetPremium.cpp \
    App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetCargo.cpp \
    App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetAssicurata.cpp \
    App/widgets/Pages/HierachyPages/SpedizioneAssicurataPage.cpp \
    App/widgets/Pages/SelezioneTipoPage.cpp \
    App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewAssicurazioneItemWidget.cpp \
    App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewFilialeItemWidget.cpp

HEADERS += \
    Model/hierarchy/Spedizione.h \
    Model/SupportClasses/Address.h \
    Model/SupportClasses/Package.h \
    Model/SupportClasses/Stato.h \
    Model/SupportClasses/Filiale.h \
    Model/hierarchy/SpedizionePremium.h \
    Collection/ArrayList.h \
    Librerie/DataPersistence.h \
    App/widgets/Pages/Home.h \
    App/widgets/CustomWidgets/MyButton.h \
    App/widgets/StackTracer.h \
    Librerie/FileManager.h \
    App/widgets/CustomWidgets/QLabelTitle.h \
    App/widgets/Visitor/Visitor.h \
    App/widgets/Pages/HierachyPages/HierachyPageInterface.h \
    App/widgets/Pages/HierachyPages/SpedizionePremiumPage.h \
    App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewSpedizioniItemWidget.h \
    Model/hierarchy/SpedizioneEconomica.h \
    Model/hierarchy/SpedizioneCargo.h \
    Model/hierarchy/SpedizioneInternazionale.h \
    Model/hierarchy/SpedizioneAssicurata.h \
    Model/SupportClasses/Assicurazione.h \
    App/widgets/CustomWidgets/AddressWidget.h \
    App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetBase.h \
    App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetPremium.h \
    App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetCargo.h \
    App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetAssicurata.h \
    App/widgets/Pages/HierachyPages/SpedizioneAssicurataPage.h \
    App/widgets/Pages/SelezioneTipoPage.h \
    App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewAssicurazioneItemWidget.h \
    App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewFilialeItemWidget.h

LIBS += -L$$[QT_INSTALL_LIBS] -lQt6Core -lQt6Gui -lQt6Widgets
