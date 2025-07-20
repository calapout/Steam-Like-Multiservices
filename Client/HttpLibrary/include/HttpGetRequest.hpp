//
// Created by calapout on 7/20/25.
//

#pragma once

#include <ranges>


#include "HttpResponse.hpp"
#include "pch.hpp"

namespace SteamLikeClient::HttpLibrary
{
	template<class ResponseType>
	class HttpGetRequest {
		public:
			explicit HttpGetRequest(boost::asio::io_context& context, const std::string& host, int port, const std::string& path, const PARAM_VECTOR& params) :
				m_Host(host), m_Port(port), m_Context(context), m_Path(path), m_Params(params)
			{}

			explicit HttpGetRequest(boost::asio::io_context& context, const std::string& host, int port, const std::string& path, PARAM_VECTOR&& params) :
				m_Host(host), m_Port(port), m_Context(context), m_Path(path), m_Params(params)
			{}
			std::expected<HttpResponse<ResponseType>, std::string> Run()
			{
				try
				{
					ip::tcp::resolver resolver(m_Context);
					ip::tcp::socket socket{m_Context};

					auto const result = resolver.resolve(m_Host, std::to_string(m_Port));
					if (result.empty())
					{
						return std::unexpected("Could not resolve " + m_Host + ":" + std::to_string(m_Port));
					}

					boost::asio::connect(socket, result.cbegin(), result.cend());


					std::stringstream query;
					query << m_Path;

					if (!m_Params.empty())
					{
						query << "?" << m_Params[0].first << "=" << m_Params[0].second;
						;

						for (int i = 1; i < m_Params.size(); ++i)
						{
							query << "&" << m_Params[i].first << "=" << m_Params[i].second;
						}
					}

					auto verb = http::verb::get;

					http::request<http::string_body> req(verb, query.str(), 11);
					req.set(http::field::host, m_Host);
					req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

					http::write(socket, req);

					boost::beast::flat_buffer flatBuffer;
					http::response<http::string_body> response;
					http::read(socket, flatBuffer, response);

					switch (response.result())
					{
						case http::status::ok: {
							ResponseType responseData;
							boost::json::parse_into<ResponseType>(responseData, response.body());
							return HttpResponse<ResponseType>{200, std::move(responseData)};
						}
						default:
							return std::unexpected("Status is different than ok, could not parse the data");
					}
				} catch (boost::system::system_error error)
				{
					return std::unexpected(std::string("Error happened while doing the request: ") + error.what());
				}
			};

		protected:
			std::string m_Host;
			int m_Port;
			boost::asio::io_context& m_Context;
			std::string m_Path;
			std::vector<std::pair<std::string, std::string>> m_Params;
	};
} // namespace SteamLikeClient::HttpLibrary
