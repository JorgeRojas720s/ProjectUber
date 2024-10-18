#pragma once


class Edge {

	int targetNode;
	int price;
	int time;
public: 
	Edge();
	Edge(int targetNode, int weight, int time);

	int getTargetNode();
	int getPrice();
	int getTime();

	void setTargetNode(int targetNode);
	void setPrice(int price);
	void setTime(int time);
};