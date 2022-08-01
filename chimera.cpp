#include <iostream>
#include <string>
#include <vector>

#include "tracker/tracker.h"
#include "tracker/module.h"

#include "gui/gui.h"

// entry point
int main(int argc, char** argv)
{
	// args as in a c++ vector, please.
	const std::vector<std::string> cpp_args(argv, argv + argc);
	const std::string initial_project_filename = cpp_args.size() > 1 ?
		cpp_args[1] : "";

	if (initial_project_filename.empty())
		std::cout << "no initial project" << std::endl;

	// begin program
	chimera::gui* main_gui = new chimera::gui();
	main_gui->start();
	
	return 0;
}
