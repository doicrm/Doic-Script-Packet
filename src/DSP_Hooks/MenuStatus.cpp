// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    HOOK Ivk_oCMenu_Status_InitForDisplay PATCH(&oCMenu_Status::InitForDisplay, &oCMenu_Status::InitForDisplay_Union);
    void oCMenu_Status::InitForDisplay_Union() {
        int index = parser->GetIndex("MENU_STATUS_API");
        THISCALL(Ivk_oCMenu_Status_InitForDisplay)();
        if (index > 0) parser->CallFunc(index);
    }
}