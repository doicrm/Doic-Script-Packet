// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

#pragma push_macro("Z")
#undef Z

    struct C_POSITION {
        int X;
        int Y;
        int Z;
    };

    static void SetPositionWorld(zCVob* vob, const zVEC3& position)
    {
        const bool collDetectionStatic = vob->collDetectionStatic;
        const bool collDetectionDynamic = vob->collDetectionDynamic;
        vob->collDetectionStatic = 0;
        vob->collDetectionDynamic = 0;
        vob->SetPositionWorld(position);
        vob->collDetectionStatic = collDetectionStatic;
        vob->collDetectionDynamic = collDetectionDynamic;
    }

    int Wld_InsertVob()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName, point;
        par->GetParameter(point);
        par->GetParameter(vobName);
        point = point.Upper();
        zCVob* vob = new zCVob{};
        oCWorld* world = ogame->GetGameWorld();
        zCWaypoint* wp = world->wayNet->GetWaypoint(point);
        zVEC3 pos;
        if (wp) {
            pos = wp->GetPositionWorld();
        }
        else
        {
            zCVob* pointVob = world->SearchVobByName(point);
            if (pointVob) {
                pos = pointVob->GetPositionWorld();
            }
        }
        vob->SetVobName(vobName.Upper());
        world->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Wld_InsertVobPos()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
        par->GetParameter(vobName);
        zCVob* vob = new zCVob{};
        zVEC3 pos = zVEC3(
            (float)vobPosition->X,
            (float)vobPosition->Y,
            (float)vobPosition->Z
        );
        vob->SetVobName(vobName.Upper());
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
        oCWorld* world = ogame->GetGameWorld();
        vobName = vobName.Upper();
        zCVob* vob = world->SearchVobByName(vobName);
        if (!vob)
        {
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
            par->SetReturn(0);
            return 0;
        }
        world->RemoveVob(vob);
        vob->Release();
        par->SetReturn(1);
        return 0;
    }

    int Vob_MoveTo()
    {
        auto const par = zCParser::GetParser();
        zSTRING point, vobName;
        par->GetParameter(point);
        par->GetParameter(vobName);
        oCWorld* world = ogame->GetGameWorld();
        vobName = vobName.Upper();
        point = point.Upper();
        zCVob* vob = world->SearchVobByName(vobName);
        if (!vob)
        {
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
            return 0;
        }
        zCWaypoint* wp = world->wayNet->GetWaypoint(point);
        zVEC3 pos;
        if (wp) {
            pos = wp->GetPositionWorld();
        }
        else
        {
            zCVob* pointVob = world->SearchVobByName(point);
            if (pointVob) {
                pos = pointVob->GetPositionWorld();
            }
        }
        SetPositionWorld(vob, pos);
        return 0;
    }

    int Wld_GetPos()
    {
        static C_POSITION vobPosition;
        auto const par = zCParser::GetParser();
        int posx, posy, posz;
        par->GetParameter(posz);
        par->GetParameter(posy);
        par->GetParameter(posx);
        vobPosition.X = posx;
        vobPosition.Y = posy;
        vobPosition.Z = posz;
        par->SetReturn(&vobPosition);
        return 0;
    }

    int Vob_Rotate()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
        par->GetParameter(vobName);
        vobName = vobName.Upper();
        zCVob* vob = ogame->GetGameWorld()->SearchVobByName(vobName);
        if (!vob)
        {
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
            return 0;
        }
        const bool collDetectionStatic = vob->collDetectionStatic;
        const bool collDetectionDynamic = vob->collDetectionDynamic;
        vob->SetCollDet(0);
        vob->RotateWorldX((float)vobPosition->X);
        vob->RotateWorldY((float)vobPosition->Y);
        vob->RotateWorldZ((float)vobPosition->Z);
        vob->collDetectionStatic = collDetectionStatic;
        vob->collDetectionDynamic = collDetectionDynamic;
        return 0;
    }

    int Vob_SetVisual()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName, visualName;
        par->GetParameter(visualName);
        par->GetParameter(vobName);
        vobName = vobName.Upper();
        zCVob* vob = ogame->GetGameWorld()->SearchVobByName(vobName);
        if (!vob)
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
        else
            vob->SetVisual(zCVisual::LoadVisual(visualName.Upper()));
        return 0;
    }

    int Vob_SetOnFloor()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        par->GetParameter(vobName);
        oCWorld* world = ogame->GetGameWorld();
        vobName = vobName.Upper();
        zCVob* vob = world->SearchVobByName(vobName);
        if (!vob)
        {
            cmd << "No Vob found with specified Vobname: " << vobName << endl;
            return 0;
        }
        oCVob* obj = dynamic_cast<oCVob*>(vob);
        if (obj)
        {
            zVEC3 pos = vob->GetPositionWorld();
            obj->SetOnFloor(pos);
        }
        else {
            cmd << "Vob found, but it is not an oCVob: " << vobName << endl;
        }
        return 0;
    }

    int Wld_InsertMob()
    {
        auto const par = zCParser::GetParser();
        zSTRING point, vobName;
        par->GetParameter(point);
        par->GetParameter(vobName);
        vobName = vobName.Upper();
        point = point.Upper();
        oCMOB* vob = new oCMOB{};
        oCWorld* world = ogame->GetGameWorld();
        zCWaypoint* wp = world->wayNet->GetWaypoint(point);
        zVEC3 pos;
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pVob = world->SearchVobByName(point);
            if (pVob)
                pos = pVob->GetPositionWorld();
        }
        vob->SetVobName(vobName.Upper());
        world->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Wld_InsertMobPos()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
        par->GetParameter(vobName);
        oCMOB* vob = new oCMOB{};
        zVEC3 pos = zVEC3(
            (float)vobPosition->X,
            (float)vobPosition->Y,
            (float)vobPosition->Z
        );
        vob->SetVobName(vobName.Upper());
        ogame->GetGameWorld()->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Wld_InsertMobInter()
    {
        auto const par = zCParser::GetParser();
        zSTRING point, vobName;
        par->GetParameter(point);
        par->GetParameter(vobName);
        point = point.Upper();
        oCMobInter* vob = new oCMobInter{};
        oCWorld* world = ogame->GetGameWorld();
        zCWaypoint* wp = world->wayNet->GetWaypoint(point);
        zVEC3 pos;
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pVob = world->SearchVobByName(point);
            if (pVob)
                pos = pVob->GetPositionWorld();
        }
        vob->SetVobName(vobName.Upper());
        world->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Wld_InsertMobInterPos()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
        par->GetParameter(vobName);
        oCMobInter* vob = new oCMobInter{};
        zVEC3 pos = zVEC3(
            (float)vobPosition->X,
            (float)vobPosition->Y,
            (float)vobPosition->Z
        );
        vob->SetVobName(vobName.Upper());
        ogame->GetGameWorld()->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Wld_InsertMobContainer()
    {
        zSTRING point, vobName;
        auto const par = zCParser::GetParser();
        par->GetParameter(point);
        par->GetParameter(vobName);
        point = point.Upper();
        oCMobContainer* mob = new oCMobContainer{};
        oCWorld* world = ogame->GetGameWorld();
        zCWaypoint* wp = world->wayNet->GetWaypoint(point);
        zVEC3 pos;
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pointVob = world->SearchVobByName(point);
            if (pointVob)
                pos = pointVob->GetPositionWorld();
        }
        mob->SetVobName(vobName.Upper());
        world->AddVob(mob);
        SetPositionWorld(mob, pos);
        mob->Release();
        return 0;
    }

    int Wld_InsertMobContainerPos()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
        par->GetParameter(vobName);
        oCMobContainer* vob = new oCMobContainer{};
        zVEC3 pos = zVEC3(
            (float)vobPosition->X,
            (float)vobPosition->Y,
            (float)vobPosition->Z
        );
        vob->SetVobName(vobName.Upper());
        ogame->GetGameWorld()->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Wld_InsertMobFire()
    {
        zSTRING point, vobName;
        auto const par = zCParser::GetParser();
        par->GetParameter(point);
        par->GetParameter(vobName);
        point = point.Upper();
        oCMobFire* mob = new oCMobFire{};
        oCWorld* world = ogame->GetGameWorld();
        zCWaypoint* wp = world->wayNet->GetWaypoint(point);
        zVEC3 pos;
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pointVob = world->SearchVobByName(point);
            if (pointVob)
                pos = pointVob->GetPositionWorld();
        }
        mob->SetVobName(vobName.Upper());
        world->AddVob(mob);
        SetPositionWorld(mob, pos);
        mob->Release();
        return 0;
    }

    int Wld_InsertMobFirePos()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
        par->GetParameter(vobName);
        oCMobFire* vob = new oCMobFire{};
        zVEC3 pos = zVEC3(
            (float)vobPosition->X,
            (float)vobPosition->Y,
            (float)vobPosition->Z
        );
        vob->SetVobName(vobName.Upper());
        ogame->GetGameWorld()->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Wld_InsertMobDoor()
    {
        zSTRING point, vobName;
        auto const par = zCParser::GetParser();
        par->GetParameter(point);
        par->GetParameter(vobName);
        point = point.Upper();
        oCMobDoor* mob = new oCMobDoor{};
        oCWorld* world = ogame->GetGameWorld();
        zCWaypoint* wp = world->wayNet->GetWaypoint(point);
        zVEC3 pos;
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pointVob = world->SearchVobByName(point);
            if (pointVob)
                pos = pointVob->GetPositionWorld();
        }
        mob->SetVobName(vobName.Upper());
        world->AddVob(mob);
        SetPositionWorld(mob, pos);
        mob->Release();
        return 0;
    }

    int Wld_InsertMobDoorPos()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
        par->GetParameter(vobName);
        oCMobDoor* vob = new oCMobDoor{};
        zVEC3 pos = zVEC3(
            (float)vobPosition->X,
            (float)vobPosition->Y,
            (float)vobPosition->Z
        );
        vob->SetVobName(vobName.Upper());
        ogame->GetGameWorld()->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Wld_InsertMobBed()
    {
        zSTRING point, vobName;
        auto const par = zCParser::GetParser();
        par->GetParameter(point);
        par->GetParameter(vobName);
        point = point.Upper();
        oCMobBed* mob = new oCMobBed{};
        oCWorld* world = ogame->GetGameWorld();
        zCWaypoint* wp = world->wayNet->GetWaypoint(point);
        zVEC3 pos;
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pointVob = world->SearchVobByName(point);
            if (pointVob)
                pos = pointVob->GetPositionWorld();
        }
        mob->SetVobName(vobName.Upper());
        world->AddVob(mob);
        SetPositionWorld(mob, pos);
        mob->Release();
        return 0;
    }

    int Wld_InsertMobBedPos()
    {
        auto const par = zCParser::GetParser();
        zSTRING vobName;
        C_POSITION* vobPosition = (C_POSITION*)par->GetInstance();
        par->GetParameter(vobName);
        oCMobBed* vob = new oCMobBed{};
        zVEC3 pos = zVEC3(
            (float)vobPosition->X,
            (float)vobPosition->Y,
            (float)vobPosition->Z
        );
        vob->SetVobName(vobName.Upper());
        ogame->GetGameWorld()->AddVob(vob);
        SetPositionWorld(vob, pos);
        vob->Release();
        return 0;
    }

    int Hlp_IsValidVob()
    {
        auto const par = zCParser::GetParser();
        zCVob* vob = ((zCVob*)par->GetInstance());
        par->SetReturn(vob != NULL);
        return 0;
    }

    int Cast_InstanceIsVob()
    {
        auto const par = zCParser::GetParser();
        zCObject* instance = (zCObject*)par->GetInstance();
        par->SetReturn((int)instance->CastTo<zCVob>());
        return 0;
    }

#pragma pop_macro("Z")
}