#pragma once
#include "ToolMain.h"

class BrushTool final : public ToolMain
{
public:
	//Functions
	void MousePressed(sf::Vector2f _mousePos) override;
	void MouseReleased(sf::Vector2f _mousePos) override;
	void SetShape(int _shapeNum);
	void SetSize(int _sizeNum);

	//Creating a path for drawing smoother
	static sf::VertexArray Brush;

private:
	//Member variables - default size/shape
	int M_ShapeNum = 30; //Circle
	int M_SizeNum = 5;

	
	
	
};
