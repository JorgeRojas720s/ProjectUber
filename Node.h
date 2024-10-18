#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


class Node {
private:
	int id;
	int posX;
	int posY;
	CircleShape shape;
	//Text text;

public:

	Node();

	Node(int id, int posX, int posY);

	int getId();

	void setId(int id);

	int getPosX();

	void setPosX(int posX);

	int getPosY();

	void setPosY(int posY);

	CircleShape getShape();

	void setShape(CircleShape shape);


	//Text getText();

	//void setText(Text text);

};