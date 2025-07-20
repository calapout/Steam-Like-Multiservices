//
// Created by calapout on 7/20/25.
//

#pragma once

#include "GameDTO.hpp"

namespace SteamLikeClient
{

	class GameFrame : public Gtk::Frame {
		public:
			// FORCE THE MOVE
			explicit GameFrame(const ServerFacade::GameDTO&& game) : m_game(game)
			{
				this->set_size_request(50, 300);
				this->set_expand(false);
				m_box.set_size_request(50, 300);
				m_box.set_expand(false);

				this->set_halign(Gtk::Align::CENTER);
				this->set_valign(Gtk::Align::CENTER);

				m_box.set_orientation(Gtk::Orientation::VERTICAL);
				m_box.set_halign(Gtk::Align::START);
				m_box.set_valign(Gtk::Align::CENTER);

				// Create a vertical box to hold two labels:
				m_Name.set_size_request(50);
				m_Name.set_expand(false);
				m_Name.set_text(m_game.Name);
				m_Name.set_wrap(true);
				m_Name.set_wrap_mode(Pango::WrapMode::WORD);
				m_Name.set_ellipsize(Pango::EllipsizeMode::NONE);
				m_Name.set_halign(Gtk::Align::START);

				m_Description.set_size_request(50);
				m_Description.set_expand(false);
				m_Description.set_text(m_game.Description);
				m_Description.set_wrap(true);
				m_Description.set_wrap_mode(Pango::WrapMode::WORD);
				m_Description.set_ellipsize(Pango::EllipsizeMode::NONE);
				m_Description.set_halign(Gtk::Align::START);

				m_box.append(m_Name);
				m_box.append(m_Description);
				this->set_child(m_box);
			}

		protected:
			SteamLikeClient::ServerFacade::GameDTO m_game;
			Gtk::Box m_box;
			Gtk::Label m_Name;
			Gtk::Label m_Description;
	};

} // namespace SteamLikeClient
