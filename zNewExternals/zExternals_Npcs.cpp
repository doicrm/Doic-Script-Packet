// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

	int Npc_GetRoutineName() // FIXME: Doesn't return routine's name correctly!
	{
		zCParser* par = zCParser::GetParser();
		zSTRING routine;
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
		if (npc)
		{
			oCNpc_States* npcStates = &npc->state;
			if (npcStates)
			{
				routine = npcStates->GetRoutineName();
				par->SetReturn(routine);
				return 0;
			}
		}
		par->SetReturn("");
		return 0;
	}

	int Npc_IsInRoutineName()
	{
		zCParser* par = zCParser::GetParser();
		zSTRING routine, currentRoutine;
		BOOL result = false;
		par->GetParameter(routine);
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
		if (npc)
		{
			oCNpc_States* npcStates = &npc->state;
			if (npcStates)
			{
				currentRoutine = npcStates->GetRoutineName();
				routine = routine.Upper();
				if (!routine.StartWith("RTN_"))
					routine = "RTN_" + routine;
				if (!routine.EndWith("_" + (zSTRING)npc->idx))
					routine = routine + "_" + (zSTRING)npc->idx;
				result = currentRoutine == routine;
			}
		}
		par->SetReturn(result);
		return 0;
	}

	int Npc_GetSlotItem()
	{
		zCParser* par = zCParser::GetParser();
		zSTRING slot;
		par->GetParameter(slot);
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
		oCItem* item = npc->GetSlotItem(slot);
		item ? par->SetReturn(item) : par->SetReturn(-1);
		return 0;
	}

	int Npc_EquipItem()
	{
		zCParser* par = zCParser::GetParser();
		oCItem* item = (oCItem*)par->GetInstance();
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
		npc->Equip(item);
		return 0;
	}

	int Npc_IsInWorld()
	{
		zCParser* par = zCParser::GetParser();
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
		BOOL result = false;
		if (npc)
			result = npc->GetHomeWorld() == ogame->GetGameWorld();
		par->SetReturn(result);
		return 0;
	}
}