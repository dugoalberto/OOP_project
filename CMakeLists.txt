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

add_executable(Project main.cpp Model/hierarchy/Spedizione.cpp Model/hierarchy/Spedizione.h Model/SupportClasses/Address.cpp Model/SupportClasses/Address.h Model/SupportClasses/Package.cpp Model/SupportClasses/Package.h Model/SupportClasses/Stato.cpp Model/SupportClasses/Stato.h Model/SupportClasses/Filiale.cpp Model/SupportClasses/Filiale.h Model/hierarchy/SpedizionePremium.cpp Model/hierarchy/SpedizionePremium.h Collection/ArrayList.cpp Collection/ArrayList.h Librerie/DataPersistence.cpp Librerie/DataPersistence.h App/widgets/Home.cpp App/widgets/Home.h App/widgets/myButton.cpp App/widgets/myButton.h App/widgets/CreaSpedizione.cpp App/widgets/CreaSpedizione.h App/widgets/SpedizioniTotali.cpp App/widgets/SpedizioniTotali.h App/widgets/Filiali.cpp App/widgets/Filiali.h App/widgets/StackTracer.cpp App/widgets/StackTracer.h App/widgets/SpedizioneWidget.cpp App/widgets/SpedizioneWidget.h Librerie/FileManager.cpp Librerie/FileManager.h)
target_link_libraries(Project
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )