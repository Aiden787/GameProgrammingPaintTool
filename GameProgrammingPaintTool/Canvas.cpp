#include "Canvas.h"
#include "BrushTool.h"

Canvas::Canvas(sf::RenderWindow* _window)
{
	M_CanvasWindow = _window;
}

Canvas::~Canvas()
{
}


//Draw all items in vector to canvas texture and canvas window. 
void Canvas::Render(sf::RenderWindow& _window)
{

	//draw Brush path
	_window.draw(BrushTool::Brush); 

	for (const auto shape : M_ItemsToDraw)
	{
		M_CanvasTexture.draw(*shape);
		_window.draw(*shape);
	}
}
void Canvas::Clear()
{
	//Clears Canvas texture to white
	M_CanvasTexture.clear(sf::Color::White);

}

void Canvas::Save()
{

}

void Canvas::Load()
{

}