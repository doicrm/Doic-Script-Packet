// This file added in headers queue
// File: "Sources.h"
#include "resource.h"

namespace GOTHIC_ENGINE {

  // TO DO
  // Your code ...

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

#define INT  zPAR_TYPE_INT
#define FLT  zPAR_TYPE_FLOAT
#define INST zPAR_TYPE_INSTANCE
#define FUNC zPAR_TYPE_FUNC
#define STR  zPAR_TYPE_STRING
#define VOID zPAR_TYPE_VOID

      //---------------------------------------------------------------------
      // MENU
      //---------------------------------------------------------------------

      // func void Menu_SetItemText(var string menuItemName, var string value)
      parser->DefineExternal("Menu_SetItemText", Menu_SetItemText, VOID, STR, STR, 0);
      parserMenu->DefineExternal("Menu_SetItemText", Menu_SetItemText, VOID, STR, STR, 0);

      // func string Menu_GetItemText(var string menuItemName)
      parser->DefineExternal("Menu_GetItemText", Menu_GetItemText, STR, STR, 0);
      parserMenu->DefineExternal("Menu_GetItemText", Menu_GetItemText, STR, STR, 0);

      parserMenu->DefineExternal("Hlp_StrCmp", Hlp_StrCmp, INT, STR, STR, 0);

      //---------------------------------------------------------------------
      // LOG
      //---------------------------------------------------------------------

      // func int Log_GetTopicStatus(var string logName) 
      parser->DefineExternal("Log_GetTopicStatus", Log_GetTopicStatus, INT, STR, 0);
      //parser->DefineExternal("DIA_AddChoice", DIA_AddChoice, VOID, STR, FUNC, 0);

      //---------------------------------------------------------------------
      // NPC
      //---------------------------------------------------------------------

      // func string Npc_GetRoutineName(var C_NPC npc)
      parser->DefineExternal("Npc_GetRoutineName", Npc_GetRoutineName, STR, INST, 0);
      // func int Npc_IsInRoutineName(var C_NPC npc, var string routine)
      parser->DefineExternal("Npc_IsInRoutineName", Npc_IsInRoutineName, INT, INST, STR, 0);
      // func C_Item Npc_GetSlotItem(var C_NPC npc)
      parser->DefineExternal("Npc_GetSlotItem", Npc_GetSlotItem, INST, INST, STR, 0);
      // func void Npc_EquipItem(var C_NPC npc, var int itemInstance)
      parser->DefineExternal("Npc_EquipItem", Npc_EquipItem, VOID, INST, INT, 0);

      //---------------------------------------------------------------------
      // Item
      //---------------------------------------------------------------------

      // func C_Item Hlp_GetItem(var int itemInstance)
      parser->DefineExternal("Hlp_GetItem", Hlp_GetItem, INST, INT, 0);

      //---------------------------------------------------------------------
      // WLD
      //---------------------------------------------------------------------

      parser->DefineExternal("Wld_PlayEffectOnVob", Wld_PlayEffectOnVob, VOID, STR, INST, INT, INT, INT, INT, 0);
      parser->DefineExternal("Wld_PlayEffectAt", Wld_PlayEffectAt, VOID, STR, INST, INT, INT, INT, INT, 0);
      // func string Wld_GetPlayerPortalRoom()
      parser->DefineExternal("Wld_GetPlayerPortalRoom", Wld_GetPlayerPortalRoom, STR, 0);

      //---------------------------------------------------------------------
      // VOB
      //---------------------------------------------------------------------

