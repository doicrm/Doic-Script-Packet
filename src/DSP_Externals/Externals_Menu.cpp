// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    int Menu_SetItemText()
    {
        auto const par = zCParser::GetParser();
        zSTRING menuItemName, menuItemText;
        par->GetParameter(menuItemText);
        par->GetParameter(menuItemName);
        menuItemName = menuItemName.Upper();
        zCMenuItem* menuItem = zCMenuItem::GetByName(menuItemName);

        if (!menuItem)
        {
            cmd << "Menu_SetItemText: Invalid Menu Item: " << menuItemName << endl;
            return 0;
        }

        menuItem->SetText(menuItemText, 0, 0);
#if ENGINE > Engine_G1A
        menuItem->Release();
#else
        menuItem = NULL;
#endif
        return 0;
    }

    int Menu_GetItemText()
    {
        static zSTRING result = "";
        auto const par = zCParser::GetParser();
        zSTRING menuItemName;
        par->GetParameter(menuItemName);
        menuItemName = menuItemName.Upper();
        zCMenuItem* menuItem = zCMenuItem::GetByName(menuItemName);

        if (!menuItem)
        {
            cmd << "Menu_GetItemText: Invalid Menu Item: " << menuItemName << endl;
            par->SetReturn((zSTRING&)result);
            return 0;
        }

        result = (zSTRING&)menuItem->GetText(0);
#if ENGINE > Engine_G1A
        menuItem->Release();
#else
        menuItem = NULL;
#endif
        par->SetReturn(result);
        return 0;
    }
}