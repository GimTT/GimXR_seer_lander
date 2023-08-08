#include "mutedsessionevents.h"

volatile bool g_bMuted;     //全局静音变量

CMutedSessionEvents::CMutedSessionEvents(IAudioSessionManager* pAudioSessionManager)
{
    m_AudioSessionManager = pAudioSessionManager;
    _cRef = 1;
}

ULONG STDMETHODCALLTYPE CMutedSessionEvents::Release()
{
    ULONG ulRef = InterlockedDecrement(&_cRef);
    if (0 == ulRef)
    {
        delete this;
    }
    return ulRef;
}

HRESULT STDMETHODCALLTYPE CMutedSessionEvents::QueryInterface(REFIID riid, VOID **ppvInterface)
{
    if (IID_IUnknown == riid)
    {
        AddRef();
        *ppvInterface = (IUnknown*)this;
    }
    else if(__uuidof(IAudioSessionEvents) == riid) 
    {
        AddRef();
        *ppvInterface = (IAudioSessionEvents*)this;
    }
    else
    {
        *ppvInterface = NULL;
        return E_NOINTERFACE;
    }
    return S_OK;
}

HRESULT STDMETHODCALLTYPE CMutedSessionEvents::OnSimpleVolumeChanged(float NewVolume, BOOL NewMute, LPCGUID EventContext)
{
    // 防止其它程序对静音篡改
    if ((BOOL)g_bMuted != NewMute)
    {
        TxSetMuted(g_bMuted);
    }
    return S_OK;
}

bool CMutedSessionEvents::TxSetMuted(bool bMuted)
{
    HRESULT hr = S_FALSE;
    // 获得音量、静音控制接口
    ISimpleAudioVolume *pAudioVolume = NULL;
    hr = m_AudioSessionManager->GetSimpleAudioVolume(NULL, 0, &pAudioVolume);
    if (FAILED(hr))
    {
        return false;
    }

    if (SUCCEEDED(hr))
    {
        pAudioVolume->SetMute(bMuted, &GUID_NULL);
        // 更改全局静音状态
        g_bMuted = bMuted;
    }

    if (pAudioVolume != NULL)
    {
        pAudioVolume->Release();
        pAudioVolume = NULL;
    }

    return true;
}
