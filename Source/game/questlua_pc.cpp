
// EN ALTA IN
// void RegisterPCFunctionTable() BULUNUR
// USTUNE EKLEN?R


#ifdef ENABLE_DUNGEON_JOIN_CORDS
	ALUA(pc_get_dungeonindex)  
	{
		lua_pushnumber(L, CQuestManager::instance().GetCurrentCharacterPtr()->GetPlayerDungeonIndex());
		return 1;
	}

	ALUA(pc_set_dungeonindex)  
	{
		if (!lua_isnumber(L, 1))
		{
			sys_err("invalid argument");
			return 0;
		}
		else
		{
			long newIndex = lua_tonumber(L, 1);
			LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

			ch->SetPlayerDungeonIndex(newIndex);

			return 0;
		}
	}
#endif

///////////////////////////////////////////////////////////////////////////////////////////

// EN ALTA IN
// { NULL,			NULL			} BULUNUR
// USTUNE EKLEN?R

#ifdef ENABLE_DUNGEON_JOIN_CORDS
			{"get_dungeonindex", pc_get_dungeonindex},
			{"set_dungeonindex", pc_set_dungeonindex},
#endif