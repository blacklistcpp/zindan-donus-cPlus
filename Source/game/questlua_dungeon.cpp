
// EN ALTA İNİLİR
// void RegisterDungeonFunctionTable() BULUNUR
// ÜSTÜNE EKLENİR

#ifdef ENABLE_DUNGEON_JOIN_CORDS
	int dungeon_join_coords(lua_State* L)
	{
		if (lua_gettop(L)<3 || !lua_isnumber(L,1) || !lua_isnumber(L, 2) || !lua_isnumber(L,3))
		{
			sys_err("not enough argument");
			return 0;
		}

		long lMapIndex = (long)lua_tonumber(L, 1);
		
		LPDUNGEON pDungeon = CDungeonManager::instance().Create(lMapIndex);

		if (!pDungeon)
			return 0;

		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		long index2 = (long)ch->GetMapIndex();

		if (ch->GetParty() && ch->GetParty()->GetLeaderPID() == ch->GetPlayerID())
			pDungeon->JoinParty_Coords(ch->GetParty(), (long)lua_tonumber(L, 2), (long)lua_tonumber(L, 3),index2);
		else if (!ch->GetParty())
			pDungeon->Join_Coords(ch, (long)lua_tonumber(L, 2), (long)lua_tonumber(L, 3),index2);

		return 0;
	}
#endif


///////////////////////////////////////////////////////////////////////////////////////////////////////////////


// EN ALTA İNİLİR
// { NULL,				NULL			} BULUNUR
//ÜSTÜNE EKLENİR


#ifdef ENABLE_DUNGEON_JOIN_CORDS
			{ "join_cords",		dungeon_join_coords	},
#endif