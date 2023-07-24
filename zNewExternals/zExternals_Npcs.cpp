// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	int Npc_IsInRoutineName()
	{
		zCParser* par = zCParser::GetParser();
		zSTRING routine;
		par->GetParameter(routine);
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
		oCNpc_States* npcStates = nullptr;
		npcStates->npc = npc;

		if (npc)
		{
			routine = npcStates->GetRoutineName();

			if (routine) {
				routine = routine.Upper();
				par->SetReturn(routine);
				return 0;
			}
		}

		par->SetReturn("");
		return 0;
	}

	int Npc_IsInWorld()
	{
		zCParser* par = zCParser::GetParser();
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
		BOOL result = npc && npc->GetHomeWorld() == ogame->GetGameWorld();
		par->SetReturn(result);
		return 0;
	}
}