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
    int Vob_GetPos()
    {
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
    int Vob_SetPos()
    {
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

    int Wld_InsertVob()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING vobName, visualName;
        BOOL isCollDet, isSetOnFloor;
        par->GetParameter(isSetOnFloor);
        par->GetParameter(isCollDet);
        par->GetParameter(visualName);
        C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
        par->GetParameter(vobName);
        zVEC3 pos = zVEC3(
            (float)vobPosition->X,
            (float)vobPosition->Y,
            (float)vobPosition->Z);
        oCVob* vob = new oCVob();
        if (!vob)
            return 0;
        vob->SetPositionWorld(pos);
        vob->SetVisual(visualName);
        vob->SetCollDet(FALSE);
        ogame->GetGameWorld()->AddVob(vob);
        if (isSetOnFloor)
            vob->SetOnFloor(pos);
        vob->SetCollDet(isCollDet);
        vob->SetPhysicsEnabled(TRUE);
        vob->SetSleeping(TRUE);
        vob->Release();
        return 0;
    }

    int Wld_RemoveVob()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING vobName;
        par->GetParameter(vobName);
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (!vob)
        {
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
            par->SetReturn(FALSE);
            return 0;
        }
        ogame->GetGameWorld()->RemoveVob(vob);
        par->SetReturn(TRUE);
        return 0;
    }

    int Vob_SetVisual()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING vobName, visualName;
        par->GetParameter(visualName);
        par->GetParameter(vobName);
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (!vob)
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
        else
            vob->SetVisual(visualName);
        return 0;
    }

    int Vob_ClearVisual()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING vobName;
        par->GetParameter(vobName);
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (!vob)
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
        else
            vob->SetVisual(NULL);
        return 0;
    }

    int Vob_SetName()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING vobName, newName;
        par->GetParameter(newName);
        par->GetParameter(vobName);
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (!vob)
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
        else
            vob->SetVobName(newName);
        return 0;
    }

    int Mob_SetMisc()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING mobName, triggerTarget, useWithItem, onStateFuncName;
        par->GetParameter(onStateFuncName);
        par->GetParameter(useWithItem);
        par->GetParameter(triggerTarget);
        par->GetParameter(mobName);
        oCMobContainer* mob = dynamic_cast<oCMobContainer*>(ogame->GetWorld()->SearchVobByName(mobName));
        if (!mob)
            cmd << "No Mob found with specified Vobname: " << mobName << endl;
        else
            mob->SetUseWithItem(useWithItem);
        return 0;
    }

    int Mob_SetLockable()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING mobName, keyInstance, pickLockStr;
        BOOL isLocked;
        par->GetParameter(isLocked);
        par->GetParameter(pickLockStr);
        par->GetParameter(keyInstance);
        par->GetParameter(mobName);
        oCMobContainer* mob = dynamic_cast<oCMobContainer*>(ogame->GetWorld()->SearchVobByName(mobName));
        if (!mob)
            cmd << "No Mob found with specified Vobname: " << mobName << endl;
        else
        {
            mob->SetKeyInstance(keyInstance);
            mob->SetPickLockStr(pickLockStr);
            mob->SetLocked(isLocked);
        }
        return 0;
    }

    int Mob_FillItems()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING mobName, contents;
        par->GetParameter(contents);
        par->GetParameter(mobName);
        oCMobContainer* mob = dynamic_cast<oCMobContainer*>(ogame->GetWorld()->SearchVobByName(mobName));
        if (!mob)
            cmd << "No Mob found with specified Vobname: " << mobName << endl;
        else
            mob->CreateContents(contents);
        return 0;
    }
}