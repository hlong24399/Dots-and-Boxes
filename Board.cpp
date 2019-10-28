#include "Board.h"
#include <iostream>
#include "Box.h"
#include <utility>



Board::Board(int size, RenderWindow& win) { /////Create the game

	this->size = size;
	totalLines = 2 * (size * size - size);	////Calculate the total valid lines
	edge.setSize(size, totalLines);			////Pass size and totalLines to box class
	std::cout << " The size of the game is " << size << std::endl;
	CircleShape aCircle; ///Create a visual Dot
	vertex.setPrimitiveType(Lines); ///Set primitive type for vertex
	vertex.resize(2 * totalLines);	///Set its size
	float breadth = static_cast<float>(0.8f * screen_size) / static_cast<float>(size) - 1.f;

	//Print those dots----------------------------------------------
	for (int i = 0; i < size * size; i++) {
		float circle_x = 0.1 * screen_size + float{ (i % size) * breadth }; ///Set the position for 
		float circle_y = 0.1 * screen_size + float{ (i / size) * breadth };	///	those circles
		circle.push_back(aCircle);
		circle[i].setRadius(8);
		circle[i].setPosition(circle_x, circle_y);
		circle[i].setFillColor(Color(255, 0, 20));
		circle[i].setOrigin(4, 4);
	}
	////Set up the board, draw dot first before input the first choice like what happened on Prof's code
	win.clear(Color(192, 192, 192, 200));
	for (auto i : circle)
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
	else { aChoice.a = b; aChoice.b = a; }					//// so that a always smaller than b
	choice.push_back(aChoice);									////the Board::choice
	aProp.product = a * b;						////Input product into 
	aProp.sum = a + b;							////vector::selectedLines to 
	selectedLines.push_back(aProp);				////use for Board::isTaken
	edge.inputEdges(aChoice.a, aChoice.b);
	//box.printBox();		 ///Just to check whatever is in the box::edges
	for (int i = 0; i < size * (size - 1); i++) {
		if (edge.in(i, i + 1) && edge.in(i, i + size)				////This is to detect if there are enough edges to 
			&& edge.in(i + 1, i + 1 + size)						////	make a box .  "i" will be the index of the
			&& edge.in(i + size, i + 1 + size)) {				////	circle that contains the upperleft corner
			std::cout << " This is the i that works " << i << std::endl;
			setBoxes(i);
		}
	}
}


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
void Board::Draw(RenderWindow& win)
{
	vertex[2 * moveCount].position.x = circle[choice[moveCount].a].getPosition().x + 5;				///Draws Vertex
	vertex[2 * moveCount].position.y = circle[choice[moveCount].a].getPosition().y + 5;				///  by using
	vertex[2 * moveCount + 1].position.x = circle[choice[moveCount].b].getPosition().x + 5;			///  coord of circle
	vertex[2 * moveCount + 1].position.y = circle[choice[moveCount].b].getPosition().y + 5;			///  +5 because the radius is 10
	vertex[2 * moveCount].color = Color::Yellow;
	vertex[2 * moveCount + 1].color = Color::Yellow;
	for (auto i : circle) win.draw(i);																///Redraw the circle
	win.draw(vertex);
	moveCount++;
	//Draw those boxes------------------------------------------------------------------
	for (auto t : rects) win.draw(t);

}

//Set up the boxes
void Board::setBoxes(int leftcorner)
{
	float Box_breadth = (static_cast<float>(0.8f * screen_size) / static_cast<float>(size) - 1.f) - 4; //Box breadth is 4 pixel smaller than board breadth
	RectangleShape new_rect(Vector2f(Box_breadth, Box_breadth));
	new_rect.setFillColor(Color(0, 0, 0, 200));
	new_rect.setPosition(Vector2f(circle[leftcorner].getPosition()) + Vector2f(5, 5));
	rects.push_back(new_rect);
	//Must be something here to save score.
	setScore(leftcorner);
}

void Board::setScore(int box)
{
	bool isRepeated = false;
	for (auto i : checkRepeated) {
		if (box == i)  isRepeated = true;
		
	}
	if (!isRepeated) {
		checkRepeated.push_back(box);
		if (scoreCount % 2 == 0) {
			score1++;
			scoreCount++;
			std::cout << " Current FIRST score : " << score1 << std::endl;
		}
		else if (scoreCount % 2 == 1) {
			score2++;
			scoreCount++;
			std::cout << " Current SECOND score : " << score2 << std::endl;
		}
	}
}
