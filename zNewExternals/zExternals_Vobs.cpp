// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    int Wld_InsertVob() // On WPs or FPs
    {
        zCParser* par = zCParser::GetParser();
        zSTRING point, vobName, visualName;
        BOOL isCollDet, isSetOnFloor;
        par->GetParameter(isSetOnFloor);
        par->GetParameter(isCollDet);
        par->GetParameter(visualName);
        par->GetParameter(point);
        par->GetParameter(vobName);
        oCVob* vob = new oCVob();
        zVEC3 pos;
        zCWaypoint* wp = ogame->GetWorld()->wayNet->GetWaypoint(point);
        if (wp)
            pos = wp->GetPositionWorld();
        else
        {
            zCVob* pointVob = ogame->GetGameWorld()->SearchVobByName(point);
            if (pointVob)
                pos = pointVob->GetPositionWorld();
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

    int Vob_MoveToWP() // To WPs or FPs
    {
        zCParser* par = zCParser::GetParser();
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
        zCParser* par = zCParser::GetParser();
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
        zCParser* par = zCParser::GetParser();
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
        oCVob* vob = new oCVob();
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

    int Wld_RemoveVob()
    {
        zCParser* par = zCParser::GetParser();
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

    int Vob_SearchByName()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING vobName;
        par->GetParameter(vobName);
        zCVob* vob = ogame->GetGameWorld()->SearchVobByName(vobName);
        if (vob)
            par->SetReturn(&vob); return 0;
        par->SetReturn(-1);
        return 0;
    }
}