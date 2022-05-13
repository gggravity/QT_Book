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
        Charts
        Network
        REQUIRED)

add_executable(cppguis main.cpp
        Q_runner_io.cpp Q_runner_io.h
        Worker_io.cpp Worker_io.h)

target_link_libraries(cppguis
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Sql
        Qt6::Charts
        Qt6::Network
        )

