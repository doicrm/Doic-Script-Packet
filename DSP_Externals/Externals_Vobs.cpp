// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

    void SetPositionWorld(zCVob* vob, const zVEC3& position)
    {
        const bool collDetectionStatic = vob->collDetectionStatic;
        const bool collDetectionDynamic = vob->collDetectionDynamic;
        vob->SetCollDet(false);
        vob->SetPositionWorld(position);
        vob->SetCollDetStat(collDetectionStatic);
        vob->SetCollDetDyn(collDetectionDynamic);
    }

    int Wld_InsertVob() // On WPs or FPs
    {
        auto const par = zCParser::GetParser();
        zSTRING point, vobName, visualName;
        BOOL isCollDet;
        par->GetParameter(isCollDet);
        par->GetParameter(visualName);
        par->GetParameter(point);
        par->GetParameter(vobName);
        zCVob* vob = new zCVob();
        zVEC3 pos;
        zCWaypoint* wp = ogame->GetGameWorld()->wayNet->GetWaypoint(point.Upper());
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pointVob = ogame->GetGameWorld()->SearchVobByName(point.Upper());
            if (pointVob)
                pos = pointVob->GetPositionWorld();
        }
        vob->SetVobName(vobName.Upper());
        vob->SetVisual(zCVisual::LoadVisual(visualName.Upper()));
        vob->SetCollDetDyn(isCollDet);
        ogame->GetGameWorld()->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Vob_MoveTo() // To WPs or FPs
    {
        auto const par = zCParser::GetParser();
        zSTRING point, vobName;
        par->GetParameter(point);
        par->GetParameter(vobName);
        zVEC3 pos;
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (!vob)
        {
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
            return 0;
        }
        zCWaypoint* wp = ogame->GetWorld()->wayNet->GetWaypoint(point);
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pointVob = ogame->GetGameWorld()->SearchVobByName(point);
            if (pointVob)
                pos = pointVob->GetPositionWorld();
        }
        vob->SetCollDet(0);
        vob->SetPhysicsEnabled(0);
        vob->SetPositionWorld(pos);
        vob->SetCollDet(1);
        vob->SetPhysicsEnabled(1);
        return 0;
    }

    int Vob_MoveToPos()
    {
        auto const par = zCParser::GetParser();
        int posx, posy, posz;
        zSTRING point, vobName;
        par->GetParameter(posz);
        par->GetParameter(posy);
        par->GetParameter(posx);
        par->GetParameter(vobName);
        zVEC3 pos = zVEC3((float)posx, (float)posy, (float)posz);
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (!vob)
        {
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
            return 0;
        }
        vob->SetCollDet(0);
        vob->SetPhysicsEnabled(0);
        vob->SetPositionWorld(pos);
        vob->SetCollDet(1);
        vob->SetPhysicsEnabled(1);
        return 0;
    }

    int Wld_InsertVobPos()
    {
        auto const par = zCParser::GetParser();
        int posx, posy, posz;
        zSTRING point, vobName, visualName;
        BOOL isCollDet;
        par->GetParameter(isCollDet);
        par->GetParameter(visualName);
        par->GetParameter(posz);
        par->GetParameter(posy);
        par->GetParameter(posx);
        par->GetParameter(vobName);
        zCVob* vob = new zCVob();
        zVEC3 pos = zVEC3((float)posx, (float)posy, (float)posz);
        vob->SetVobName(vobName.Upper());
        vob->SetVisual(zCVisual::LoadVisual(visualName.Upper()));
        vob->SetCollDetDyn(isCollDet);
        ogame->GetGameWorld()->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Wld_RemoveVob()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        par->GetParameter(vobName);
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (!vob)
        {
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
            par->SetReturn(0);
            return 0;
        }
        ogame->GetWorld()->RemoveVob(vob);
        par->SetReturn(1);
        return 0;
    }

    int Vob_Rotate()
    {
        auto const par = zCParser::GetParser();
        int posx, posy, posz;
        zSTRING vobName;
        par->GetParameter(posz);
        par->GetParameter(posy);
        par->GetParameter(posx);
        par->GetParameter(vobName);
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (!vob)
        {
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
            return 0;
        }
        vob->SetCollDet(0);
        vob->RotateWorldX((float)posx);
        vob->RotateWorldY((float)posy);
        vob->RotateWorldZ((float)posz);
        vob->SetCollDet(1);
        return 0;
    }

    int Vob_SetVisual()
    {
        auto const par = zCParser::GetParser();
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
        auto const par = zCParser::GetParser();
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
        auto const par = zCParser::GetParser();
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

    int Vob_SearchByName()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        par->GetParameter(vobName);
        zCVob* vob = ogame->GetGameWorld()->SearchVobByName(vobName);
        if (vob)
            par->SetReturn(&vob); return 0;
        par->SetReturn(-1);
        return 0;
    }

    int Wld_InsertMob() // On WPs or FPs
    {
        auto const par = zCParser::GetParser();
        zSTRING point, vobName, visualName;
        BOOL isCollDet, isSetOnFloor;
        par->GetParameter(isSetOnFloor);
        par->GetParameter(isCollDet);
        par->GetParameter(visualName);
        par->GetParameter(point);
        par->GetParameter(vobName);
        oCVob* vob = new oCMOB();
        zVEC3 pos;
        zCWaypoint* wp = ogame->GetWorld()->wayNet->GetWaypoint(point);
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pVob = ogame->GetGameWorld()->SearchVobByName(point);
            if (pVob)
                pos = pVob->GetPositionWorld();
        }
        vob->SetVobName(vobName);
        vob->SetPositionWorld(pos);
        vob->SetVisual(visualName);
        vob->SetCollDet(0);
        ogame->GetGameWorld()->AddVob(vob);
        if (isSetOnFloor)
            vob->SetOnFloor(pos);
        vob->SetCollDet(isCollDet);
        vob->SetPhysicsEnabled(1);
        vob->SetSleeping(1);
        vob->Release();
        return 0;
    }

    int Wld_InsertMobPos()
    {
        auto const par = zCParser::GetParser();
        int posx, posy, posz;
        zSTRING vobName, visualName;
        BOOL isCollDet, isSetOnFloor;
        par->GetParameter(isSetOnFloor);
        par->GetParameter(isCollDet);
        par->GetParameter(visualName);
        par->GetParameter(posz);
        par->GetParameter(posy);
        par->GetParameter(posx);
        par->GetParameter(vobName);
        zVEC3 pos = zVEC3((float)posx, (float)posy, (float)posz);
        oCVob* vob = new oCMOB();
        vob->SetVobName(vobName);
        vob->SetPositionWorld(pos);
        vob->SetVisual(visualName);
        vob->SetCollDet(0);
        ogame->GetGameWorld()->AddVob(vob);
        if (isSetOnFloor)
            vob->SetOnFloor(pos);
        vob->SetCollDet(isCollDet);
        vob->SetPhysicsEnabled(1);
        vob->SetSleeping(1);
        vob->Release();
        return 0;
    }

    int Wld_InsertMobInter() // On WPs or FPs
    {
        auto const par = zCParser::GetParser();
        zSTRING point, vobName, visualName;
        BOOL isCollDet, isSetOnFloor;
        par->GetParameter(isSetOnFloor);
        par->GetParameter(isCollDet);
        par->GetParameter(visualName);
        par->GetParameter(point);
        par->GetParameter(vobName);
        oCVob* vob = new oCMobInter();
        zVEC3 pos;
        zCWaypoint* wp = ogame->GetWorld()->wayNet->GetWaypoint(point);
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pVob = ogame->GetGameWorld()->SearchVobByName(point);
            if (pVob)
                pos = pVob->GetPositionWorld();
        }
        vob->SetVobName(vobName);
        vob->SetPositionWorld(pos);
        vob->SetVisual(visualName);
        vob->SetCollDet(0);
        ogame->GetGameWorld()->AddVob(vob);
        if (isSetOnFloor)
            vob->SetOnFloor(pos);
        vob->SetCollDet(isCollDet);
        vob->SetPhysicsEnabled(1);
        vob->SetSleeping(1);
        vob->Release();
        return 0;
    }

    int Wld_InsertMobInterPos()
    {
        auto const par = zCParser::GetParser();
        int posx, posy, posz;
        zSTRING vobName, visualName;
        BOOL isCollDet, isSetOnFloor;
        par->GetParameter(isSetOnFloor);
        par->GetParameter(isCollDet);
        par->GetParameter(visualName);
        par->GetParameter(posz);
        par->GetParameter(posy);
        par->GetParameter(posx);
        par->GetParameter(vobName);
        zVEC3 pos = zVEC3((float)posx, (float)posy, (float)posz);
        oCVob* vob = new oCMobInter();
        vob->SetVobName(vobName);
        vob->SetPositionWorld(pos);
        vob->SetVisual(visualName);
        vob->SetCollDet(0);
        ogame->GetGameWorld()->AddVob(vob);
        if (isSetOnFloor)
            vob->SetOnFloor(pos);
        vob->SetCollDet(isCollDet);
        vob->SetPhysicsEnabled(1);
        vob->SetSleeping(1);
        vob->Release();
        return 0;
    }

    int Wld_SetMobInterProps()
    {
        auto const par = zCParser::GetParser();
        zSTRING mobName, newTriggerTarget, newUseWithItem, newConditionFunc, newOnStateFuncName;
        par->GetParameter(newOnStateFuncName);
        par->GetParameter(newConditionFunc);
        par->GetParameter(newUseWithItem);
        par->GetParameter(newTriggerTarget);
        par->GetParameter(mobName);
        oCMobInter* mobInter = dynamic_cast<oCMobInter*>(ogame->GetWorld()->SearchVobByName(mobName));
        if (!mobInter)
        {
            cmd << "No MobInter found with specified name: " << mobName << endl;
            return 0;
        }
        mobInter->triggerTarget = newTriggerTarget;
        mobInter->useWithItem = newUseWithItem;
        mobInter->conditionFunc = newConditionFunc;
        mobInter->onStateFuncName = newOnStateFuncName;
        return 0;
    }
}