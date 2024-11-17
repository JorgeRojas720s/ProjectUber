#pragma once
#include <SFML/Graphics.hpp>
#include "RadioButton.h"
#include "Graph.h"
#include "Node.h"
#include <vector>


using namespace sf;
using namespace std;


class Map {

private:
	Texture mapTexture;
	Texture carTexture;
	string selectedAlgorithm;
	Font font;
	vector<RadioButton> radioButtons;
	vector<Node*> nodePath;
	Event event;
	bool drawPathEnabled;
	bool animatePoint;
	int currentNodeIndex;
	float interpolation;
	float speed;

public:
	Map();
	Map(bool, bool, int, float, float);

	void loadWindow(Graph&, RenderWindow&);
	void loadMap();
	void loadFont();
	void loadCarSprite();
	void eventsHandler(RenderWindow&);
	void showMessage(RenderWindow&, const string&, Font&);
	void showWindow(Graph&, RenderWindow&);
	void resetVariables(bool&, string&);
	bool isAlreadyUp(Vector2f&, Node*&);
	bool isAlreadyDown(Vector2f&, Node*&);
	bool isAlreadyRight(Vector2f&, Node*&);
	bool isAlreadyLeft(Vector2f&, Node*&);
	void resetCarPosition(Sprite&, bool&, Node*&);
	void drawPathFromNodes(Node*& , Node*& , RenderWindow& );
	
	void setChooseAlgorithnm(string& , string& , Graph& );
	void redrawNode(Graph&, RenderWindow&);
	
	bool applyDjkstra(Graph& graph);
	void moveCar(vector<Node*>& , Sprite&);
	bool applyFloyd(Graph& graph);
	void rotateCar(Vector2f&, Vector2f&, Sprite&);
	void rotateRight(Vector2f&, Vector2f&, Sprite&);
	void rotateLeft(Vector2f&, Vector2f&, Sprite&);
	void rotateUp(Vector2f&, Vector2f&, Sprite&);
	void rotateDown(Vector2f&, Vector2f&, Sprite&);



};