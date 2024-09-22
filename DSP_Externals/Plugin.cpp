// This file added in headers queue
// File: "Sources.h"
#include "resource.h"

namespace GOTHIC_ENGINE {
    void Game_Entry() {
    }

    void Game_Init() {
    }

    void Game_Exit() {
    }

    void Game_PreLoop() {
    }

    void Game_Loop() {
    }

    void Game_PostLoop() {
    }

    void Game_MenuLoop() {
    }

    // Information about current saving or loading world
    TSaveLoadGameInfo& SaveLoadGameInfo = UnionCore::SaveLoadGameInfo;

    void Game_SaveBegin() {
    }

    void Game_SaveEnd() {
    }

    void LoadBegin() {
    }

    void LoadEnd() {
    }

    void Game_LoadBegin_NewGame() {
        LoadBegin();
    }

    void Game_LoadEnd_NewGame() {
        LoadEnd();
    }

    void Game_LoadBegin_SaveGame() {
        LoadBegin();
    }

    void Game_LoadEnd_SaveGame() {
        LoadEnd();
    }

    void Game_LoadBegin_ChangeLevel() {
        LoadBegin();
    }

    void Game_LoadEnd_ChangeLevel() {
        LoadEnd();
    }

    void Game_LoadBegin_Trigger() {
    }

    void Game_LoadEnd_Trigger() {
    }

    void Game_Pause() {
    }

    void Game_Unpause() {
    }

    void Game_DefineExternals() {

        //---------------------------------------------------------------------
        // MENU
        //---------------------------------------------------------------------

        // func void Menu_SetItemText(var string menuItemName, var int value)
        parser->DefineExternal("Menu_SetItemText", Menu_SetItemText, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_STRING, 0);

        //---------------------------------------------------------------------
        // LOG
        //---------------------------------------------------------------------
 
        // func int Log_GetTopicStatus(var string logName) 
        parser->DefineExternal("Log_GetTopicStatus", Log_GetTopicStatus, zPAR_TYPE_INT, zPAR_TYPE_STRING, 0);

        //---------------------------------------------------------------------
        // NPC
        //---------------------------------------------------------------------

        // func int Npc_IsInWorld(var C_NPC npc)
        parser->DefineExternal("Npc_IsInWorld", Npc_IsInWorld, zPAR_TYPE_INT, zPAR_TYPE_INSTANCE, 0);
        // func int Npc_GetRoutineName(var C_NPC npc)
        parser->DefineExternal("Npc_GetRoutineName", Npc_GetRoutineName, zPAR_TYPE_STRING, zPAR_TYPE_INSTANCE, 0);
        // func int Npc_IsInRoutineName(var C_NPC npc, var string routine)
        parser->DefineExternal("Npc_IsInRoutineName", Npc_IsInRoutineName, zPAR_TYPE_INT, zPAR_TYPE_INSTANCE, zPAR_TYPE_STRING, 0);
        // func int Npc_GetSlotItem(var C_NPC slf)
        parser->DefineExternal("Npc_GetSlotItem", Npc_GetSlotItem, zPAR_TYPE_INSTANCE, zPAR_TYPE_INSTANCE, zPAR_TYPE_STRING, 0);
        // func int Npc_EquipItem(var C_NPC slf, var C_Item itm)
        parser->DefineExternal("Npc_EquipItem", Npc_EquipItem, zPAR_TYPE_VOID, zPAR_TYPE_INSTANCE, zPAR_TYPE_INSTANCE, 0);

        //---------------------------------------------------------------------
        // WLD
        //---------------------------------------------------------------------

        parser->DefineExternal("Wld_PlayEffectOnVob", Wld_PlayEffectOnVob, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_INSTANCE, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, 0);
        parser->DefineExternal("Wld_PlayEffectAt", Wld_PlayEffectAt, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_INSTANCE, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, 0);
        // func int Wld_GetPlayerPortalName(var string portalName)
        parser->DefineExternal("Wld_GetPlayerPortalName", Wld_GetPlayerPortalName, zPAR_TYPE_INT, zPAR_TYPE_STRING, 0);

        //---------------------------------------------------------------------
        // VOB
        //---------------------------------------------------------------------

        // func void Wld_InsertVob(var string vobName, var string point, var string visualName, var int isCollDet, var int isSetOnFloor)
        parser->DefineExternal("Wld_InsertVob", Wld_InsertVob, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_INT, 0);
        // func void Wld_InsertVobPos(var string vobName, var int posx, var int posy, var int posz, var string visualName, var int isCollDet, var int isSetOnFloor)
        parser->DefineExternal("Wld_InsertVobPos", Wld_InsertVobPos, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_INT, 0);
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
        // func void Vob_SearchByName(var string vobName)
        parser->DefineExternal("Vob_SearchByName", Vob_SearchByName, zPAR_TYPE_INT, zPAR_TYPE_STRING, 0);

        //---------------------------------------------------------------------
        // AI
        //---------------------------------------------------------------------

        // func string AI_TurnToWP(var C_NPC npc, var string wp)
        parser->DefineExternal("AI_TurnToWP", AI_TurnToWP, zPAR_TYPE_VOID, zPAR_TYPE_INSTANCE, zPAR_TYPE_STRING, 0);
        // func string AI_TurnToVob(var C_NPC npc, var string vobName)
        parser->DefineExternal("AI_TurnToVob", AI_TurnToVob, zPAR_TYPE_VOID, zPAR_TYPE_INSTANCE, zPAR_TYPE_STRING, 0);

        //---------------------------------------------------------------------
        // Other
        //---------------------------------------------------------------------

        parser->DefineExternal("ReadStatIntArray", Ext_ReadStatArray<int>, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, 0);
        parser->DefineExternal("ReadStatStringArray", Ext_ReadStatArray<zSTRING>, zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_INT, 0);
        parser->DefineExternal("WriteStatIntArray", Ext_WriteStatArray<int>, zPAR_TYPE_VOID, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, 0);
        parser->DefineExternal("WriteStatStringArray", Ext_WriteStatArray<zSTRING>, zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_STRING, 0);
    }

