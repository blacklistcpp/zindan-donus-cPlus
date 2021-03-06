size_t CreatePlayerSaveQuery(char* pszQuery, size_t querySize, TPlayerTable* pkTab)
{
	size_t queryLen;

	queryLen = snprintf(pszQuery, querySize,
		"horse_stamina = %d, "
		"horse_skill_point = %d, "

// ARATILIR 


// ALTINA EKLEN?R
#ifdef ENABLE_DUNGEON_JOIN_CORDS
		"d_map_index = %d, "
#endif
		,

///////////////////////////////////////////////////////////////////////////////////////////////////

	static char text[8192 + 1];

// ARATILIR


// USTUNE EKLEN?R

#ifdef ENABLE_DUNGEON_JOIN_CORDS
		,pkTab->d_map_index
#endif
		);



///////////////////////////////////////////////////////////////////////////////////////////////////

		snprintf(queryStr, sizeof(queryStr),
			"SELECT "
			"id,name,job,voice,dir,x,y,z,map_index,exit_x,exit_y,exit_map_index,hp,mp,stamina,random_hp,random_sp,playtime,"
			"gold,level,level_step,st,ht,dx,iq,exp,"
			"stat_point,skill_point,sub_skill_point,stat_reset_count,part_base,part_hair,"
#ifdef ENABLE_ACCE_SYSTEM
			"part_acce, "
#endif
			"skill_level,quickslot,skill_group,alignment,horse_level,horse_riding,horse_hp,horse_hp_droptime,horse_stamina,"
			"UNIX_TIMESTAMP(NOW())-UNIX_TIMESTAMP(last_play),horse_skill_point"


// ARATILIR


// ALTINA EKLEN?R

#ifdef ENABLE_DUNGEON_JOIN_CORDS
			",d_map_index "
#endif


///////////////////////////////////////////////////////////////////////////////////////////////////


bool CreatePlayerTableFromRes(MYSQL_RES* res, TPlayerTable* pkTab)
{

	str_to_number(pkTab->skill_group, row[col++]);
	str_to_number(pkTab->lAlignment, row[col++]);

	str_to_number(pkTab->horse.bLevel, row[col++]);
	str_to_number(pkTab->horse.bRiding, row[col++]);
	str_to_number(pkTab->horse.sHealth, row[col++]);
	str_to_number(pkTab->horse.dwHorseHealthDropTime, row[col++]);
	str_to_number(pkTab->horse.sStamina, row[col++]);
	str_to_number(pkTab->logoff_interval, row[col++]);
	str_to_number(pkTab->horse_skill_point, row[col++]);


// ARATILIR 

// ALTINA EKLEN?R
#ifdef ENABLE_DUNGEON_JOIN_CORDS
	str_to_number(pkTab->d_map_index, row[col++]);
#endif
