#ifndef MUTEDSESSIONEVENTS_H
#define MUTEDSESSIONEVENTS_H

#include <mmdeviceapi.h>
#include <Audiopolicy.h>

class CMutedSessionEvents : public IAudioSessionEvents
{
    public: 
        CMutedSessionEvents(IAudioSessionManager* pAudioSessionManager);
        ~CMutedSessionEvents(){}
        // IUnknown methods -- AddRef, Release, and QueryInterface
        ULONG STDMETHODCALLTYPE AddRef(){return InterlockedIncrement(&_cRef);}
        ULONG STDMETHODCALLTYPE Release();
        HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, VOID **ppvInterface);
        // Notification methods for audio session events
        HRESULT STDMETHODCALLTYPE OnDisplayNameChanged(LPCWSTR NewDisplayName, LPCGUID EventContext){return S_OK;}
        HRESULT STDMETHODCALLTYPE OnIconPathChanged(LPCWSTR NewIconPath, LPCGUID EventContext){return S_OK;}
        HRESULT STDMETHODCALLTYPE OnSimpleVolumeChanged(float NewVolume, BOOL NewMute, LPCGUID EventContext);
        HRESULT STDMETHODCALLTYPE OnChannelVolumeChanged(DWORD ChannelCount, float NewChannelVolumeArray[], DWORD ChangedChannel, LPCGUID EventContext) {return S_OK;}
        HRESULT STDMETHODCALLTYPE OnGroupingParamChanged(LPCGUID NewGroupingParam, LPCGUID EventContext){return S_OK;}
        HRESULT STDMETHODCALLTYPE OnStateChanged(AudioSessionState NewState){return S_OK;}
        HRESULT STDMETHODCALLTYPE OnSessionDisconnected(AudioSessionDisconnectReason DisconnectReason){return S_OK;}
        bool TxSetMuted(bool bMuted);
    private:
        LONG _cRef;
        IAudioSessionManager* m_AudioSessionManager;
};

extern volatile bool g_bMuted;

#endif