    void Game_ApplyOptions() {
    }

    /*
    Functions call order on Game initialization:
      - Game_Entry           * Gothic entry point
      - Game_DefineExternals * Define external script functions
      - Game_Init            * After DAT files init

    Functions call order on Change level:
      - Game_LoadBegin_Trigger     * Entry in trigger
      - Game_LoadEnd_Trigger       *
      - Game_Loop                  * Frame call window
      - Game_LoadBegin_ChangeLevel * Load begin
      - Game_SaveBegin             * Save previous level information
      - Game_SaveEnd               *
      - Game_LoadEnd_ChangeLevel   *

    Functions call order on Save game:
      - Game_Pause     * Open menu
      - Game_Unpause   * Click on save
      - Game_Loop      * Frame call window
      - Game_SaveBegin * Save begin
      - Game_SaveEnd   *

    Functions call order on Load game:
      - Game_Pause              * Open menu
      - Game_Unpause            * Click on load
      - Game_LoadBegin_SaveGame * Load begin
      - Game_LoadEnd_SaveGame   *
    */

#define AppDefault True
    CApplication* lpApplication = !CHECK_THIS_ENGINE ? Null : CApplication::CreateRefApplication(
        Enabled(AppDefault) Game_Entry,
        Enabled(AppDefault) Game_Init,
        Enabled(AppDefault) Game_Exit,
        Enabled(AppDefault) Game_PreLoop,
        Enabled(AppDefault) Game_Loop,
        Enabled(AppDefault) Game_PostLoop,
        Enabled(AppDefault) Game_MenuLoop,
        Enabled(AppDefault) Game_SaveBegin,
        Enabled(AppDefault) Game_SaveEnd,
        Enabled(AppDefault) Game_LoadBegin_NewGame,
        Enabled(AppDefault) Game_LoadEnd_NewGame,
        Enabled(AppDefault) Game_LoadBegin_SaveGame,
        Enabled(AppDefault) Game_LoadEnd_SaveGame,
        Enabled(AppDefault) Game_LoadBegin_ChangeLevel,
        Enabled(AppDefault) Game_LoadEnd_ChangeLevel,
        Enabled(AppDefault) Game_LoadBegin_Trigger,
        Enabled(AppDefault) Game_LoadEnd_Trigger,
        Enabled(AppDefault) Game_Pause,
        Enabled(AppDefault) Game_Unpause,
        Enabled(AppDefault) Game_DefineExternals,
        Enabled(AppDefault) Game_ApplyOptions
    );
}