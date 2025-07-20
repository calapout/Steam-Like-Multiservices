//
// Created by calapout on 7/20/25.
//

#pragma once
#include "GameFrame.h"

namespace SteamLikeClient
{
	class GameGrid : public Gtk::Grid {
		public:
			explicit GameGrid(int nb_col = 3);

		private:
			int m_Cols;
			std::vector<GameFrame> m_gameFrames;
	};

} // namespace SteamLikeClient
