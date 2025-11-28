cmake_minimum_required(VERSION 3.16)

project(UserViewAndFilterModel_Example VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick Sql REQUIRED)

qt_add_executable(appUserViewAndFilterModel_Example
    main.cpp
)

qt_add_qml_module(appUserViewAndFilterModel_Example
    URI UserViewAndFilterModel_Example
    VERSION 1.0
    QML_FILES main.qml
    SOURCES user.h user.cpp
    SOURCES userviewmodel.h userviewmodel.cpp
    SOURCES userdatabasehandler.h userdatabasehandler.cpp
    SOURCES userfiltermodel.h userfiltermodel.cpp
    QML_FILES UserListView.qml
    SOURCES userdatamodel.h userdatamodel.cpp
    QML_FILES CustomSearchBar.qml
    RESOURCES
    RESOURCES
    RESOURCES Images/searchIcon.png
)

set_target_properties(appUserViewAndFilterModel_Example PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appUserViewAndFilterModel_Example
    PRIVATE
        Qt6::Quick
        Qt6::Sql
)

include(GNUInstallDirs)
install(TARGETS appUserViewAndFilterModel_Example
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
