#include "ColourMenu.h"
ColourMenu::ColourMenu(ToolMenu* _toolMenu)
{
	M_ColourWheel = sf::CircleShape(175);
	M_ColourWheelTexture = new sf::Texture();
	M_ColourWheelTexture->loadFromFile("Resources/ColourWheel.png");
	M_ColourWheel.setTexture(M_ColourWheelTexture);
	M_ColourWheelImage = M_ColourWheelTexture->copyToImage();

	M_ToolMenu = _toolMenu;
}

ColourMenu::~ColourMenu()
{
}

void ColourMenu::SetColour(sf::Color t_colour)
{
	M_ToolMenu->GetCurrentTool()->SetColor(t_colour); //fix spell
}

void ColourMenu::Update(sf::RenderWindow& _window, sf::Event _event)
{
	//t_appWindow.clear(sf::Color::White);
	if (_event.type == sf::Event::MouseButtonPressed && _event.mouseButton.button == sf::Mouse::Left && _window.hasFocus())
	{
		sf::Vector2f MousePos = sf::Vector2f(sf::Mouse::getPosition(_window));
		sf::Vector2f MouseWorldPos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
		SetColour(M_ColourWheelImage.getPixel(MousePos.x, MousePos.y));
	}

}

void ColourMenu::Render(sf::RenderWindow& _window)
{
	_window.draw(M_ColourWheel);
}

//changes - add colours to drop down from tool ba with set sfml colours. from there, open the wheel