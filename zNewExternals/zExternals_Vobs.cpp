// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
#pragma warning(push)
#pragma warning(disable: 4244)

#pragma push_macro("A")
#pragma push_macro("Z")
#undef A
#undef Z

    struct C_POSITION {
        int X;
        int Y;
        int Z;
    };

    // by Gratt from zParserExtender
    int Vob_GetPos() {
        static C_POSITION vobPosition;
        zCParser* par = zCParser::GetParser();
        zCVob* vob = (zCVob*)par->GetInstance();
        zVEC3 pos = vob->GetPositionWorld();

        vobPosition.X = (int)pos[VX];
        vobPosition.Y = (int)pos[VY];
        vobPosition.Z = (int)pos[VZ];
        par->SetReturn(&vobPosition);
        return 0;
    }

    // by Gratt from zParserExtender
    int Vob_SetPos() {
        zCParser* par = zCParser::GetParser();
        C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
        zCVob* vob = (zCVob*)par->GetInstance();
        cmd << string::Combine("%x %x", vobPosition, vob) << endl;

        vob->SetPositionWorld(zVEC3(
            (float)vobPosition->X,
            (float)vobPosition->Y,
            (float)vobPosition->Z));

        return 0;
    }

    //int Wld_InsertVob() {
    //    zCParser* par = zCParser::GetParser();
    //    zSTRING vobName;
    //    zSTRING visualName;
    //    par->GetParameter(visualName);
    //    par->GetParameter(vobName);
    //    int instance = par->CreateInstance();
    //    C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
    //    oCVob* vob = ogame->GetGameWorld()->CreateVob(zVOB_TYPE_NORMAL, instance);
    //    if (!vob)
    //        return 0;
    //    vob->SetPositionWorld(zVEC3(
    //        (float)vobPosition->X,
    //        (float)vobPosition->Y,
    //        (float)vobPosition->Z));
    //    ogame->GetGameWorld()->AddVob(vob);
    //    vob->SetVisual(visualName);
    //    vob->Release();
    //    return 0;
    //}

    int Vob_SetVisual()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING vobName;
        zSTRING visualName;
        par->GetParameter(visualName);
        par->GetParameter(vobName);
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (!vob)
            cmd << "No Vob found with specified name: " << vobName << endl;
        else
            vob->SetVisual(visualName);
        return 0;
    }

    int Vob_ClearVisual()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING vobName;
        zSTRING visualName;
        const char* value = 0;
        par->GetParameter(visualName);
        par->GetParameter(vobName);
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (!vob)
            cmd << "No Vob found with specified name: " << vobName << endl;
        else
            vob->SetVisual(value);
        return 0;
    }
}