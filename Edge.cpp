#include "Edge.h"

Edge::Edge()
{
}

Edge::Edge(int targetNode, int price, int time)
{
	this->targetNode = targetNode;
	this->price = price;
	this->time = time;
}

int Edge::getTargetNode()
{
	return this->targetNode;
}

int Edge::getPrice()
{
	return this->price;
}

int Edge::getTime()
{
	return this->time;
}

void Edge::setTargetNode(int targetNode)
{
	this->targetNode = targetNode;
}

void Edge::setPrice(int price)
{
	this->price = price;
}

void Edge::setTime(int time)
{
	this->time = time;
}
