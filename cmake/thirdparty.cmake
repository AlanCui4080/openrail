find_package(Boost 1.4.0 REQUIRED)
target_link_libraries(openrail PRIVATE ${Boost_LIBRARIES})
target_include_directories(openrail PUBLIC ${Boost_INCLUDE_DIRS})

find_package(spdlog REQUIRED)
target_link_libraries(openrail PRIVATE spdlog::spdlog)
target_include_directories(openrail PUBLIC ${spdlog_INCLUDE_DIRS})
