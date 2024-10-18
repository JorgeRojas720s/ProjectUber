#pragma once
#include <SFML/Graphics.hpp>
#include "Node.h"
#include "Edge.h"
#include <vector>

using namespace std;
using namespace sf;

class Graph {


private:
	int numberVertices;
	vector<Node*> nodes;
	vector<vector<Edge*>> adjList;
public:
	Graph(int numberVertices);
	vector<Node*> getNodes();
	void setNodes(const vector<Node*>& newNodes);
	vector<vector<Edge*>> getAdjList();
	void setAdjList(const vector<vector<Edge*>>& newAdjList);

	void addNode(int id, int posX, int posY);
	void addEdge(int startNode, int endNode, int price, int time);
	void addDirectedEdge(int startNode, int endNode, int price, int time);
	void printGraph();
	void drawPath(RenderWindow& window, const vector<Node*>& nodes);
};