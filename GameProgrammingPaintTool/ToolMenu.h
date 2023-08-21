#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "Canvas.h"
#include "ToolMain.h"
#include "ColourMenu.h"

class ColourMenu;

class ToolMenu
{

public:
	explicit ToolMenu(sf::RenderWindow* _window, Canvas* _canvas, sf::RenderWindow* _colourMenu);

	void Render(sf::RenderWindow& _window);
	void UserInput(const sf::Event& _event, sf::Vector2f& _mousePos);
	void SetCurrentTool(ToolMain* _tool);
	ToolMain* GetCurrentTool();

	ColourMenu* GetColourMenu();

	//Member Variables
	int M_UserBrushSize = 5;
	int M_UserBrushShape = 30; //circle

private:
	//Window pointers
	sf::RenderWindow* M_PaintToolWindow;
	sf::RenderWindow* M_ColourMenuWindow{};
	Canvas* M_Canvas{};
	ColourMenu* M_ColourMenu{};

	std::array<sf::RectangleShape, 13> M_ToolButtons; //Array of buttons for the tools
	std::array<sf::Texture*, 13> M_ButtonTextures{}; //Array of textures for the tool buttons
	std::array<std::string, 13> M_TexturePaths //Array of paths to button textures
	{
		"Resources/paint_brush_icon.png",		// Brush Tool Icon Path
		"Resources/line_icon.png",				// Line Tool Icon Path
		"Resources/rectangle_icon.png",			// Rectangle Tool Icon Path
		"Resources/ellipse_circle_icon.png",	// Ellipse Tool Icon Path
		"Resources/polygon_icon.png",			// Polygon Tool Icon Path
		"Resorces/stamp_icon.png",				// Stamp Tool Icon Path
		"Resources/ColourWheel_Icon.png",		// Colour wheel Icon Path - change to pallete 
		"Resources/save_icon.png",				// Save File Icon Path
		"Resources/open_icon.png",				// Open File Icon Path
		"Resources/brush_size_add.png",			// Brush Size increase Icon Path
		"Resources/brush_size_minus.png",		// Brush Size decrease Icon Path
		"Resources/brush_shape_add.png",		// Brush Shape increase Icon Path
		"Resources/brush_shape_minus.png",		// Brush Shape decrease Icon Path
	};


	ToolMain* M_CurrentTool{}; //Pointer to current tool
	std::array<ToolMain*, 6> M_Tools{}; //Array of tools
};






/*#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

enum class CurrentTool
{
	BrushTool,
	// Set Initial Point for Line Tool
	BoxToolStartPoint,
	BoxToolEndPoint,
	EllipseToolStartPoint,
	EllipseToolEndPoint,
	LineToolStartPoint,
	// Set End Point for Line Tool
	LineToolEndPoint,
	PolygonToolStartPoint,
	PolygonToolNextPoint
};
class ToolMenu
{
	ToolMenu();
	~ToolMenu();

public:
	std::vector<sf::Shape*> M_MenuTools; //Vector of menu tool buttons
	void CreateToolBar(); 
	int ChangeTool();
	CurrentTool m_SelectedTool;

};
*/
