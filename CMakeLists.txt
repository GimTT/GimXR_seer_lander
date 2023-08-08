cmake_minimum_required(VERSION 3.5)

project(seer_lander LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS
        Core
        AxContainer
        Gui
        Widgets
        WebEngineWidgets
        REQUIRED)

add_subdirectory(lib/startup_options)
add_subdirectory(lib/h5_mode/h5_main_window)
add_subdirectory(lib/flash_mode/flash_main_window)
add_subdirectory(lib/audio_mute)

add_executable(seer_lander WIN32 main.cpp)

target_link_libraries(seer_lander
        Qt5::Core
        Qt5::AxContainer
        Qt5::Gui
        Qt5::Widgets
        Qt5::WebEngineWidgets)


target_link_libraries(seer_lander StartupOptions)
target_link_libraries(seer_lander AudioMute)
target_link_libraries(seer_lander H5MainWindow)
target_link_libraries(seer_lander FlashMainWindow)
