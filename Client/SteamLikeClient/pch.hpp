//
// Created by calapout on 7/20/25.
//

#pragma once

#include <boost/beast.hpp>
#include <boost/json.hpp>
#include <expected>
#include <iostream>
#include <string>
#include <vector>

#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>

#include "ServerFacade.hpp"

namespace http = boost::beast::http;
namespace ip = boost::asio::ip;

typedef std::vector<std::pair<std::string, std::string>> PARAM_VECTOR;
