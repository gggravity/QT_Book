cmake_minimum_required(VERSION 3.22)
project(cppguis)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

add_executable(cppguis main.cpp Arguments_open.h)

target_link_libraries(cppguis
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Sql
        )

