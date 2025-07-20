#include "Widgets/SteamClientWindow.h"
#include "gtkmm-4.0/gtkmm.h"

int main(int argc, char* argv[])
{
	// INIT FACADE
	std::shared_ptr<boost::asio::io_context> io_context = std::make_shared<boost::asio::io_context>();
	SteamLikeClient::ServerFacade::ServerFacade::Init(io_context);

	auto game = SteamLikeClient::ServerFacade::ServerFacade::GetGame(0);
	if (game)
	{
		std::cout << std::format("[Id: {}] - Name: {}, Description: {}", game->Data.Id, game->Data.Name, game->Data.Description) << "\n";
	}
	else
	{
		std::cerr << "Failed to get game: " << game.error() << std::endl;
	}

	// OPEN APPLICATION
	const auto app = Gtk::Application::create("com.calapout.SteamLikeClient");

	return app->make_window_and_run<SteamLikeClient::SteamClientWindow>(argc, argv);
}
