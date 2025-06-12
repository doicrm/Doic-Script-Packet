// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	int Npc_IsInRoutineName()
	{
		BOOL result = false;
		auto const par = zCParser::GetParser();
		zSTRING routine, currentRoutine;
		par->GetParameter(routine);
		oCNpc* npc = (oCNpc*)par->GetInstance();
		currentRoutine = npc->state.GetRoutineName().Upper();
		routine = routine.Upper();

		if (!routine.StartWith("RTN_"))
			routine = "RTN_" + routine;

		zSTRING npcId = zSTRING(npc->idx);
		if (!routine.EndWith("_" + npcId))
			routine = routine + "_" + npcId;

		result = currentRoutine == routine.Upper();
		par->SetReturn(result);
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