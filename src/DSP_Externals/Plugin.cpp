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

      //---------------------------------------------------------------------
      // LOG
      //---------------------------------------------------------------------

      // func int Log_GetTopicStatus(var string logName) 
      parser->DefineExternal("Log_GetTopicStatus", Log_GetTopicStatus, INT, STR, 0);
      // parser->DefineExternal("DIA_AddChoice", DIA_AddChoice, VOID, STR, FUNC, 0);

      //---------------------------------------------------------------------
      // NPC
      //---------------------------------------------------------------------

      // func int Npc_IsInRoutineName(var C_NPC npc, var string routine)
      parser->DefineExternal("Npc_IsInRoutineName", Npc_IsInRoutineName, INT, INST, STR, 0);
      // func void Npc_EquipItem(var C_NPC npc, var int itemInstance)
      parser->DefineExternal("Npc_EquipItem", Npc_EquipItem, VOID, INST, INT, 0);

      //---------------------------------------------------------------------
      // WLD
      //---------------------------------------------------------------------

      // func string Wld_GetPlayerPortalRoom()
      parser->DefineExternal("Wld_GetPlayerPortalRoom", Wld_GetPlayerPortalRoom, STR, 0);

      // func void Wld_InsertVob(var string vobName, var string point)
      parser->DefineExternal("Wld_InsertVob", Wld_InsertVob, VOID, STR, STR, 0);
      // func void Wld_InsertVobPos(var string vobName, var C_POSITION vobPosition)
      parser->DefineExternal("Wld_InsertVobPos", Wld_InsertVobPos, VOID, STR, INST, 0);
      // func void Wld_InsertMob(var string vobName, var string point)
      parser->DefineExternal("Wld_InsertMob", Wld_InsertMob, VOID, STR, STR, 0);
      // func void Wld_InsertMobInter(var string vobName, var string point)
      parser->DefineExternal("Wld_InsertMobInter", Wld_InsertMobInter, VOID, STR, STR, 0);
      // func void Wld_InsertMobContainer(var string vobName, var string point)
      parser->DefineExternal("Wld_InsertMobContainer", Wld_InsertMobContainer, VOID, STR, STR, 0);
      // func void Wld_InsertMobFire(var string vobName, var string point)
      parser->DefineExternal("Wld_InsertMobFire", Wld_InsertMobFire, VOID, STR, STR, 0);
      // func void Wld_InsertMobDoor(var string vobName, var string point)
      parser->DefineExternal("Wld_InsertMobDoor", Wld_InsertMobDoor, VOID, STR, STR, 0);
      // func void Wld_InsertMobBed(var string vobName, var string point)
      parser->DefineExternal("Wld_InsertMobBed", Wld_InsertMobBed, VOID, STR, STR, 0);
      // func void Wld_InsertMobPos(var string vobName, var C_POSITION vobPosition)
      parser->DefineExternal("Wld_InsertMobPos", Wld_InsertMobPos, VOID, STR, INST, 0);
      // func void Wld_InsertMobInterPos(var string vobName, var C_POSITION vobPosition)
      parser->DefineExternal("Wld_InsertMobInterPos", Wld_InsertMobInterPos, VOID, STR, INST, 0);
      // func void Wld_InsertMobContainerPos(var string vobName, var C_POSITION vobPosition)
      parser->DefineExternal("Wld_InsertMobContainerPos", Wld_InsertMobContainerPos, VOID, STR, INST, 0);
      // func void Wld_InsertMobFirePos(var string vobName, var C_POSITION vobPosition)
      parser->DefineExternal("Wld_InsertMobFirePos", Wld_InsertMobFirePos, VOID, STR, INST, 0);
      // func void Wld_InsertMobDoorPos(var string vobName, var C_POSITION vobPosition)
      parser->DefineExternal("Wld_InsertMobDoorPos", Wld_InsertMobDoorPos, VOID, STR, INST, 0);
      // func void Wld_InsertMobBedPos(var string vobName, var C_POSITION vobPosition)
      parser->DefineExternal("Wld_InsertMobBedPos", Wld_InsertMobBedPos, VOID, STR, INST, 0);

      // func int Wld_RemoveVob(var string vobName)
      parser->DefineExternal("Wld_RemoveVob", Wld_RemoveVob, INT, STR, 0);

      // func C_Position Wld_GetPos(var int posX, var int posY, vart int posZ)
      parser->DefineExternal("Wld_GetPos", Wld_GetPos, INST, INT, INT, INT, 0);

      //---------------------------------------------------------------------
      // CAST
      //--------------------------------------------------------------------- 

      // func int Cast_InstanceIsVob(var instance object)
      parser->DefineExternal("Cast_InstanceIsVob", Cast_InstanceIsVob, INT, INST, 0);

      //---------------------------------------------------------------------
      // HLP
      //--------------------------------------------------------------------- 

      // func C_Item Hlp_GetItem(var int itemInstance)
      parser->DefineExternal("Hlp_GetItem", Hlp_GetItem, INST, INT, 0);
      // func int Hlp_IsValidVob(var instance object)
      parser->DefineExternal("Hlp_IsValidVob", Hlp_IsValidVob, INT, INST, 0);

      parserMenu->DefineExternal("Hlp_StrCmp", Hlp_StrCmp, INT, STR, STR, 0);

      //---------------------------------------------------------------------
      // VOB
      //---------------------------------------------------------------------

      // func void Vob_Rotate(var string vobName, var C_Position vobPosition)
      parser->DefineExternal("Vob_Rotate", Vob_Rotate, VOID, STR, INST, 0);
      // func void Vob_MoveTo(var string vobName, var string point)
      parser->DefineExternal("Vob_MoveTo", Vob_MoveTo, VOID, STR, STR, 0);
      // func void Vob_SetOnFloor(var string vobName)
      parser->DefineExternal("Vob_SetOnFloor", Vob_SetOnFloor, VOID, STR, 0);
      // func void Vob_SetVisual(var string vobName, var string visualName)
      parser->DefineExternal("Vob_SetVisual", Vob_SetVisual, VOID, STR, STR, 0);

      //---------------------------------------------------------------------
      // AI
      //---------------------------------------------------------------------

      // func void AI_TurnToWP(var C_NPC npc, var string wp)
      parser->DefineExternal("AI_TurnToWP", AI_TurnToWP, VOID, INST, STR, 0);
      // func void AI_TurnToVob(var C_NPC npc, var string vobName)
      parser->DefineExternal("AI_TurnToVob", AI_TurnToVob, VOID, INST, STR, 0);

      //---------------------------------------------------------------------
      // STR
      //---------------------------------------------------------------------

      // var string Str_Upper(var string str)
      parser->DefineExternal("Str_Upper", Str_Lower, STR, STR, 0);
      // var string Str_Lower(var string str)
      parser->DefineExternal("Str_Lower", Str_Lower, STR, STR, 0);
      // var string Str_Capitel(var string str)
      parser->DefineExternal("Str_Capitel", Str_Capitel, STR, STR, 0);

      //---------------------------------------------------------------------
      // Other
      //---------------------------------------------------------------------

      parser->DefineExternal("GetIntArrayValue", Ext_ReadStatArray<int>, INT, INT, INT, 0);
      parser->DefineExternal("GetStringArrayValue", Ext_ReadStatArray<zSTRING>, STR, STR, INT, 0);
      parser->DefineExternal("SetIntArrayValue", Ext_WriteStatArray<int>, VOID, INT, INT, INT, 0);
      parser->DefineExternal("SetStringArrayValue", Ext_WriteStatArray<zSTRING>, VOID, STR, INT, STR, 0);

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