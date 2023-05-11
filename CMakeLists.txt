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

add_executable(Project main.cpp Model/hierarchy/Spedizione.cpp Model/hierarchy/Spedizione.h Model/SupportClasses/Address.cpp Model/SupportClasses/Address.h Model/SupportClasses/Package.cpp Model/SupportClasses/Package.h Model/SupportClasses/Stato.cpp Model/SupportClasses/Stato.h Model/SupportClasses/Filiale.cpp Model/SupportClasses/Filiale.h Model/hierarchy/SpedizionePremium.cpp Model/hierarchy/SpedizionePremium.h Collection/ArrayList.cpp Collection/ArrayList.h Librerie/DataPersistence.cpp Librerie/DataPersistence.h App/widgets/Pages/Home.cpp App/widgets/Pages/Home.h App/widgets/CustomWidgets/myButton.cpp App/widgets/CustomWidgets/myButton.h App/widgets/StackTracer.cpp App/widgets/StackTracer.h Librerie/FileManager.cpp Librerie/FileManager.h App/widgets/CustomWidgets/QLabelTitle.cpp App/widgets/CustomWidgets/QLabelTitle.h App/widgets/Visitor/Visitor.cpp App/widgets/Visitor/Visitor.h App/widgets/Pages/HierachyPages/HierachyPageInterface.cpp App/widgets/Pages/HierachyPages/HierachyPageInterface.h App/widgets/Pages/HierachyPages/SpedizionePremiumPage.cpp App/widgets/Pages/HierachyPages/SpedizionePremiumPage.h App/widgets/CustomWidgets/ListViewItemWidget.cpp App/widgets/CustomWidgets/ListViewItemWidget.h)
target_link_libraries(Project
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )