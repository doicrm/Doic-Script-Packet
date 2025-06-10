// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	int Npc_GetRoutineName()
	{
		static zSTRING routine = "";
		auto const par = zCParser::GetParser();
		oCNpc* npc = (oCNpc*)par->GetInstance();
		oCNpc_States* npcStates = &npc->state;
		routine = npcStates ? (zSTRING&)npcStates->GetRoutineName() : "";
		par->SetReturn(routine);
		return 0;
	}

	int Npc_IsInRoutineName()
	{
		auto const par = zCParser::GetParser();
		zSTRING routine, currentRoutine;
		BOOL result = false;
		par->GetParameter(routine);
		oCNpc* npc = (oCNpc*)par->GetInstance();
		oCNpc_States* npcStates = &npc->state;
		currentRoutine = npcStates ? (zSTRING&)npcStates->GetRoutineName() : "";
		routine = routine ? routine.Upper() : "";
		if (!routine.StartWith("RTN_"))
			routine = "RTN_" + routine;
		if (!routine.EndWith("_" + (zSTRING)npc->idx))
			routine = routine + "_" + (zSTRING)npc->idx;
		result = currentRoutine == routine;
		par->SetReturn(result);
		return 0;
	}

	// by Gratt from zParserExtender
	int Npc_GetSlotItem()
	{
		auto const par = zCParser::GetParser();
		zSTRING slotName;
		par->GetParameter(slotName);
		oCNpc* npc = (oCNpc*)par->GetInstance();
		oCItem* item = npc->GetSlotItem(slotName.Upper())->CastTo<oCItem>();
		par->SetReturn(item);
		return 0;
	}

	int Npc_EquipItem()
	{
		auto const par = zCParser::GetParser();
		int index;
		par->GetParameter(index);
		zCPar_Symbol* sym = par->GetSymbol(index);
		oCNpc* npc = (oCNpc*)par->GetInstance();
		oCItem* item = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());
		if (npc && item)
			npc->Equip(item);
		return 0;
	}

	void DefineNpcExternals()
	{
		// func string Npc_GetRoutineName(var C_NPC npc)
		parser->DefineExternal("Npc_GetRoutineName", Npc_GetRoutineName, zPAR_TYPE_STRING, zPAR_TYPE_INSTANCE, 0);
		// func string Npc_IsInRoutineName(var C_NPC npc, var string routine)
		parser->DefineExternal("Npc_IsInRoutineName", Npc_IsInRoutineName, zPAR_TYPE_INT, zPAR_TYPE_INSTANCE, zPAR_TYPE_STRING, 0);
		// func C_Item Npc_GetSlotItem(var C_NPC npc)
		parser->DefineExternal("Npc_GetSlotItem", Npc_GetSlotItem, zPAR_TYPE_INSTANCE, zPAR_TYPE_INSTANCE, zPAR_TYPE_STRING, 0);
		// func void Npc_EquipItem(var C_NPC npc, var int itemInstance)
		parser->DefineExternal("Npc_EquipItem", Npc_EquipItem, zPAR_TYPE_VOID, zPAR_TYPE_INSTANCE, zPAR_TYPE_INT, 0);
	}
}