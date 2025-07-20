//
// Created by calapout on 7/20/25.
//

#pragma once
#include "GameGrid.h"

namespace SteamLikeClient
{

	class SteamClientWindow : public Gtk::Window {
		public:
			SteamClientWindow();
			~SteamClientWindow() override = default;

		protected:
			GameGrid m_Grid;
	};

} // namespace SteamLikeClient
