// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

	int Npc_GetRoutineName() // FIXME: Wartoœæ string nie jest wyœwietlana w grze
	{
		zCParser* par = zCParser::GetParser();
		zSTRING routine;
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
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