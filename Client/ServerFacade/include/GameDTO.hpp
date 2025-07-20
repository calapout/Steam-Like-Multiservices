//
// Created by calapout on 5/10/25.
//

#ifndef GAME_H
#define GAME_H

#include "boost/describe.hpp"

namespace SteamLikeClient::ServerFacade {
	struct GameDTO {
		int Id;
		std::string Name;
		std::string Description;
	};

	BOOST_DESCRIBE_STRUCT(GameDTO, (), (Id, Name, Description))
}

#endif //GAME_H
