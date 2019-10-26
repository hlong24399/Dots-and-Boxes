#pragma once
#include <SFML/Graphics.hpp>
#include <sfml/Window.hpp>
#include <iostream>
#include <utility>

using namespace sf;


class Edge
{
	//friend class Board;
public:
	std::vector<std::pair<int, int>> Edges;   ///First is column, Second is row
	int size{}, totalLines{};
public:
	void inputEdges(int a, int b);
	void setSize(int size, int totalLines);
	bool in(int a, int b);
};
