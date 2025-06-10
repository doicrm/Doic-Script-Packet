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
}