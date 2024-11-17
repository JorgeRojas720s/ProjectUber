#include "Node.h"

Node::Node()
{
	if (!this->font.loadFromFile("UberMoveTextRegular.otf")) {
		std::cerr << "Error loading font\n";
		return;
	}

}

Node::Node(int id, int posX, int posY)
{
	this->id = id;
	this->posX = posX;
	this->posY = posY;
	this->shape.setRadius(2);
	this->shape.setFillColor(Color::Blue);
	this->shape.setPosition(posX - this->shape.getRadius(), posY - this->shape.getRadius());
	this->text.setString(to_string(id));
	this->text.setCharacterSize(this->shape.getRadius() * 3); 
	this->text.setFillColor(Color::Blue);
	this->text.setFont(this->font);
	this->text.setPosition(posX - this->text.getLocalBounds().width / 2, posY - this->text.getLocalBounds().height / 2);

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

Text Node::getText()
{
	return this->text;
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

