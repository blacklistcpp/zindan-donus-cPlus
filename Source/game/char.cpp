void CHARACTER::SaveReal()


// ARATILIR


// USTUNE EKLENIR

#ifdef ENABLE_DUNGEON_JOIN_CORDS
	tab.d_map_index = m_points.d_map_index;
#endif



/////////////////////////////////////////////////////////////////////////////////////////////////////////

	m_points.iRandomHP = t->sRandomHP;
	m_points.iRandomSP = t->sRandomSP;

// ARATILIR


// ALTINA EKLENIR

#ifdef ENABLE_DUNGEON_JOIN_CORDS
	m_points.d_map_index = t->d_map_index;
#endif