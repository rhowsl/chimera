#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace chimera
{
	class pattern_editor : public Drawable
	{
		private:
			bool follow;
			unsigned int current_row;

		public:
			pattern_editor();
			~pattern_editor();

			void set_follow(const bool follow);
	};
}
