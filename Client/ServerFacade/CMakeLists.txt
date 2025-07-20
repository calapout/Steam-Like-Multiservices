cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 23)

# BOOST PROVIDES CMAKE TARGETS, SO WE WILL USE THOSE TO BIND
find_package(Boost COMPONENTS beast json REQUIRED)

add_library(ServerFacade SHARED
        src/ServerFacade.cpp
        include/ServerFacade.hpp
        include/GameDTO.hpp
)

message(STATUS ${PROJECT_ROOT}/HttpLibrary/include)
# COMPILER CONFIG
target_include_directories(ServerFacade PRIVATE
        include
        ${PROJECT_ROOT}/HttpLibrary/include
)

# LINKER CONFIG
target_link_libraries(ServerFacade PRIVATE
        HttpLibrary
        Boost::beast
        Boost::json
)