#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Canvas.h"
#include "ToolMenu.h"
class Program
{

public:
	
	
	//Constructor
		Program();

	//Deconstrcutor
		~Program();

	//Main loop function
	void ProgramLoop();

	//Variable that holds the location of the mouse pointer
	sf::Vector2i M_MousePos;

	private:
		//Window pointers
		sf::RenderWindow* M_CanvasWindow;
		sf::RenderWindow* M_ToolMenuWindow;
		sf::RenderWindow* M_ColourMenuWindow;
		sf::RenderWindow* M_ColourWheelWindow;

		//Canvas 
		Canvas* M_Canvas;
		ToolMenu* M_ToolMenu;

		
};

