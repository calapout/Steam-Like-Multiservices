//
// Created by calapout on 7/14/25.
//

#pragma once

namespace SteamLikeClient::HttpLibrary
{
	template<class DataFormat>
	struct HttpResponse {
		int StatusCode;
		std::string ErrorMessage;
		DataFormat Data;

		// SUCCESS
		HttpResponse(const int statusCode, const DataFormat& data)
		{
			StatusCode = statusCode;
			ErrorMessage = "";
			Data = data;
		}

		// MOVE SUCCESS
		HttpResponse(const int statusCode, const DataFormat&& data)
		{
			StatusCode = statusCode;
			ErrorMessage = "";
			Data = data;
		}

		// ERROR
		HttpResponse(const int statusCode, const std::string& errorMessage)
		{
			StatusCode = statusCode;
			ErrorMessage = errorMessage;
		}

		// MOVE ERROR
		HttpResponse(const int statusCode, const std::string&& errorMessage)
		{
			StatusCode = statusCode;
			ErrorMessage = errorMessage;
		}
	};
}