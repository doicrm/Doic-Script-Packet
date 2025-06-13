// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    int Wld_GetPlayerPortalRoom()
    {
        static zSTRING result = "";
        zCParser* par = zCParser::GetParser();
        oCPortalRoomManager* portalMng = ogame->GetPortalRoomManager();
        result = (zSTRING&)portalMng->curPlayerPortal || "";
        par->SetReturn(result);
        return 0;
    }
}