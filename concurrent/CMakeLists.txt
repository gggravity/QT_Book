cmake_minimum_required(VERSION 3.22)
project(cppguis)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.78.0 COMPONENTS
        filesystem
        regex)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        Charts
        Network
        REQUIRED)

add_executable(cppguis
        main.cpp
        Worker_generic_callback.h
        Worker_generic_callback.cpp
        Q_runner_generic_callback.h
        Q_runner_generic_callback.cpp
        )

target_link_libraries(cppguis
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Sql
        Qt6::Charts
        Qt6::Network
        )

