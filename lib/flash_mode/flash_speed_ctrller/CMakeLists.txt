set(FlashSpeedCtrller_SRC flash_speed_ctrller.cpp)
add_library(FlashSpeedCtrller STATIC ${FlashSpeedCtrller_SRC})
target_link_libraries(FlashSpeedCtrller
    Qt5::Core
    Qt5::AxContainer
    Qt5::Gui
    Qt5::Widgets
    Qt5::WebEngineWidgets)
target_include_directories(FlashSpeedCtrller INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})