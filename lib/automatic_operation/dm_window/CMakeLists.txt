set(DM_Window_SRC dm_window.cpp)
add_library(DM_Window STATIC ${DM_Window_SRC})
target_link_libraries(DM_Window
    Qt5::Core
    Qt5::AxContainer
    Qt5::Gui
    Qt5::Widgets
    Qt5::WebEngineWidgets)
target_include_directories(DM_Window INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})