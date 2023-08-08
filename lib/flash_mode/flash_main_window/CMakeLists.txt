set(FlashMainWindow_SRC flash_main_window.cpp)
add_library(FlashMainWindow STATIC ${FlashMainWindow_SRC})
target_link_libraries(FlashMainWindow
    Qt5::Core
    Qt5::AxContainer
    Qt5::Gui
    Qt5::Widgets
    Qt5::WebEngineWidgets)
target_include_directories(FlashMainWindow INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
