cmake_minimum_required(VERSION 3.5)

project(PasswordApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

set(PROJECT_SOURCES
        main.cpp
        resources.qrc
        LoginWindow.cpp
        LoginWindow.h
        LoginWindow.ui
        Views/tourbook.cpp
        Views/tourbook.h
        Views/tourbook.ui
        Views/DashboardWindow.h Views/DashboardWindow.cpp Views/DashboardWindow.ui
        Views/Clients.h Views/Clients.cpp Views/Clients.ui
        Exceptions/UserNotFound.h Exceptions/BadRequest.h
        Utils/Logger.h Utils/Logger.cpp
        Utils/DatabaseManager.h Utils/DatabaseManager.cpp
        DAL/AuthDAL.h DAL/AuthDAL.cpp DAL/AuthDALInterface.h
        Services/AuthService.h Services/AuthService.cpp Services/AuthServiceInterface.h 
        Entity/UserEntity.h Entity/UserEntity.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PasswordApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PasswordApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PasswordApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PasswordApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(PasswordApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(PasswordApp PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS PrintSupport)
target_link_libraries(PasswordApp PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)

set_target_properties(PasswordApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS PasswordApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PasswordApp)
endif()
