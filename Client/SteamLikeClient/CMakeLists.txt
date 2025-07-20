cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 23)

# GTKMM PROVIDE ONLY A PkgConfig MODULE, SO WE GOTTA USE THAT TO LINK
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-4.0)

# BOOST PROVIDES CMAKE TARGETS, SO WE WILL USE THOSE TO BIND
find_package(Boost COMPONENTS beast json REQUIRED)

add_executable(SteamLikeClient main.cpp
        Widgets/SteamClientWindow.cpp
        Widgets/SteamClientWindow.h
        Widgets/GameGrid.cpp
        Widgets/GameGrid.h
        Widgets/GameFrame.cpp
        Widgets/GameFrame.h)

target_precompile_headers(SteamLikeClient PRIVATE pch.hpp)

# COMPILER CONFIG
#target_include_directories(SteamLikeClient PRIVATE)
target_include_directories(SteamLikeClient PRIVATE
        # INCLUDE INTERNAL LIBS
        ${PROJECT_ROOT}/HttpLibrary/include
        ${PROJECT_ROOT}/ServerFacade/include
        # INCLUDE EXTERNAL LIBS
        ${GTKMM_INCLUDE_DIRS}
)

# LINKER CONFIG
target_link_directories(SteamLikeClient PRIVATE
        ${GTKMM_LIBRARY_DIRS}
)
target_link_libraries(SteamLikeClient PRIVATE
        # LINK TO INTERNAL LIBS
        HttpLibrary
        ServerFacade

        # LINK TO EXTERNAL LIBS
        ${GTKMM_LIBRARIES}
        Boost::beast
        Boost::json
)