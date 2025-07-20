//
// Created by calapout on 5/10/25.
//

#pragma once

#include "HttpLibrary.hpp"
#include "GameDTO.hpp"

namespace SteamLikeClient::ServerFacade
{
	class ServerFacade {
		public:
			static void Init(const std::shared_ptr<boost::asio::io_context>& context);
			static std::expected<HttpLibrary::HttpResponse<std::vector<GameDTO>>, std::string> GetGames();
			static std::expected<HttpLibrary::HttpResponse<GameDTO>, std::string> GetGame(int id);

		protected:
			inline static std::shared_ptr<boost::asio::io_context> facadeContext = nullptr;
	};
} // namespace SteamLikeClient::ServerFacade