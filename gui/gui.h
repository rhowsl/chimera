#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace chimera
{
	class gui
	{
		private:
			// graphics
			sf::RenderWindow* gui_window;
			sf::Font* font;
			sf::Text* debug_text;
			sf::Texture* background_image_tex;
			sf::Sprite* background_image_spr;
			sf::Clock* fps_clock;
			// counters
			unsigned int frames;
			unsigned int last_fps;

		public:
			gui();
			~gui();
			void start();
			void quit();

		private:
			void bg_adjust();
			void cool_grid();
	};
}