      // func void Wld_InsertVob(var string vobName, var string visualName, var string point, var int isCollDet)
      parser->DefineExternal("Wld_InsertVob", Wld_InsertVob, VOID, STR, STR, STR, INT, 0);
      // func void Wld_InsertVobPos(var string vobName, var string visualName, var int posx, var int posy, var int posz, var int isCollDet)
      parser->DefineExternal("Wld_InsertVobPos", Wld_InsertVobPos, VOID, STR, STR, INT, INT, INT, INT, 0);
      // func int Wld_RemoveVob(var string vobName)
      parser->DefineExternal("Wld_RemoveVob", Wld_RemoveVob, INT, STR, 0);
      // func void Vob_Rotate(var string vobName, var int posx, var int posy, var int posz)
      parser->DefineExternal("Vob_Rotate", Vob_Rotate, VOID, STR, INT, INT, INT, 0);
      // func void Vob_SetVisual(var string vobName, var string visualName)
      parser->DefineExternal("Vob_SetVisual", Vob_SetVisual, VOID, STR, STR, 0);
      // func void Vob_ClearVisual(var string vobName)
      parser->DefineExternal("Vob_ClearVisual", Vob_ClearVisual, VOID, STR, 0);
      // func void Vob_SetName(var string oldVobName, var string newVobName)
      parser->DefineExternal("Vob_SetName", Vob_SetName, VOID, STR, STR, 0);
      // func void Vob_MoveTo(var string vobName, var string point)
      parser->DefineExternal("Vob_MoveTo", Vob_MoveTo, VOID, STR, STR, 0);
      // func void Vob_MoveToPos(var string vobName, var int posx, var int posy, var int posz)
      parser->DefineExternal("Vob_MoveToPos", Vob_MoveToPos, VOID, STR, INT, INT, INT, 0);
      // func int Vob_SearchByName(var string vobName)
      parser->DefineExternal("Vob_SearchByName", Vob_SearchByName, VOID, STR, 0);
      // func void Wld_InsertMobInter(var string vobName, var string visualName, var string point)
      parser->DefineExternal("Wld_InsertMobInter", Wld_InsertMobInter, VOID, STR, STR, STR, 0);
      // func void Wld_InsertMobContainer(var string vobName, var string visualName, var string point)
      parser->DefineExternal("Wld_InsertMobContainer", Wld_InsertMobContainer, VOID, STR, STR, STR, 0);

      //---------------------------------------------------------------------
      // AI
      //---------------------------------------------------------------------

      // func void AI_TurnToWP(var C_NPC npc, var string wp)
      parser->DefineExternal("AI_TurnToWP", AI_TurnToWP, VOID, INST, STR, 0);
      // func void AI_TurnToVob(var C_NPC npc, var string vobName)
      parser->DefineExternal("AI_TurnToVob", AI_TurnToVob, VOID, INST, STR, 0);

      //---------------------------------------------------------------------
      // Other
      //---------------------------------------------------------------------

      parser->DefineExternal("GetIntArrayValue", Ext_ReadStatArray<int>, INT, INT, INT, 0);
      parser->DefineExternal("GetStringArrayValue", Ext_ReadStatArray<zSTRING>, STR, STR, INT, 0);
      parser->DefineExternal("SetIntArrayValue", Ext_WriteStatArray<int>, VOID, INT, INT, INT, 0);
      parser->DefineExternal("SetStringArrayValue", Ext_WriteStatArray<zSTRING>, VOID, STR, INT, STR, 0);

      // var string Str_ToUpperCase(var string str)
      parser->DefineExternal("Str_ToUpperCase", Str_ToUpperCase, STR, STR, 0);
      // var string Str_ToLowerCase(var string str)
      parser->DefineExternal("Str_ToLowerCase", Str_ToLowerCase, STR, STR, 0);
      // var string Str_ToCapitelCase(var string str)
      parser->DefineExternal("Str_ToCapitelCase", Str_ToCapitelCase, STR, STR, 0);

#undef INT
#undef FLT
#undef INST
#undef FUNC
#undef STR

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
    Enabled( AppDefault ) Game_Entry,
    Enabled( AppDefault ) Game_Init,
    Enabled( AppDefault ) Game_Exit,
    Enabled( AppDefault ) Game_PreLoop,
    Enabled( AppDefault ) Game_Loop,
    Enabled( AppDefault ) Game_PostLoop,
    Enabled( AppDefault ) Game_MenuLoop,
    Enabled( AppDefault ) Game_SaveBegin,
    Enabled( AppDefault ) Game_SaveEnd,
    Enabled( AppDefault ) Game_LoadBegin_NewGame,
    Enabled( AppDefault ) Game_LoadEnd_NewGame,
    Enabled( AppDefault ) Game_LoadBegin_SaveGame,
    Enabled( AppDefault ) Game_LoadEnd_SaveGame,
    Enabled( AppDefault ) Game_LoadBegin_ChangeLevel,
    Enabled( AppDefault ) Game_LoadEnd_ChangeLevel,
    Enabled( AppDefault ) Game_LoadBegin_Trigger,
    Enabled( AppDefault ) Game_LoadEnd_Trigger,
    Enabled( AppDefault ) Game_Pause,
    Enabled( AppDefault ) Game_Unpause,
    Enabled( AppDefault ) Game_DefineExternals,
    Enabled( AppDefault ) Game_ApplyOptions
  );
}