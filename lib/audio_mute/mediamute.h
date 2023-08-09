#ifndef __MEDIAMUTE_H__
#define __MEDIAMUTE_H__

#include "Mmdeviceapi.h"
#include "Audiopolicy.h"
#include "../../lander_conf.h"

class MediaMute
{
    public:
        MediaMute();
        bool SetMute(bool mute);//设置静音    
        bool UnMute();//释放
};

#endif
