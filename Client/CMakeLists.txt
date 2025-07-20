cmake_minimum_required(VERSION 3.30)
project(SteamLikeClient)

set(CMAKE_CXX_STANDARD 23)

SET(PROJECT_ROOT ${PROJECT_SOURCE_DIR})

add_subdirectory(HttpLibrary)
add_subdirectory(ServerFacade)
add_subdirectory(SteamLikeClient)