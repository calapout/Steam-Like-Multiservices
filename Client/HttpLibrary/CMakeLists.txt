cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 23)

# BOOST PROVIDES CMAKE TARGETS, SO WE WILL USE THOSE TO BIND
find_package(Boost COMPONENTS beast json REQUIRED)

add_library(HttpLibrary SHARED
        include/HttpLibrary.hpp
        include/HttpGetRequest.hpp
)

target_precompile_headers(HttpLibrary PRIVATE include/pch.hpp)

target_link_libraries(HttpLibrary PRIVATE
        Boost::beast
        Boost::json
)