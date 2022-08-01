cmake_minimum_required(VERSION 3.10)
project(chimera)

# tracker stuff
add_subdirectory(tracker)
add_subdirectory(gui)

# final part
add_executable(chimera chimera.cpp)
target_link_libraries(chimera PUBLIC chimera_tracker)
target_link_libraries(chimera PUBLIC chimera_gui)
