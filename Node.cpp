#include "Node.h"

Node::Node()
{
}

Node::Node(int id, int posX, int posY)
{
	this->id = id;
	this->posX = posX;
	this->posY = posY;
	shape.setRadius(5);
	shape.setFillColor(Color::Blue);
	shape.setPosition(posX - shape.getRadius(), posY - shape.getRadius());
	//text.setString(to_string(id));
	//text.setCharacterSize(12);
	//text.setFillColor(Color::White);
	//text.setPosition(posX, posY);
}

int Node::getId()
{
	return this->id;
}

void Node::setId(int id)
{
	this->id = id;
}

int Node::getPosX()
{
	return this->posX;
}

void Node::setPosX(int posX)
{
	this->posX = posX;
}

int Node::getPosY()
{
	return this->posY;
}

void Node::setPosY(int posY)
{
	this->posY = posY;
}

CircleShape Node::getShape()
{
	return this->shape;
}

void Node::setShape(CircleShape shape)
{
	this->shape = shape;
}
//
//Text Node::getText()
//{
//	return this->text;
//}
//
//void Node::setText(Text text)
//{
//	this->text = text;
//}

