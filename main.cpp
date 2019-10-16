#include <sfml/Graphics.hpp>
#include <sfml/Window.hpp>
#include <sfml/Main.hpp>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace sf;
const int screen_x = 1000;
const int screen_y = 1000;
class Board {
private:
	std::vector<CircleShape>circle;
public:
	Board(int size) { //Create grid
		CircleShape aCircle;
		//Print those dots----------------------------------------------
		for (int i = 0; i < size * size; i++) {
			circle.push_back(aCircle);
			circle[i].setRadius(10);
			circle[i].setPosition((40.f + (i % size) * screen_x / size), (40.f + (i / size) * screen_y / size));
			circle[i].setFillColor(Color::Red);
			circle[i].setOrigin(5, 5);	
			
		}
	}
	friend class ConnectLine;
	std::vector<CircleShape> getCircle() { //return vector of dots
		return circle;
	}
};
//class ConnectLine {
//private:
//	
//public:
//	static std::vector<Vertex>vertex;
//	ConnectLine(Vector2i pos) {
//		Vertex aVertex;
//		aVertex.position = static_cast<Vector2f>(pos);
//		vertex.push_back(aVertex);
//	}
//	static std::vector<Vertex> get2Vertex() {
//		return vertex;
//	}
//};
int main() {
	
	RenderWindow window(VideoMode(screen_x,screen_y), " Dots and Boxes ", Style::Default);
	window.setFramerateLimit(144);
	int edge{};
	
	std::cout << " Enter the number of dots you want on an edge: ";
	//std::cin >> edge;
	edge = 5;
	VertexArray vertex(Lines, 10000);
	int INDEX{};
	while (window.isOpen()) {
		Event event;
		/////////////////////////Get mouse position on window---------------------
		Vector2i pos = Mouse::getPosition(window);
		/////////////////Print those dots----------------------------------------------
		Board board(edge);
		/////////////////Print those line--------------------------------------------
		while (window.pollEvent(event)) {
			
			if (event.type == Event::Closed)
				window.close();
			/////////////////////Select the dot---------------------------------------------------
			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					for (auto t : board.getCircle()) {
						if (t.getGlobalBounds().contains(pos.x, pos.y)) { //Need a function to create a vertex when this happens
							std::cout << " YO ";
							vertex[INDEX].position = t.getPosition(); //Create a Vertex
							vertex[INDEX].color = Color::Black;
							INDEX++;
						}
					}
				}
			}
				if (event.type == Event::MouseButtonReleased) {
					if (event.key.code == Mouse::Left) {
						for (auto t : board.getCircle()) {
							if (t.getGlobalBounds().contains(pos.x, pos.y)) {
								std::cout << " Yay " << std::endl;
								vertex[INDEX].position = t.getPosition();  //Create a Vertex
								vertex[INDEX].color = Color::Black;
								INDEX++;
							}
						}
					}
				}
		}
		window.clear(Color::White);
		for ( auto i : board.getCircle()) {
			window.draw(i);			
		}
		window.draw(vertex);
		window.display();
	}
	return 0;
}
