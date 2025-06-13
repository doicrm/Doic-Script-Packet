// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    int Hlp_GetItem()
    {
        auto const par = zCParser::GetParser();
        oCItem* item = NULL;
        int instance;
        par->GetParameter(instance);
        zCPar_Symbol* sym = par->GetSymbol(instance);

        if (sym)
        {
            if (sym->type == zPAR_TYPE_INSTANCE) {
                item = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());
            }
            if (!item) {
                item = zDYNAMIC_CAST<oCItem>(ogame->GetGameWorld()->SearchVobByName(sym->name));
            }
        }

        par->SetReturn(item);
        return 0;
    }

    int Hlp_IsValidVob()
    {
        auto const par = zCParser::GetParser();
        zCVob* vob = ((zCVob*)par->GetInstance());
        par->SetReturn(vob != NULL);
        return 0;
    }
    
    int Hlp_StrCmp()
    {
        zSTRING s1, s2;
        auto const par = zCParser::GetParser();
        par->GetParameter(s2);
        par->GetParameter(s1);
        s1.Upper();
        s2.Upper();
        BOOL result = s1 == s2;
        par->SetReturn(result);
        return 0;
    }
}