#include "ProgramLoop.h"
//All set up and basic loop stuff here

Program::Program()
{
	// Create Canvas window and canvas
	sf::ContextSettings windowSettings;
	windowSettings.antialiasingLevel = 16;
	M_CanvasWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Paint Tool", sf::Style::Default, windowSettings); // Create Canvas Window
	M_Canvas = new Canvas(M_CanvasWindow); // Create Canvas and pass in the canvas window to be stored and used later

	//Create Colour Picker window
	M_ColourMenuWindow = new sf::RenderWindow(sf::VideoMode(350, 350), "Colour Picker Window", sf::Style::Default);

	// Create Toolbar window and toolbar
	M_ToolMenuWindow = new sf::RenderWindow(sf::VideoMode(908, 64), "Toolbar", sf::Style::Titlebar);
	M_ToolMenu = new ToolMenu(M_ToolMenuWindow, M_Canvas, M_ColourMenuWindow);// Create toolbar class

}

Program::~Program()
{
}

void Program::ProgramLoop()
{
	while (M_CanvasWindow->isOpen())
	{
		// Deal with user input
		sf::Event event{};

		//Deal with user input in the Toolbar Window 
		while (M_ToolMenuWindow->pollEvent(event))
		{
			const auto mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*M_ToolMenuWindow));

			M_ToolMenu->UserInput(event, mousePosition);
		}

		//Colour Picker Input 
		while (M_ColourMenuWindow->pollEvent(event))
		{
			M_ToolMenu->GetColourPicker()->Update(*M_ColourMenuWindow, event);
		}

		// Canvas Window Input
		while (M_CanvasWindow->pollEvent(event))
		{
			// Setup Mouse Position
			const auto mousePosition = sf::Mouse::getPosition(*M_CanvasWindow);
			const auto mouseWorldPosition = M_CanvasWindow->mapPixelToCoords(mousePosition);


			if (event.type == sf::Event::Closed)
			{
				M_CanvasWindow->close();
			}

			if (event.type == sf::Event::Resized)
			{
				// Nothing to do here as scaling is handled by setting mouse to a world position
			}

			// Hold event gets current tool and calls input pressed
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				M_ToolMenu->GetCurrentTool()->InputPressed(mouseWorldPosition);
			}

			// Single Click Event (for polygon points and stamps)
			////if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			//{
				//M_Toolbar->GetCurrentTool()->InputPressed(mouseWorldPosition);
			//}

			//Event triggered when user releases mouse
			if (event.type == sf::Event::MouseButtonReleased)
			{
				M_ToolMenu->GetCurrentTool()->InputReleased(mouseWorldPosition);
			}

		}

		// Clearing and Updating the windows/canvas
		M_CanvasWindow->clear(sf::Color::White);
		M_ToolMenuWindow->clear(sf::Color::White);
		M_CanvasWindow->clear(sf::Color::White);
		M_Canvas->Clear();

		// Drawing to window and canvas
		M_ToolMenu->Render(*M_ToolMenuWindow);
		M_Canvas->Render(*M_CanvasWindow);
		M_ToolMenu->GetColourPicker()->Render(*M_ColourMenuWindow);

		//m_canvas->render(*m_canvasWindow);
		M_ToolMenuWindow->display();
		M_CanvasWindow->display();
		M_ColourMenuWindow->display();
	}
}
