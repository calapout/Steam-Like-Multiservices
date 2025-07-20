//
// Created by calapout on 7/20/25.
//

#pragma once

#include <string>
#include <vector>
#include <expected>
#include <boost/beast.hpp>
#include <boost/json.hpp>


namespace http = boost::beast::http;
namespace ip = boost::asio::ip;

typedef std::vector<std::pair<std::string, std::string>> PARAM_VECTOR;