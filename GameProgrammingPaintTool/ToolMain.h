#pragma once
#include <SFML/Graphics.hpp>

//Using abstraction to create all tools. 

class ToolMain
{
public:

	virtual ~ToolMain();

	//Gets user input information to draw shapes via each tool
	virtual void MousePressed(sf::Vector2f _mousePos) = 0;
	virtual void MouseReleased(sf::Vector2f _mousePos) = 0;

	//Set fill colour of current tool
	void SetFillColour(const sf::Color& _colour)
	{
		M_FillColour = _colour;
	}

protected:
	sf::Color M_FillColour;
};

