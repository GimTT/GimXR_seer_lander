set(DM_SRC dm.cpp)
add_library(DM STATIC ${DM_SRC})
target_link_libraries(DM
    Qt5::Core
    Qt5::AxContainer
    Qt5::Gui
    Qt5::Widgets
    Qt5::WebEngineWidgets)
target_include_directories(DM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})