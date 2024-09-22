// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    HOOK Ivk_oCMenu_Status_InitForDisplay PATCH(&oCMenu_Status::InitForDisplay, &oCMenu_Status::InitForDisplay_Union);
    void oCMenu_Status::InitForDisplay_Union() {
        THISCALL(Ivk_oCMenu_Status_InitForDisplay)();
        int index = parser->GetIndex("Menu_Status_API");
        if (index > 0) parser->CallFunc(index);
    }
}