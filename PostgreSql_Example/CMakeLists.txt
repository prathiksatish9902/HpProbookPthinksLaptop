cmake_minimum_required(VERSION 3.16)
project(QtPostgresBackend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Sql REQUIRED)

set(CMAKE_AUTOMOC ON)  # <-- important for QObject classes

add_executable(QtPostgresBackend
    main.cpp
    databasehandler.h
    databasehandler.cpp
)

target_link_libraries(QtPostgresBackend
    Qt6::Core
    Qt6::Sql
)
