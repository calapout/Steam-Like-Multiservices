//
// Created by calapout on 5/10/25.
//

#include "ServerFacade.hpp"

#include "boost/json.hpp"

#include "HttpLibrary.hpp"

namespace SteamLikeClient::ServerFacade
{
	void ServerFacade::Init(const std::shared_ptr<boost::asio::io_context>& context)
	{
		facadeContext = context;
	}

	std::expected<HttpLibrary::HttpResponse<std::vector<GameDTO>>, std::string> ServerFacade::GetGames()
	{
		if (!facadeContext)
		{
			return std::unexpected("Current context is invalid, did you call ServerFacade::Init?");
		}

		HttpLibrary::HttpGetRequest<std::vector<GameDTO>> getRequest(*facadeContext, "localhost", 8080, "/games", PARAM_VECTOR{});
		return getRequest.Run();
	}
	std::expected<HttpLibrary::HttpResponse<GameDTO>, std::string> ServerFacade::GetGame(int id)
	{
		if (!facadeContext)
		{
			return std::unexpected("Current context is invalid, did you call ServerFacade::Init?");
		}

		HttpLibrary::HttpGetRequest<GameDTO> getRequest(*facadeContext, "localhost", 8080, "/games/" + std::to_string(id), PARAM_VECTOR{});
		return getRequest.Run();
	}
} // namespace SteamLikeClient::ServerFacade
