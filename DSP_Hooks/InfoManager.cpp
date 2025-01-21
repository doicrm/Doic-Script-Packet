// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

	// Hooks directly from zParserExtender by Gratt (now works!)

    HOOK Hook_oCInfoManager_Unarchive PATCH(&oCInfoManager::Unarchive, &oCInfoManager::Unarchive_Union);

    void oCInfoManager::Unarchive_Union(zCArchiver& arc) {
        Map<string, oCInfo**> infoInstances;
        auto list = infoList.next;
        while (list) {
            infoInstances.Insert(list->data->name, &list->data);
            list = list->next;
        }

        int NumOfEntries;
        arc.ReadInt("NumOfEntries", NumOfEntries);

        for (int i = 0; i < NumOfEntries; i++) {
            oCInfo* entry = new oCInfo();
            entry->Unarchive(arc);

            auto& pair = infoInstances[entry->name];

            if (pair.IsNull()) {
                infoList.InsertSort(entry);
                continue;
            }

            oCInfo*& info = *pair;
            delete info;
            info = entry;
        }
    }

    HOOK Hook_oCInfo_Info PATCH(&oCInfo::Info, &oCInfo::Info_Union);

    void oCInfo::Info_Union() {
        zCPar_Symbol* symbol1 = parser->GetSymbol("DIA_CURRENTNAME");
        if (symbol1 && symbol1->type == zPAR_TYPE_STRING) {
            static zSTRING currentName;
            currentName = name;
            symbol1->SetValue(name, 0);
        }

        zCPar_Symbol* symbol2 = parser->GetSymbol("DIA_CURRENTCOUNTER");
        if (symbol2 && symbol2->type == zPAR_TYPE_INT)
            symbol2->SetValue(0, 0);

        zCPar_Symbol* symbol3 = parser->GetSymbol("DIA_CURRENTINSTANCE");
        if (symbol3 && (symbol3->type == zPAR_TYPE_INT || symbol3->type == zPAR_TYPE_INSTANCE))
            symbol3->SetValue(instance, 0);

        THISCALL(Hook_oCInfo_Info)();
    }
}