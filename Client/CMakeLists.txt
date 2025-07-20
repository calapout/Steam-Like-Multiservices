cmake_minimum_required(VERSION 3.30)
project(SteamLikeClient)

set(CMAKE_CXX_STANDARD 23)

SET(PROJECT_ROOT ${PROJECT_SOURCE_DIR})

# Derive normalized names
string(TOLOWER "${CMAKE_SYSTEM_NAME}" PLATFORM_DIR)
string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" ARCH_DIR)

# Base output dir (relative to build directory, or make absolute if you want)
set(OUTPUT_BASE "${CMAKE_BINARY_DIR}/bin/${PLATFORM_DIR}/${ARCH_DIR}")

# For single-config generators (Makefiles, Ninja):
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_BASE}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_BASE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_BASE}")

add_subdirectory(HttpLibrary)
add_subdirectory(ServerFacade)
add_subdirectory(SteamLikeClient)