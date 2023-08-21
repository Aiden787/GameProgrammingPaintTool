#pragma once
#include <SFML/Graphics.hpp>
#include "ToolMenu.h"
class ToolMenu;
class ColourMenu
{

public:
	explicit ColourMenu(ToolMenu* t_toolbar);
	~ColourMenu();

	void SetColour(sf::Color t_colour);
	void Update(sf::RenderWindow& t_appWindow, sf::Event t_event);
	void Render(sf::RenderWindow& t_appWindow);
private:
	sf::CircleShape M_ColourWheel;
	sf::Texture* M_ColourWheelTexture{};
	sf::Image M_ColourWheelImage;

	ToolMenu* M_ToolMenu{};
};

