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

add_executable(Project main.cpp Model/Spedizione.cpp Model/Spedizione.h Model/Address.cpp Model/Address.h Model/Package.cpp Model/Package.h Model/Stato.cpp Model/Stato.h Model/Filiale.cpp Model/Filiale.h Model/SpedizionePremium.cpp Model/SpedizionePremium.h)
target_link_libraries(Project
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )