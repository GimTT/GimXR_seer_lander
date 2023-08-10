/***************************************************************************************************
                        Project                  :                  seer_lander
                        MCU                      :                  None
                        IDE                      :                  QT5(CMake+MSVC2017)
                        File                     :                  mutedsessionevents.h
                        Brief                    :                  音频控制锁相关
                        Developer                :                  金欣嵘
                        Other                    :                  移植自星夜bilibili专栏
====================================================================================================

====================================================================================================
                                              History
====================================================================================================
----------------------------------------------------------------------------------------------------
                                            Brief 补充注释
----------------------------------------------------------------------------------------------------
                        Branch                   :                  dev_h5_lander_mode
                        Commit                   :                  eebfe18f3
----------------------------------------------------------------------------------------------------
***************************************************************************************************/
#include "mediamute.h"
#include "mutedsessionevents.h"

static IMMDeviceEnumerator* m_pEnumerator = NULL;
static IMMDevice* m_pDeviceOut = NULL;
static IAudioSessionManager * m_AudioSessionManager = NULL;
static IAudioSessionControl * m_AudioSessionControl = NULL;
static CMutedSessionEvents * m_pMutedSessionEvents= NULL;

MediaMute::MediaMute()
{
    CoInitializeEx( NULL , COINIT_MULTITHREADED );
    HRESULT hr;
    //实例化 MMDeviceEnumerator 枚举器
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL,CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),(void**)&m_pEnumerator);

    // 默认设备的IMMDevice接口
    hr = m_pEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &m_pDeviceOut);

    // 得到音频会话接口IAudioSessionManager
    hr = m_pDeviceOut->Activate(__uuidof(m_AudioSessionManager), CLSCTX_ALL, NULL, (void**)&m_AudioSessionManager);

    // 设置会话(Session)参数
    hr = m_AudioSessionManager->GetAudioSessionControl(NULL,0,&m_AudioSessionControl);

    // 设置声音改变参数通知
    m_pMutedSessionEvents = new CMutedSessionEvents(m_AudioSessionManager);
    hr = m_AudioSessionControl->RegisterAudioSessionNotification(m_pMutedSessionEvents);

}

bool MediaMute::UnMute()
{
    // ---- 解注册声音改变参数通知
    if (m_AudioSessionControl != NULL && m_pMutedSessionEvents != NULL)
    {
        m_AudioSessionControl -> UnregisterAudioSessionNotification(m_pMutedSessionEvents);
    }

    // ---- 释放内存空间
    if (m_AudioSessionControl != NULL)
    {
        m_AudioSessionControl->Release();
        m_AudioSessionControl = NULL;
    }

    if (m_pMutedSessionEvents != NULL)
    {
        m_pMutedSessionEvents->Release();
        m_pMutedSessionEvents = NULL;
    }

    if (m_pDeviceOut != NULL)
    {
        m_pDeviceOut->Release();
        m_pDeviceOut = NULL;
    }
    if(m_AudioSessionManager != NULL)
    {
        m_AudioSessionManager->Release();
        m_AudioSessionManager = NULL;
    }
    if (m_pEnumerator != NULL)
    {
        m_pEnumerator->Release();
        m_pEnumerator = NULL;
    }
    CoUninitialize();
    return true;
}

bool MediaMute::SetMute(bool mute)
{
    HRESULT hr = S_FALSE;
    // 获得音量、静音控制接口
    ISimpleAudioVolume *pAudioVolume = NULL;
    hr = m_AudioSessionManager->GetSimpleAudioVolume(NULL,0,&pAudioVolume);
    if (FAILED(hr)) return false;
    if(SUCCEEDED(hr))
    {
        pAudioVolume->SetMute(mute, &GUID_NULL);
        // 更改全局静音状态
        g_bMuted = mute;
    }
    if (pAudioVolume != NULL)
    {
        pAudioVolume->Release();
        pAudioVolume = NULL;
    }
    return true;
}
