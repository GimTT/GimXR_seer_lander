set(StartupOptions_SRC startup_options.cpp)
add_library(StartupOptions STATIC ${StartupOptions_SRC})
target_link_libraries(StartupOptions
    Qt5::Core
    Qt5::AxContainer
    Qt5::Gui
    Qt5::Widgets
    Qt5::WebEngineWidgets)
target_include_directories(StartupOptions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
