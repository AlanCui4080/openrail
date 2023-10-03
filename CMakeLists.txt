cmake_minimum_required(VERSION 3.15)

project(openrail LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

include_directories(GLOB ${PROJECT_SOURCE_DIR}/include)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

file(GLOB PROJ_SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(openrail ${PROJ_SRC})

include(thirdparty)
