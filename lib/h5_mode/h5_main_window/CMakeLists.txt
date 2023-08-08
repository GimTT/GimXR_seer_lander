set(H5MainWindow_SRC h5_main_window.cpp)
add_library(H5MainWindow STATIC ${H5MainWindow_SRC})
target_link_libraries(H5MainWindow
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::WebEngineWidgets)
target_include_directories(H5MainWindow INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
