//测试(老板)模式
#define TEST_MODE   1

#if TEST_MODE
    #define FLASH_MODE_URL          ("http://www.baidu.com/")
#else
    #define FLASH_MODE_URL          ("http://seer.61.com/play.shtml")
#endif

#if TEST_MODE
    #define H5_MODE_URL             ("http://www.baidu.com/")
#else
    #define H5_MODE_URL             ("http://seerh5.61.com/")
#endif

#if TEST_MODE
    #define SEER_LANDER_H5_LOGO     ("")
    #define SEER_LANDER_FLASH_LOGO  ("")
#else
    #define SEER_LANDER_H5_LOGO     ("./lander/startup/H5_Logo.png")
    #define SEER_LANDER_FLASH_LOGO  ("./lander/startup/FLASH_Logo.png")
#endif

#define SPEED_CTRLLER_DLL_PATH      ("./lander/bin/SpeedControl.dll")
#define DM_DLL_PATH                 ("./lander/bin/dm.dll")
#define DM_REG_DLL_PATH             ("./lander/bin/RegDll.dll")
