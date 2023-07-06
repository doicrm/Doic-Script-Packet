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

    //int Wld_InsertVob() {
    //    return 0;
    //}

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

    int Vob_SetVisual()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING vobName;
        zSTRING visualName;
        par->GetParameter(vobName);
        par->GetParameter(visualName);
        zCVob* pVob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        //if (!pVob)
        //    zerr.Warning("U:MOB:CreateItems : No Mob found with specified Vobname: " + vobName);
        //else
        //    pVob->SetVisual(visualName);
        if (pVob)
            pVob->SetVisual(visualName);
        return 0;
    }
}