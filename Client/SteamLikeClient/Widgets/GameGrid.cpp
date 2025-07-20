//
// Created by calapout on 7/20/25.
//

#include "GameGrid.h"

namespace SteamLikeClient
{
	GameGrid::GameGrid(int nb_col) : m_Cols(nb_col)
	{
		ServerFacade::ServerFacade serverFacade;
		const std::expected<HttpLibrary::HttpResponse<std::vector<ServerFacade::GameDTO>>, std::string> response = serverFacade.GetGames();

		this->set_expand();
		this->set_row_spacing(32);
		this->set_column_spacing(32);
		this->set_margin(16);

		if (!response)
		{
			std::cerr << response.error() << std::endl;
			return;
		}

		if (response->StatusCode == 200)
		{
			for (const auto& game: response->Data)
			{
				int col = get_children().size() % m_Cols;
				int row = get_children().size() / m_Cols;

				GameFrame frame(std::move(game));
				m_gameFrames.emplace_back(std::move(frame));
				attach(m_gameFrames.back(), col, row);
			}
		}
	};
} // namespace SteamLikeClient
