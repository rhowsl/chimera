find_package(nlohmann_json 3.2.0 REQUIRED)

add_library(chimera_tracker
	tracker.cpp
	tracker.h
	module.cpp
	module.h
	)

target_link_libraries(chimera_tracker PRIVATE nlohmann_json::nlohmann_json)
