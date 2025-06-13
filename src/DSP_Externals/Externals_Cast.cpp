// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    int Cast_InstanceIsVob()
    {
        auto const par = zCParser::GetParser();
        zCObject* instance = (zCObject*)par->GetInstance();
        par->SetReturn((int)instance->CastTo<zCVob>());
        return 0;
    }
}