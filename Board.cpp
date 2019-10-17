#include "Board.h"
#include <iostream>
//Create grid
Board::Board(int size) { /////Create the game
	this->size = size;
	std::cout << " The size of the game is " << size << std::endl;
	totalLines = 2 * (size * size - 1); ////Calculate the total valid lines
	CircleShape aCircle; ///Create a visual Dot
	vertex.setPrimitiveType(Lines); ///Set primitive type for vertex
	vertex.resize(totalLines);	///Set its size
	//Print those dots----------------------------------------------
	for (int i = 0; i < size * size; i++) {
		circle.push_back(aCircle);
		circle[i].setRadius(10);
		circle[i].setPosition((40.f + (i % size) * screen_x / size), (40.f + (i / size) * screen_y / size));
		circle[i].setFillColor(Color::Red);
		circle[i].setOrigin(5, 5);
	}
	LineSelect(); /////Check if the line is good
}

/////Select the line-------------------------------------------------
void Board::LineSelect() 
{
	for (int i = 0; i < totalLines; i++) {
		Choice aChoice;                  ///To save this single choice into vector::choice
		PropOfAnB aProp;					////to save a prop of a and b into vector::selectedLines to use for Board::isTaken
		std::cout << " \n Select the dot that you want to connect: ";
		std::cin >> a >> b;
		while ((notValid(a, b, size)) || (isTaken(a, b, selectedLines))) { ////Validation
			std::cout << " Wrong input " << std::endl;
			std::cin.clear();
			std::cin >> a >> b;
		}
		aChoice.a = a;												////Input the valid
		aChoice.b = b;												//// choice into 
		choice.push_back(aChoice);									////the vector::choice
		aProp.product = a * b;						////Input product into 
		aProp.sum = a + b;							////vector::selectedLines to 
		selectedLines.push_back(aProp);				////use for Board::isTaken
		std::cout << " Data is in " << std::endl;               ///Confirm that data is in
		std::cout << " Here is i " << i << std::endl;			///Checking value of i
		printLine();										///Print to see what line is taken
		drawLines(i);
	}
}

///Print those Line ON CONSOLE--------------------------------------------
void Board::printLine()				
{
	for (auto i : choice) {
		std::cout << std::fixed << std::showpoint;
		std::cout << i.a << " ---------- " << i.b << std::endl;
	}
}

///Validation------------------------------------------
bool Board::notValid(int a, int b, int size) {  
	if ((abs(b - a) == size || (abs(b - a) == 1 && std::max(a, b) % size != 0)) && (a < size * size && b < size * size))	return false;
	std::cout << " Not Valid " << std::endl;
	return true;
}

///See if it's taken or not----------------------------------------
bool Board::isTaken(int a, int b, std::vector<PropOfAnB>Sum_Product) { 
	bool SumValid = false, ProductValid = false;
	for (auto i : Sum_Product) {
		if ((a * b) == i.product && (a + b) == i.sum) return true;
	}
	return false;
}

VertexArray Board::drawLines(int i)
{
	VertexArray vertex(Lines, 2 * (size*size - 1));
	std::cout << " Line is drawed ";
	//std::cout << circle[choice[i].a].getPosition().x << std::endl;
	//std::cout << circle[choice[i].b].getPosition().y << std::endl;
	vertex[i].position = circle[choice[i].a].getPosition();
	vertex[i+1].position = circle[choice[i].b].getPosition(); //////////Problem here
}
