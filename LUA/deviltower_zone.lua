

		when login begin
			if pc.get_map_index() == 66 then
				if pc.get_x() < 2048+88 or pc.get_y() < 6656+577 or pc.get_x() > 2048+236 or pc.get_y() > 6656+737 then
					pc.warp(590500, 110500)
				end
				pc.set_warp_location(65, 5905, 1105)
			elseif pc.get_map_index() >= 660000 and pc.get_map_index() < 670000 then
				pc.set_dungeonindex(d.get_map_index()). -- ZINDAN GERI DONUS
				pc.set_warp_location(65, 5905, 1105)				
				deviltower_zone.register_player(pc.get_vid())
			end
		end
		
		-- WHEN LOGIN BEGIN KISMINI BU SEKILDE DUZENLEYIN


		-- ALTINA BUNU EKLEYİN

		when deviltower_man.chat."Kaldığın Yerden Devam Et" with d.find(pc.get_dungeonindex()) begin
			local n = pc.get_dungeonindex()
			local oldumu = d.getf_from_map_index("azrail_dead", n)
			local level = d.getf_from_map_index("level", n)
			if level < 2 then
				say("2. Katı geçemediğiniz için devam edemezsin.")
				return
			end
			if oldumu == 1 then
				say_npc()
				say("Azraili zaten yok etmişsin.")
				return
			end
			if n == 0 then
				setskin(NOWINDOW)
				return
			else
				say_npc()
				say("")
				say("Kaldığın yerden devam etmek istiyor musun?")
				if select(locale.yes,locale.no) == 1 then
					pc.warp(special.devil_tower[level-1][1]*100, special.devil_tower[level-1][2]*100,n)
				end
			end
		end



