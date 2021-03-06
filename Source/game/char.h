
typedef struct character_point
{
#ifdef ENABLE_YANG_LIMIT_SYSTEM
	long long		points[POINT_MAX_NUM];
#else
	long			points[POINT_MAX_NUM];
#endif

	BYTE			job;
	BYTE			voice;

	BYTE			level;
	DWORD			exp;
#ifdef ENABLE_YANG_LIMIT_SYSTEM
	long long		gold;
#else
	long			gold;
#endif

	int				hp;
	int				sp;

	int				iRandomHP;
	int				iRandomSP;

	int				stamina;

	BYTE			skill_group;
	
// ARATILIR

// ALTINA EKLENİR
#ifdef ENABLE_DUNGEON_JOIN_CORDS
	long			d_map_index;
#endif


////////////////////////////////////////////////////////////////////////////////

// EN ALTINA IN

};

ESex GET_SEX(LPCHARACTER ch);

#endif

// USTUNE EKLE


#ifdef ENABLE_DUNGEON_JOIN_CORDS
public:
	long	GetPlayerDungeonIndex()	{ return m_points.d_map_index; }
	void	SetPlayerDungeonIndex(long vnum)	{ m_points.d_map_index = vnum; }
#endif

