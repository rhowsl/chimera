#include "gui.h"

using namespace chimera;

chimera::gui::gui()
{
	// Object initialization
	this->font = new sf::Font();
	this->fps_clock = new sf::Clock();
	this->gui_window = new sf::RenderWindow(sf::VideoMode(1024, 768), "chimera");
	this->background_image_tex = new sf::Texture();
	this->background_image_spr = new sf::Sprite();

	// Asset loading
	this->font->loadFromFile("/usr/share/fonts/TTF/FiraCode-Light.ttf");
	this->background_image_tex->loadFromFile("/home/p/Arte/1507413466.rukis_wedding_kiss.jpg");
	this->background_image_spr->setTexture(*this->background_image_tex);

	// Post asset loading
	this->debug_text = new sf::Text("Test", *this->font);
	this->debug_text->setCharacterSize(30);
	this->debug_text->setPosition(sf::Vector2f(20, 20));
	this->debug_text->setFillColor(sf::Color::White);
}

chimera::gui::~gui()
{
	// Delete everything
	delete this->font;
	delete this->gui_window;
	delete this->debug_text;
	delete this->background_image_spr;
	delete this->background_image_tex;
	delete this->fps_clock;
}

void chimera::gui::start()
{
	auto window = this->gui_window;

	while (window->isOpen())
	{
		sf::Event last_event;
		while (window->pollEvent(last_event))
		{
			switch (last_event.type)
			{
				case sf::Event::Closed:
					this->quit();
					break;
				case sf::Event::Resized:
					window->setView(sf::View(sf::FloatRect(0, 0, last_event.size.width, last_event.size.height)));
					break;
			}
		}

		// clear
		window->clear();

		// pre draw
		this->bg_adjust();
		this->debug_text->setString(std::to_string(this->last_fps) + " fps");

		// draw
		window->draw(*this->background_image_spr);
		window->draw(*this->debug_text);

		// update
		window->display();

		// fps calc
		if (this->fps_clock->getElapsedTime().asSeconds() > 1)
		{
			this->last_fps = frames;
			this->frames = 0;
			this->fps_clock->restart();
		}

		this->frames++;
	}
}

void chimera::gui::quit()
{
	this->gui_window->close();
}

void chimera::gui::bg_adjust()
{
	// background image sprite
	auto background_image_spr = this->background_image_spr;
	// window
	auto window = this->gui_window;
	// view size
	auto view_size = window->getView().getSize();
	// sprite rect
	auto sprite_rect = background_image_spr->getTextureRect();
	// calc scale transform (x + y) / 2
	std::pair<float, float> scale = std::make_pair(
			(float)sprite_rect.width / (float)view_size.x,
			(float)sprite_rect.height / (float)view_size.y
			);
	background_image_spr->setScale(1 / scale.first, 1 / scale.second);
}

void chimera::gui::cool_grid()
{
	auto window = &this->gui_window;
}
