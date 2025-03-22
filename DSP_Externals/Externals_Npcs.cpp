// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	int Npc_GetRoutineName() // FIXME: Doesn't return routine's name correctly!
	{
		auto const par = zCParser::GetParser();
		zSTRING routine = "";
		oCNpc* npc = (oCNpc*)par->GetInstance();
		if (npc)
		{
			oCNpc_States* npcStates = &npc->state;
			if (npcStates)
				routine = npcStates->GetRoutineName();
		}
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

	// by Gratt from zParserExtender
	int Npc_GetSlotItem()
	{
		auto const par = zCParser::GetParser();
		oCNpc* npc;
		zSTRING slotName;
		par->GetParameter(slotName);
		npc = (oCNpc*)par->GetInstance();
		oCItem* item = npc->GetSlotItem(slotName.Upper())->CastTo<oCItem>();
		par->SetReturn(item);
		return 0;
	}

	int Npc_EquipItem()
	{
		auto const par = zCParser::GetParser();
		oCItem* item = (oCItem*)par->GetInstance();
		oCNpc* npc = (oCNpc*)par->GetInstance();
		npc->Equip(item);
		return 0;
	}

	int Npc_IsInWorld()
	{
		auto const par = zCParser::GetParser();
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
		BOOL result = false;
		if (npc)
			result = npc->GetHomeWorld()->GetObjectName() == ogame->GetGameWorld()->GetObjectName();
		par->SetReturn(result);
		return 0;
	}
}