#ifndef STEAMSTUFF_H
#define STEAMSTUFF_H

#include <Steamworks.h>
#include "Interfaces/Steam/ISteamRemotePlay/ISteamRemotePlay001.h"

class ClientContext
{
public:
    ClientContext();
    ~ClientContext();

    ISteamUser019* SteamUser();
    ISteamFriends015* SteamFriends();
    ISteamUtils009* SteamUtils();
    ISteamRemotePlay001* SteamRemotePlay();
    IClientFriends* ClientFriends();

    IClientRemoteClientManager* RemoteClientManager();

    bool Init();
    void Shutdown();
    void RunCallbacks();

private:
    HSteamPipe m_hPipe;
    HSteamUser m_hUser;

    ISteamClient019* m_pSteamClient;
    ISteamUser019* m_pSteamUser;
    ISteamFriends015* m_pSteamFriends;
    ISteamUtils009* m_pSteamUtils;
    ISteamRemotePlay001* m_pSteamRemotePlay;

    IClientEngine* m_pClientEngine;
    IClientRemoteClientManager* m_pClientRemoteManager;
    IClientFriends* m_pClientFriends;
    
    bool m_ShuttingDown;
    bool m_Initialized;
};

ClientContext* GClientContext();
CGameID GetRunningGameID();

#endif // !STEAMSTUFF_H
