#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Canvas
{
public:

	//Constructor takes in Render Window
	Canvas(sf::RenderWindow* _window);
	~Canvas();
	
	//Functions
	//Render function -
	void Render(sf::RenderWindow& _window);
	//Clear function - clear canvas when - 
	void Clear();
	//Save function - Save current canvas texture to chosen location on computer
	void Save();
	//load function - load an image to the canvas
	void Load();

	//Public Member variables
	static std::vector<sf::Shape*> M_ItemsToDraw; //Vector of items to be drawn to the screen. Static for use in multiple tools.
	

private:
	//Private member variables 
	//Create window pointer
	sf::RenderWindow* M_CanvasWindow; 
	//Background texture, allows saving functionality 
	sf::RenderTexture M_CanvasTexture; 

};

