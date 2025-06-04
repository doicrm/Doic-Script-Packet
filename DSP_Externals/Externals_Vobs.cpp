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

    void RotateVob(zCVob* vob, int posX, int posY, int posZ)
    {
        const bool collDetectionStatic = vob->collDetectionStatic;
        const bool collDetectionDynamic = vob->collDetectionDynamic;
        vob->SetCollDet(false);
        vob->RotateWorldX((float)posX);
        vob->RotateWorldY((float)posY);
        vob->RotateWorldZ((float)posZ);
        vob->SetCollDetStat(collDetectionStatic);
        vob->SetCollDetDyn(collDetectionDynamic);
    }

    int Wld_InsertVob() // On WPs or FPs
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName, visualName, point;
        BOOL isCollDet;
        par->GetParameter(isCollDet);
        par->GetParameter(point);
        par->GetParameter(visualName);
        par->GetParameter(vobName);
        zCVob* vob = new zCVob{};
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
        SetPositionWorld(vob, pos);
        vob->Release();
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
        SetPositionWorld(vob, pos);
        vob->Release();
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
        zCVob* vob = new zCVob{};
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
            vob->Release();
            par->SetReturn(0);
            return 0;
        }
        ogame->GetWorld()->RemoveVob(vob);
        vob->Release();
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
            vob->Release();
            return 0;
        }
        RotateVob(vob, (float)posx, (float)posy, (float)posz);
        vob->Release();
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
            vob->SetVisual(zCVisual::LoadVisual(visualName.Upper()));
        vob->Release();
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
            vob->SetVisual("");
        vob->Release();
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
        vob->Release();
        return 0;
    }

    int Vob_SearchByName()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        par->GetParameter(vobName);
        zCVob* vob = dynamic_cast<zCVob*>(ogame->GetWorld()->SearchVobByName(vobName));
        if (vob) {
            par->SetReturn(&vob);
            vob->Release();
            return 0;
        }
        par->SetReturn(-1);
        vob->Release();
        return 0;
    }
    
    int Wld_InsertMobContainer()
    {
        auto const par = zCParser::GetParser();
        zSTRING point, vobName, visualName;
        par->GetParameter(visualName);
        par->GetParameter(point);
        par->GetParameter(vobName);
        oCMobContainer* mob = new oCMobContainer{};
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
        mob->SetVisual(zCVisual::LoadVisual(visualName));
        mob->SetCollDetDyn(true);
        ogame->GetGameWorld()->AddVob(mob);
        SetPositionWorld(mob, pos);
        mob->Release();
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
        oCVob* vob = new oCMOB{};
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
        oCVob* vob = new oCMOB{};
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
        oCVob* vob = new oCMobInter{};
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

    //int Wld_InsertMobInter()
    //{
    //    auto const par = zCParser::GetParser();
    //    zSTRING point, vobName, visualName;
    //    par->GetParameter(visualName);
    //    par->GetParameter(point);
    //    par->GetParameter(vobName);
    //    oCMobInter* mob = new oCMobInter{};
    //    zVEC3 pos;
    //    zCWaypoint* wp = ogame->GetGameWorld()->wayNet->GetWaypoint(point.Upper());
    //    if (wp)
    //        pos = wp->GetPositionWorld();
    //    else
    //    {
    //        zCVob* pointVob = ogame->GetGameWorld()->SearchVobByName(point.Upper());
    //        if (pointVob)
    //            pos = pointVob->GetPositionWorld();
    //    }
    //    mob->SetVisual(zCVisual::LoadVisual(visualName));
    //    mob->SetCollDetDyn(true);
    //    ogame->GetGameWorld()->AddVob(mob);
    //    SetPositionWorld(mob, pos);
    //    mob->Release();
    //    return 0;
    //}

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
        oCVob* vob = new oCMobInter{};
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
            mobInter->Release();
            return 0;
        }
        mobInter->triggerTarget = newTriggerTarget.Upper();
        mobInter->useWithItem = newUseWithItem.Upper();
        mobInter->conditionFunc = newConditionFunc.Upper();
        mobInter->onStateFuncName = newOnStateFuncName.Upper();
        mobInter->Release();
        return 0;
    }

    void DefineVobExternals()
    {
        // func void Wld_InsertVob(var string vobName, var string visualName, var string point, var int isCollDet)
        parser->DefineExternal("Wld_InsertVob", Wld_InsertVob, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_INT, 0);
        // func void Wld_InsertVobPos(var string vobName, var string visualName, var int posx, var int posy, var int posz, var int isCollDet)
        parser->DefineExternal("Wld_InsertVobPos", Wld_InsertVobPos, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, 0);
        // func int Wld_RemoveVob(var string vobName)
        parser->DefineExternal("Wld_RemoveVob", Wld_RemoveVob, zPAR_TYPE_INT, zPAR_TYPE_STRING, 0);
        // func void Vob_Rotate(var string vobName, var int posx, var int posy, var int posz)
        parser->DefineExternal("Vob_Rotate", Vob_Rotate, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, 0);
        // func void Vob_SetVisual(var string vobName, var string visualName)
        parser->DefineExternal("Vob_SetVisual", Vob_SetVisual, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_STRING, 0);
        // func void Vob_ClearVisual(var string vobName)
        parser->DefineExternal("Vob_ClearVisual", Vob_ClearVisual, zPAR_TYPE_VOID, zPAR_TYPE_STRING, 0);
        // func void Vob_SetName(var string oldVobName, var string newVobName)
        parser->DefineExternal("Vob_SetName", Vob_SetName, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_STRING, 0);
        // func void Vob_MoveTo(var string vobName, var string point)
        parser->DefineExternal("Vob_MoveTo", Vob_MoveTo, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_STRING, 0);
        // func void Vob_MoveToPos(var string vobName, var int posx, var int posy, var int posz)
        parser->DefineExternal("Vob_MoveToPos", Vob_MoveToPos, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, 0);
        // func int Vob_SearchByName(var string vobName)
        parser->DefineExternal("Vob_SearchByName", Vob_SearchByName, zPAR_TYPE_INT, zPAR_TYPE_STRING, 0);
        // func void Wld_InsertMobInter(var string vobName, var string visualName, var string point)
        parser->DefineExternal("Wld_InsertMobInter", Wld_InsertMobInter, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_STRING, 0);
        // func void Wld_InsertMobContainer(var string vobName, var string visualName, var string point)
        parser->DefineExternal("Wld_InsertMobContainer", Wld_InsertMobContainer, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_STRING, 0);
    }
}