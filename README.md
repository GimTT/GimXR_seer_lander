# 项目名称
GimXR赛尔号登陆器
# 开发环境
MSVC2017@32bit
QT5
CMake
# 调试
请在该级目录外新建一级目录以进行调试，并且需要将文件夹lander放到可执行文件同一目录下，并添加dll文件。

# 脚本命令
## 链接DLL文件
./windeployqt E:\GimXR_Workspace\GimXR_seer_lander\build-seer_lander-Desktop_Qt_5_12_5_MSVC2017_32bit-Release\seer_lander.exe

## H5模式的ui转化
### 主界面
.\uic E:\GimXR_Workspace\GimXR_seer_lander\gim-tt_seer_lander\lib\h5_mode\h5_main_window\h5_main_window_ui.ui -o E:\GimXR_Workspace\GimXR_seer_lander\gim-tt_seer_lander\lib\h5_mode\h5_main_window\h5_main_window_ui.h

## FLASH模式的ui转化
### 主界面
.\uic E:\GimXR_Workspace\GimXR_seer_lander\gim-tt_seer_lander\lib\flash_mode\flash_main_window\flash_main_window_ui.ui -o E:\GimXR_Workspace\GimXR_seer_lander\gim-tt_seer_lander\lib\flash_mode\flash_main_window\flash_main_window_ui.h

### 变速器
.\uic E:\GimXR_Workspace\GimXR_seer_lander\gim-tt_seer_lander\lib\flash_mode\flash_speed_ctrller\flash_speed_ctrller_ui.ui -o E:\GimXR_Workspace\GimXR_seer_lander\gim-tt_seer_lander\lib\flash_mode\flash_speed_ctrller\flash_speed_ctrller_ui.h
