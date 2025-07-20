//
// Created by calapout on 7/20/25.
//

#include "SteamClientWindow.h"

namespace SteamLikeClient
{
	SteamClientWindow::SteamClientWindow()
	{
		this->set_title("GTK Steam Client");
		this->set_default_size(1920, 1080);
		this->set_child(m_Grid);
	}
} // namespace SteamLikeClient
