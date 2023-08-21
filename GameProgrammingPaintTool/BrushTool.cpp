#include "BrushTool.h"
#include "Canvas.h"

void BrushTool::MousePressed(sf::Vector2f _mousePos)
{
	//Drawing with paths for smoother drawing experience
	Brush.setPrimitiveType(sf::LineStrip);

	//Set fill colour for brush
	Brush.append.setFillColor(M_FillColour);
	//Set draw position to be the current mouse position
	Brush->setPosition(_mousePos);
	//Set shape (Based on number of verticies)
	Brush->setPointCount(M_ShapeNum);
	//Set size
	Brush->setOrigin(M_SizeNum, M_SizeNum);
	Brush->setRadius(M_SizeNum);


	
}

void BrushTool::MouseReleased(sf::Vector2f _mousePos)
{
}

//Set brush shape (Based on user selection)
void BrushTool::SetShape(int _shapeNum)
{
	M_ShapeNum = _shapeNum; //based on number of vertices in selected shape 
}

//Set brush size (based on user selection) 
void BrushTool::SetSize(int _sizeNum)
{
	M_SizeNum = _sizeNum;
}


