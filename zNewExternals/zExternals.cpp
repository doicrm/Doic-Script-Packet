// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    // by Gratt from zParserExtender
    int Log_GetTopicStatus()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING value;
        par->GetParameter(value);
        oCLogManager& logs = oCLogManager::GetLogManager();

        auto* list = &logs.m_lstTopics;
        while (list)
        {
            auto topic = list->GetData();
            if (topic && topic->m_strDescription == value)
            {
                par->SetReturn(topic->m_enuStatus);
                return 0;
            }
            list = list->GetNextInList();
        }

        par->SetReturn(-1);
        return 0;
    }

    // by Gratt from zParserExtender
    int Wld_PlayEffectOnVob()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING effect;
        zCVob* pvob;
        int level;
        int damage;
        int damage_type;
        int damage_speed;

        par->GetParameter(damage_speed);
        par->GetParameter(damage_type);
        par->GetParameter(damage);
        par->GetParameter(level);
        pvob = (zCVob*)par->GetInstance();
        par->GetParameter(effect);

        oCVisualFX::CreateAndPlay(effect, pvob, Null, level, (float)damage, damage_type, damage_speed);
        return 0;
    }

    // by Gratt from zParserExtender
    int Wld_PlayEffectAt()
    {
        zCParser* par = zCParser::GetParser();
        zSTRING effect;
        zVEC3 ppos;
        int level;
        int damage;
        int damage_type;
        int damage_speed;

        par->GetParameter(damage_speed);
        par->GetParameter(damage_type);
        par->GetParameter(damage);
        par->GetParameter(level);
        ppos = *(zVEC3*)par->GetInstance();
        par->GetParameter(effect);

        oCVisualFX::CreateAndPlay(effect, ppos, Null, level, (float)damage, damage_type, damage_speed);
        return 0;
    }

    int Wld_GetPlayerPortalName()
    {
        zCParser* par = zCParser::GetParser();
        BOOL result = false;
        zSTRING portalName, currentPortalName;
        par->GetParameter(portalName);
        oCPortalRoomManager* portal = ogame->GetPortalRoomManager();
        if (portal->curPlayerPortal)
        {
            currentPortalName = portal->curPlayerPortal;
            result = currentPortalName.Upper() == portalName.Upper();
        }
        par->SetReturn(result);
        return 0;
    }

    // by Boguś
    template<typename T>
    int Ext_ReadStatArray()
    {
        auto par = zCParser::GetParser();

        int idx; par->GetParameter(idx);

        static T ele; ele = T{};

        if (idx < 0)
        {
            par->SetReturn(ele);
            return 0;
        }

        const auto array = reinterpret_cast<T*>(par->PopVarAddress());

        if (array)
        {
            ele = array[idx];
        }

        par->SetReturn(ele);

        return 0;
    }

    // by Boguś
    template<typename T>
    int Ext_WriteStatArray()
    {
        auto par = zCParser::GetParser();

        T value; par->GetParameter(value);
        int idx; par->GetParameter(idx);
        if (idx < 0) return 0;

        auto array = reinterpret_cast<T*>(par->PopVarAddress());

        if (array)
        {
            array[idx] = value;
        }

        return 0;
    }
}