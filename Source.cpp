/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

 // Our global constants to remove magic numbers
int BrushRadius = 16;
int Trans = 255;
int x = 0;
int y = 0;
int z = 0;
//sf::Color BrushColor = sf::Color::Cyan;
sf::Color BrushColor = sf::Color(x, y, z, Trans);

// Main, our applicaiton entry function
int main()
{
	// Create the window for the game
	// All rendering happens here
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	// Create our "brush" (as a circle shape), with a radius of BrushRadius pixels
	sf::CircleShape shape;
	//shape.setRadius(BrushRadius);

	// Set the color of our "brush"
	shape.setFillColor(BrushColor);

	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		// Check for events from the window
		// E.g., is the window being closed?
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			// Space key creates a screenshot
			if (event.key.code == sf::Keyboard::Space) {
				sf::Texture texture;
				texture.create(window.getSize().x, window.getSize().y);
				texture.update(window);
				if (texture.copyToImage().saveToFile("Homework 1 Screenshot.png"))
				{
					std::cout << "Screenshot saved to Homework 1 Screenshot.png" << std::endl;
				}
			}

			// R key changes color to Red
			if (event.key.code == sf::Keyboard::R) {
				x = 255;
				y = 0;
				z = 0;
				sf::Color BrushColor = sf::Color(x, y, z, Trans);
				shape.setFillColor(BrushColor);
				shape.setRadius(BrushRadius);
			}

			// G key changes color to Green
			if (event.key.code == sf::Keyboard::G) {
				y = 255;
				x = 0;
				z = 0;
				sf::Color BrushColor = sf::Color(x, y, z, Trans);
				shape.setFillColor(BrushColor);
				shape.setRadius(BrushRadius);
			}

			// B key changes color to Blue
			if (event.key.code == sf::Keyboard::B) {
				z = 255;
				x = 0;
				y = 0;
				sf::Color BrushColor = sf::Color(x, y, z, Trans);
				shape.setFillColor(BrushColor);
				shape.setRadius(BrushRadius);
			}

			if (event.key.code == sf::Keyboard::Left) {
				if (Trans > 0) {
					Trans -= 5;	
					std::cout << Trans << std::endl;
				}
				sf::Color BrushColor = sf::Color(x, y, z, Trans);
				shape.setFillColor(BrushColor);
				shape.setRadius(BrushRadius);
			}

			if (event.key.code == sf::Keyboard::Right) {
				if (Trans < 255) {
					Trans += 5;
					std::cout << Trans << std::endl;
				}
				sf::Color BrushColor = sf::Color(x, y, z, Trans);
				shape.setFillColor(BrushColor);
				shape.setRadius(BrushRadius);
			}

			if (event.key.code == sf::Keyboard::Up) {
				BrushRadius += 4;
				shape.setRadius(BrushRadius);
			}

			if (event.key.code == sf::Keyboard::Down) {
				if(BrushRadius > 4) {
					BrushRadius -= 4;
				}
				shape.setRadius(BrushRadius);
			}
		}

		// This clears the window at the beginning of every frame
		// If we comment this out, it is a very simple way to create a paintbrush effect since the window is never cleared
		//window.clear();

		// Set the position of our "brush" to the mouse position
		// Don't forget to offset by the "brush" radius to center it on the mouse position
		shape.setPosition(sf::Mouse::getPosition(window).x - BrushRadius, sf::Mouse::getPosition(window).y - BrushRadius);

		// Draw our "brush" to the window buffer
		window.draw(shape);

		// Display the window buffer for this frame
		window.display();
	}

	// The game has exited normally so send a normal exit status integer back
	return 0;
}