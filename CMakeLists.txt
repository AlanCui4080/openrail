cmake_minimum_required(VERSION 3.16)

project(openrail LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

file(GLOB PROJ_SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB PROJ_INC ${PROJECT_SOURCE_DIR}/include/*.hpp)
file(GLOB PROJUI_SRC ${PROJECT_SOURCE_DIR}/src/*.ui)

find_package(Qt6 COMPONENTS Widgets OpenGL REQUIRED)
qt_standard_project_setup()
qt_add_executable(openrail ${PROJ_SRC} ${PROJ_INC} ${PROJUI_SRC})
target_link_libraries(openrail PUBLIC Qt6::Widgets Qt6::OpenGL)
target_include_directories(openrail PUBLIC ${PROJECT_SOURCE_DIR}/include)

include(thirdparty)
