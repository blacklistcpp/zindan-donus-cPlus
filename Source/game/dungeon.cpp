void CDungeon::Initialize()
{
	deadEvent = NULL;
	// <Factor>
	exit_all_event_ = NULL;
	jump_to_event_ = NULL;
	regen_id_ = 0;

	m_iMobKill = 0;
	m_iStoneKill = 0;
	m_bUsePotion = false;
	m_bUseRevive = false;

	m_iMonsterCount = 0;

	m_bExitAllAtEliminate = false;
	m_bWarpAtEliminate = false;

	m_iWarpDelay = 0;
	m_lWarpMapIndex = 0;
	m_lWarpX = 0;
	m_lWarpY = 0;

	m_stRegenFile = "";

	m_pParty = NULL;
}

// ARATILIR

// ALTINA EKLENİR

#ifdef ENABLE_DUNGEON_JOIN_CORDS
struct FWarpToDungeonCoords
{
	FWarpToDungeonCoords(long lMapIndex, long X, long Y, LPDUNGEON d)
	: m_lMapIndex(lMapIndex), m_x(X), m_y(Y), m_pkDungeon(d)
	{
	}

	void operator () (LPCHARACTER ch)
	{
		ch->SaveExitLocation();
		ch->WarpSet(m_x, m_y, m_lMapIndex);
	}

	long m_lMapIndex;
	long m_x;
	long m_y;
	LPDUNGEON m_pkDungeon;
};

void CDungeon::Join_Coords(LPCHARACTER ch, long X, long Y, long index)
{
	if (SECTREE_MANAGER::instance().GetMap(m_lMapIndex) == NULL) 
	{
		sys_err("CDungeon: SECTREE_MAP not found for #%ld", m_lMapIndex);
		return;
	}
	X*=100;
	Y*=100;
	FWarpToDungeonCoords(m_lMapIndex, X, Y, this) (ch);
}

void CDungeon::JoinParty_Coords(LPPARTY pParty, long X, long Y, long index)
{
	pParty->SetDungeon(this);
	m_map_pkParty.insert(std::make_pair(pParty,0));

	if (SECTREE_MANAGER::instance().GetMap(m_lMapIndex) == NULL) 
	{
		sys_err("CDungeon: SECTREE_MAP not found for #%ld", m_lMapIndex);
		return;
	}
	X*=100;
	Y*=100;
	FWarpToDungeonCoords f(m_lMapIndex, X, Y, this);
	pParty->ForEachOnMapMember(f,index);
}
#endif


///////////////////////////////////////////////////////////////////////////////////////////////


void CDungeon::DecMember(LPCHARACTER ch)
{
	itertype(m_set_pkCharacter) it = m_set_pkCharacter.find(ch);

	if (it == m_set_pkCharacter.end()) {
		return;
	}

	m_set_pkCharacter.erase(it);

	if (m_set_pkCharacter.empty())
	{
		dungeon_id_info* info = AllocEventInfo<dungeon_id_info>();
		info->dungeon_id = m_id;

		event_cancel(&deadEvent);
		
// ARATILIR

// deadEvent kısmı aşağıdaki şekilde değiştirilir
#ifdef ENABLE_DUNGEON_JOIN_CORDS
		deadEvent = event_create(dungeon_dead_event, info, PASSES_PER_SEC(300));
#else
		deadEvent = event_create(dungeon_dead_event, info, PASSES_PER_SEC(10));
#endif
	}
}


