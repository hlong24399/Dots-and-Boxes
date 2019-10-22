#include "Board.h"
#include <iostream>
//Create grid
Board::Board(int size, RenderWindow &win) { /////Create the game
	this->size = size;
	std::cout << " The size of the game is " << size << std::endl;
	totalLines = 2*(size*size - size); ////Calculate the total valid lines
	CircleShape aCircle; ///Create a visual Dot
	vertex.setPrimitiveType(Lines); ///Set primitive type for vertex
	vertex.resize(2*totalLines);	///Set its size
	//Print those dots----------------------------------------------
	float breadth = static_cast<float>(0.8f * screen_size) / static_cast<float>(size) - 1.f;
	
	for (int i = 0; i < size * size; i++) {
		float circle_x = 0.1 * screen_size + float{ (i % size) * breadth }; ///Set the position for 
		float circle_y = 0.1 * screen_size + float{ (i / size) * breadth };	///	those circles
		circle.push_back(aCircle);
		circle[i].setRadius(8);
		circle[i].setPosition(circle_x, circle_y);
		circle[i].setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
		circle[i].setOrigin(4, 4);
	} 
	
	////Set up the board, draw dot first before input the first choice like what happened on Prof's code
	for ( auto i : circle)
	win.draw(i);
	win.display();
}

/////Select the line-------------------------------------------------
void Board::LineSelect()
{
	Choice aChoice;                  ///To save this single choice into vector::choice
	PropOfAnB aProp;					////to save a prop of a and b into vector::selectedLines to use for Board::isTaken
	std::cout << " \n Select the dot that you want to connect: ";
	std::cin >> a >> b;
	while ((notValid(a, b, size)) || (isTaken(a, b, selectedLines))) { ////Validation
		std::cout << " Wrong input " << std::endl;
		std::cin.clear();
		std::cin >> a >> b;
	}
	if (a < b) { aChoice.a = a; aChoice.b = b; }			////This is for sorting a and b
	else { aChoice.a = b; aChoice.b = a; }						////   to be odd and even to further use
	choice.push_back(aChoice);									////the vector::choice
	for (auto i : choice) std::cout << i.a << "-------- " << i.b << std::endl;
	aProp.product = a * b;						////Input product into 
	aProp.sum = a + b;							////vector::selectedLines to 
	selectedLines.push_back(aProp);				////use for Board::isTaken
	box.setEdges(a, b);
}

///Print those Line ON CONSOLE--------------------------------------------
//void Board::printLine()				
//{
//	for (auto i : choice) {
//		std::cout << std::fixed << std::showpoint;
//		std::cout << i.a << " ---------- " << i.b << std::endl;
//	}
//}

///Validation------------------------------------------
bool Board::notValid(int a, int b, int size)  const {
	if ((abs(b - a) == size || (abs(b - a) == 1 && std::max(a, b) % size != 0)) && (a < size * size && b < size * size))	return false;
	std::cout << " Not Valid " << std::endl;
	return true;
}

///See if it's taken or not----------------------------------------
bool Board::isTaken(int a, int b, std::vector<PropOfAnB>Sum_Product) {
	for (auto i : Sum_Product) {
		if ((a * b) == i.product && (a + b) == i.sum) {
			std::cout << " This line is taken already " << std::endl;
			return true;
		}
	}
	return false;
}

//Draw those stuff
void Board::drawLines(RenderWindow& win)
{
	vertex[2 * moveCount].position.x = circle[choice[moveCount].a].getPosition().x + 5;				///Draws Vertex
	vertex[2 * moveCount].position.y = circle[choice[moveCount].a].getPosition().y + 5;				///  by using
	vertex[2* moveCount + 1].position.x = circle[choice[moveCount].b].getPosition().x +5;			///  coord of circle
	vertex[2 * moveCount + 1].position.y = circle[choice[moveCount].b].getPosition().y + 5;			///  +5 because the radius is 10
	vertex[2 * moveCount].color = Color(rand() % 255, rand() % 255, rand() % 255);
	vertex[2 * moveCount + 1].color = Color(rand() % 255, rand() % 255, rand() % 255);
	for (auto i : circle)																			///Redraw the circle
		win.draw(i);
	//for (unsigned int u = 0; u < choice.size(); u ++ ) {
	//	std::cout << choice[u].a << "---------------" << choice[u].b << std::endl;
	//} ////This is to see what choice is made on CONSOLE
	win.draw(vertex);
	moveCount++;
}
