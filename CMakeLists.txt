cmake_minimum_required(VERSION 3.21)
project(Project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Project main.cpp src/Model/hierarchy/Spedizione.cpp src/Model/hierarchy/Spedizione.h src/Model/SupportClasses/Address.cpp src/Model/SupportClasses/Address.h src/Model/SupportClasses/Package.cpp src/Model/SupportClasses/Package.h src/Model/SupportClasses/Stato.cpp src/Model/SupportClasses/Stato.h src/Model/SupportClasses/Filiale.cpp src/Model/SupportClasses/Filiale.h src/Model/hierarchy/SpedizionePremium.cpp src/Model/hierarchy/SpedizionePremium.h src/Collection/ArrayList.cpp src/Collection/ArrayList.h src/App/widgets/Pages/Home.cpp src/App/widgets/Pages/Home.h src/App/widgets/CustomWidgets/MyButton.cpp src/App/widgets/CustomWidgets/MyButton.h src/App/widgets/StackTracer.cpp src/App/widgets/StackTracer.h src/Librerie/FileManager.cpp src/Librerie/FileManager.h src/App/widgets/CustomWidgets/QLabelTitle.cpp src/App/widgets/CustomWidgets/QLabelTitle.h src/App/widgets/Visitor/Visitor.cpp src/App/widgets/Visitor/Visitor.h src/App/widgets/Pages/HierachyPages/HierachyPageInterface.cpp src/App/widgets/Pages/HierachyPages/HierachyPageInterface.h src/App/widgets/Pages/HierachyPages/SpedizionePremiumPage.cpp src/App/widgets/Pages/HierachyPages/SpedizionePremiumPage.h src/App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewSpedizioniItemWidget.cpp src/App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewSpedizioniItemWidget.h src/Model/hierarchy/SpedizioneEconomica.cpp src/Model/hierarchy/SpedizioneEconomica.h src/Model/hierarchy/SpedizioneCargo.cpp src/Model/hierarchy/SpedizioneCargo.h src/Model/hierarchy/SpedizioneInternazionale.cpp src/Model/hierarchy/SpedizioneInternazionale.h src/Model/hierarchy/SpedizioneAssicurata.cpp src/Model/hierarchy/SpedizioneAssicurata.h src/Model/SupportClasses/Assicurazione.cpp src/Model/SupportClasses/Assicurazione.h src/App/widgets/CustomWidgets/AddressWidget.cpp src/App/widgets/CustomWidgets/AddressWidget.h src/App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetBase.cpp src/App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetBase.h src/App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetPremium.cpp src/App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetPremium.h src/App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetCargo.cpp src/App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetCargo.h src/App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetAssicurata.cpp src/App/widgets/CustomWidgets/PackageWidgetFolder/PackageWidgetAssicurata.h src/App/widgets/Pages/HierachyPages/SpedizioneAssicurataPage.cpp src/App/widgets/Pages/HierachyPages/SpedizioneAssicurataPage.h src/App/widgets/Pages/SelezioneTipoPage.cpp src/App/widgets/Pages/SelezioneTipoPage.h src/App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewAssicurazioneItemWidget.cpp src/App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewAssicurazioneItemWidget.h src/App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewFilialeItemWidget.cpp src/App/widgets/CustomWidgets/ListViewItemCustomWidget/ListViewFilialeItemWidget.h src/App/widgets/Visitor/VisitorById.cpp src/App/widgets/Visitor/VisitorById.h src/App/widgets/Pages/HierachyPages/SpedizioneInternazionalePage.cpp src/App/widgets/Pages/HierachyPages/SpedizioneInternazionalePage.h src/App/widgets/Pages/HierachyPages/SpedizioneCargoPage.cpp src/App/widgets/Pages/HierachyPages/SpedizioneCargoPage.h src/App/widgets/Pages/HierachyPages/SpedizioneEconomicaPage.cpp src/App/widgets/Pages/HierachyPages/SpedizioneEconomicaPage.h)
target_link_libraries(Project
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})