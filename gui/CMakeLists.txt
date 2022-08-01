find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_library(chimera_gui
	gui.cpp
	gui.h
	)

target_link_libraries(chimera_gui PRIVATE sfml-graphics sfml-system sfml-window)
