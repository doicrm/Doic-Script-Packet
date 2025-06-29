// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	int AI_TurnToWP()
	{
		auto const par = zCParser::GetParser();
		zSTRING point;
		par->GetParameter(point);
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
		zCWaypoint* wp = ogame->GetWorld()->wayNet->GetWaypoint(point);
		if (wp)
		{
			npc->GetEM(0)->OnMessage(new oCMsgMovement(oCMsgMovement::EV_TURNTOVOB, (zCVob*)wp), npc);
			return 0;
		}
		zCVob* vob = ogame->GetGameWorld()->SearchVobByName(point);
		if (vob)
			npc->GetEM(0)->OnMessage(new oCMsgMovement(oCMsgMovement::EV_TURNTOVOB, vob), npc);
		return 0;
	}

	int AI_TurnToVob()
	{
		auto const par = zCParser::GetParser();
		zSTRING point;
		par->GetParameter(point);
		oCNpc* npc = dynamic_cast<oCNpc*>((zCVob*)par->GetInstance());
		zCVob* vob = ogame->GetGameWorld()->SearchVobByName(point);
		if (vob)
			npc->GetEM(FALSE)->OnMessage(new oCMsgMovement(oCMsgMovement::EV_TURNTOVOB, vob), npc);
		return 0;
	}
}