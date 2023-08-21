#include "ToolMenu.h"
#include "BrushTool.h"
#include "BoxTool.h"
//#include "EllipseTool.h"
#include "LineTool.h"
#include "PolygonTool.h"
#include "StampTool.h"
//all tool stuff here 

ToolMenu::~ToolMenu()
{


}


ToolMenu::ToolMenu(sf::RenderWindow* _window, Canvas* _canvas, sf::RenderWindow* _colourMenu)
{
	M_PaintToolWindow = _window;
	M_Canvas = _canvas;
	M_ColourMenuWindow = _colourMenu;

	// Load and create textures from the array of textures paths and apply textures to each
	// button shape

	for (int i = 0; i < M_ToolButtons.size(); i++)
	{
		// Load texture
		M_ButtonTextures.at(i) = new sf::Texture(); // Create new texture and store it in m_buttonTextures;
		M_ButtonTextures.at(i)->loadFromFile(M_TexturePaths.at(i)); // Load texture from path onto the new texture

		M_ToolButtons.at(i).setSize(sf::Vector2f(64.f, 64.f)); // Set size of button
		M_ToolButtons.at(i).setTexture(M_ButtonTextures.at(i)); // Set texture of button

		// Set Position
		const float x = 5.f + i * 69.f;
		M_ToolButtons.at(i).move(sf::Vector2f(x, 0.f));
	}

	// Instantiate all tools
	M_Tools.at(0) = new BrushTool();
	M_Tools.at(1) = new LineTool();
	M_Tools.at(2) = new BoxTool();
	M_Tools.at(3) = new EllipseTool();
	M_Tools.at(4) = new PolygonTool();
	M_Tools.at(5) = new StampTool();

	//Set deafult tool to brush
	M_CurrentTool = M_Tools.at(0);

	M_ColourMenu = new ColourMenu(this);
}

//Render all tool buttons to window
void ToolMenu::Render(sf::RenderWindow& _window)
{
	for (const auto& button : M_ToolButtons)
	{
		_window.draw(button);
	};
}

void ToolMenu::UserInput(const sf::Event& _event, sf::Vector2f& _mousePos) //change funct name
{
	if (_event.type == sf::Event::MouseButtonPressed && _event.mouseButton.button == sf::Mouse::Left)
	{
		for (int i = 0; i < M_ToolButtons.size(); i++)
		{
			if (M_ToolButtons.at(i).getGlobalBounds().contains(_mousePos.x, _mousePos.y))
			{
				// Switching current Tool
				if (i >= 0 && i <= 5)
				{
					SetCurrentTool(M_Tools.at(i));
					std::cout << i << std::endl;
				}

				// Colour Wheel Window Toggle
				if (i == 6)
				{

					// Toggle Colour Wheel Window open/closed
				}
				//Save file
				if (i == 7)
				{
					M_Canvas->Save();
				}
				//Load file
				if (i == 8)
				{
					M_Canvas->Load();
				}
				//Increase brush size 
				if (i == 9)
				{
					
					if (M_BrushEditSize < 50)
					{
						M_BrushEditSize += 5;
						std::cout << "Brush size increased by 5 points" << std::endl;

						// sets a local variable if Tool -> BrushTool cast is successful
						if (const auto brushTool = dynamic_cast<BrushTool*>(M_CurrentTool))
						{
							// access the brushtool via the sucessful dynamic cast and pass in the new brush size 
							brushTool->SetSize(M_BrushEditSize);
						}
					}
					else
					{
						std::cout << "Brush max size, cannot be increased" << std::endl;
					}

				}

				//Decrease brush size
				if (i == 10)
				{
					if (M_BrushEditSize > 5)
					{
						M_BrushEditSize -= 5;
						std::cout << "Brush size decreased by 5" << std::endl;

						// sets a local variable if Tool -> BrushTool cast is successful
						if (const auto brushTool = dynamic_cast<BrushTool*>(M_CurrentTool))
						{
							// access the brushtool via the sucessful dynamic cast and pass in the new brush size 
							brushTool->SetSize(M_BrushEditSize);
						}
					}

					else
					{
						std::cout << "Brush min size, cannot be decreased" << std::endl;
					}
				}
				//change brush shape by increasing verticies - get rid of this and have a dropdown with shapes instead. change around ALL icons
				if (i == 11)
				{
					if (M_BrushEditVertex < 30)
					{
						M_BrushEditVertex += 1;
						std::cout << "Brush shape increased by one" << std::endl;

						// sets a local variable if Tool -> BrushTool cast is successful
						if (const auto brushTool = dynamic_cast<BrushTool*>(M_CurrentTool))
						{
							// access the brushtool via the sucessful dynamic cast and pass in the new brush size 
							brushTool->SetVertexCount(M_BrushEditVertex);
						}
					}

					else
					{
						std::cout << "Brush cannot have more than 30 vertices, cannot be increased" << std::endl;
					}

				}
				//change brush shape by decreasing vertices
				if (i == 12)
				{
					if (M_BrushEditVertex > 3)
					{
						//circle and 1-10
						M_BrushEditVertex -= 1;
						std::cout << "Brush shape decreased by one" << std::endl;

						// sets a local variable if Tool -> BrushTool cast is successful
						if (const auto brushTool = dynamic_cast<BrushTool*>(M_CurrentTool))
						{
							// access the brushtool via the sucessful dynamic cast and pass in the new brush size 
							brushTool->SetVertexCount(M_BrushEditVertex);
						}
					}

					else
					{
						std::cout << "Brush cannot have less than 3 vertices, cannot be increased" << std::endl;
					}

				}

			}
		}
	}
}


void ToolMenu::SetCurrentTool(ToolMain* _tool)
{
}

ToolMain* ToolMenu::GetCurrentTool()
{
	return nullptr;
}

ColourMenu* ToolMenu::GetColourMenu()
{
	return nullptr;
}
