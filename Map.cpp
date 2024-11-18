#include "Map.h"

Map::Map() {

	this->drawPathEnabled = false;
	this->animatePoint = false;
	this->currentNodeIndex = 0;
	this->interpolation = 0.0;
	this->speed = 0.001;
	//this->speed = 0.002;

}

Map::Map(bool drawPathEnabled, bool animatePoint, int currentNodeIndex, float interpolation, float speed)
{
	this->drawPathEnabled = drawPathEnabled;
	this->animatePoint = animatePoint;
	this->currentNodeIndex = currentNodeIndex;
	this->interpolation = interpolation;
	this->speed = speed;

}

void Map::loadWindow(Graph& graph, RenderWindow& window)
{
	loadMap();
	loadFont();
	loadCarSprite();
	showWindow(graph, window);

}

void Map::loadMap()
{
	if (this->mapTexture.loadFromFile("PZ.jpg")) {
		std::cerr << "Bienvenido al Sistema" << endl;
		return;
	}
}

void Map::loadFont()
{
	if (!this->font.loadFromFile("UberMoveTextRegular.otf")) {
		std::cerr << "Error loading font\n";
		return;
	}

	this->radioButtons.emplace_back(20, 700, "Sin algoritmo", font, true);
	this->radioButtons.emplace_back(20, 730, "Dijkstra", font);
	this->radioButtons.emplace_back(20, 760, "Floyd", font);
}

void Map::loadCarSprite()
{
	if (!this->carTexture.loadFromFile("carroPequeño.png")) {
		std::cerr << "No se pudo cargar la imagen del sprite\n";
		return;
	}
}

void Map::eventsHandler(RenderWindow& window)
{
	while (window.pollEvent(this->event)) {
		if (event.type == Event::Closed) {
			window.close();
		}

		if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
			drawPathEnabled = true;
			animatePoint = true;
		}

	}
}

void Map::showWindow(Graph& graph, RenderWindow& window){
	Sprite movingCar(this->carTexture);
	Sprite mapSprite(this->mapTexture);
	this->selectedAlgorithm = "Sin algoritmo";

	RadioButton floyd = this->radioButtons.at(2);
	RadioButton djkstra = this->radioButtons.at(1);
	string lastAlgorithm = "";
	Node* firstNode = nullptr;
	Node* lastNode = nullptr;
	bool firstRenderOfTheCar = true;
	while (window.isOpen()) {
		eventsHandler(window);
		window.clear();
		window.draw(mapSprite);
		redrawNode(graph, window);
		graph.drawRadioButtons(window, radioButtons, selectedAlgorithm);

		if (drawPathEnabled) {
			setChooseAlgorithnm(selectedAlgorithm, lastAlgorithm, graph);
			moveCar(this->nodePath, movingCar);
			drawPathFromNodes(firstNode, lastNode, window);
			resetCarPosition(movingCar, firstRenderOfTheCar, firstNode);
			graph.drawPath(window, this->nodePath);
		}

		if (animatePoint) {
			window.draw(movingCar);
			Vector2f carPosition = movingCar.getPosition();
			if (isAlreadyUp(carPosition, lastNode) ||
				isAlreadyDown(carPosition, lastNode) ||
				isAlreadyRight(carPosition, lastNode) ||
				isAlreadyLeft(carPosition, lastNode)
				) {
					resetVariables(firstRenderOfTheCar, lastAlgorithm);
					showTotalMessage();
			}
		}
		window.display();
	}
}

void Map::resetVariables(bool& firstRenderOfTheCar, string& lastAlgorithm) {
	animatePoint = false;
	drawPathEnabled = false;
	selectedAlgorithm = lastAlgorithm;
	this->currentNodeIndex = 0;
	this->interpolation = 0.0f;
	firstRenderOfTheCar = true;
}

bool Map::isAlreadyUp(Vector2f& carPosition, Node*& lastNode) {
	return (((int)carPosition.x + 8) == lastNode->getPosX() && ((int)carPosition.y - 8) == lastNode->getPosY());
}

bool Map::isAlreadyDown(Vector2f& carPosition, Node*& lastNode) {
	return (((int)carPosition.x - 5) == lastNode->getPosX() && ((int)carPosition.y + 8) == lastNode->getPosY());
}

bool Map::isAlreadyRight(Vector2f& carPosition, Node*& lastNode) {
	return (((int)carPosition.x + 11) == lastNode->getPosX() && ((int)carPosition.y + 9) == lastNode->getPosY());
}

bool Map::isAlreadyLeft(Vector2f& carPosition, Node*& lastNode) {
	return (((int)carPosition.x - 10) == lastNode->getPosX() && ((int)carPosition.y - 8) == lastNode->getPosY());
}

void Map::resetCarPosition(Sprite& movingCar, bool& firstRenderOfTheCar, Node*& firstNode) {
	if (firstRenderOfTheCar) {
		Vector2f newPosition;
		newPosition.x = firstNode->getPosX();
		newPosition.y = firstNode->getPosY();
		movingCar.setPosition(newPosition);
		firstRenderOfTheCar = false;
	}
}

void Map::drawPathFromNodes(Node*& firstNode, Node*& lastNode, RenderWindow& window) {
	firstNode = this->nodePath.front();
	lastNode = this->nodePath.back();
	window.draw(firstNode->getShape());
	window.draw(lastNode->getShape());
}

void Map::setChooseAlgorithnm(string& selectedAlgorithm, string& lastAlgorithm, Graph& graph) {
	if (selectedAlgorithm == "Floyd") {
		//if floyd esta marcado en radio button ejecutar este, hacer elif para dijkstra
		lastAlgorithm = selectedAlgorithm;
		selectedAlgorithm = applyFloyd(graph);
	}
	else if (selectedAlgorithm == "Djkstra") {
		lastAlgorithm = selectedAlgorithm;
		selectedAlgorithm = applyDjkstra(graph);
	}
}

void Map::redrawNode(Graph &graph, RenderWindow& window) {
	if (!drawPathEnabled) {
		for (Node* node : graph.getNodes()) {
			window.draw(node->getShape());
			window.draw(node->getText());
		}
	}
}

bool Map::applyDjkstra(Graph& graph) {
	cout << "Apply djkstra" << endl;
	return false;
}


void Map::moveCar(vector<Node*>& nodePath, Sprite& movingCar)
{

	if (animatePoint && currentNodeIndex < nodePath.size() - 1) {
		Vector2f start(
			nodePath.at(currentNodeIndex)->getPosX(),
			nodePath.at(currentNodeIndex)->getPosY());
		Vector2f end(
			nodePath.at(currentNodeIndex+1)->getPosX(),
			nodePath.at(currentNodeIndex+1)->getPosY());

		rotateCar(start, end, movingCar);

		interpolation += speed;

		if (interpolation >= 1) {
			interpolation = 0.0;
			currentNodeIndex++;
		}
	}
}

bool Map::applyFloyd(Graph& graph) {
	vector<vector<int>> next(100, vector<int>(100, -1));
	vector<vector<int>> distances = graph.floydWarshall(next);
	int origin = 0, destination = 0;

	cout << "Origen: ";
	cin >> origin;
	cout << "Destino: ";
	cin >> destination;

	vector<int> path = graph.getPath(origin, destination, next);
	this->nodePath.clear();
	this->totalMoney = 0;
	this->totalTime = 0;

	for (int i = 0; i < path.size(); ++i) {
		Node* node = graph.getNodeById(path[i]);
		if (node != nullptr) {
			this->nodePath.push_back(node);
		}
		else {
			std::cout << "Nodo con id " << path[i] << " no encontrado." << std::endl;
			continue;
		}
		createTotalMoneyAndTime(path, graph, i);
		
	}

	std::cout << std::endl;

	return false;
}

void Map::showTotalMessage() {
	std::cout << "Total del viaje: $" << this->totalMoney << std::endl;
	std::cout << "Total de tiempo del viaje: " << this->totalTime << " min" << std::endl;
}

void Map::createTotalMoneyAndTime(vector<int>& path, Graph& graph, int& i) {
	if (i + 1 < path.size()) {
		int currentNode = path[i];
		int nextNode = path[i + 1];

		vector<Edge*> edges = graph.getAdjList()[currentNode];
		for (Edge* edge : edges){
			if (edge->getTargetNode() == nextNode) {
				this->totalMoney += edge->getPrice();
				this->totalTime += edge->getTime();
				break;
			}
		}
	}
}


void Map::rotateCar(Vector2f& start, Vector2f& end, Sprite& movingCar)
{
	rotateRight(start, end, movingCar);
	rotateLeft(start, end, movingCar);
	rotateUp(start, end, movingCar);
	rotateDown(start, end, movingCar);
}

void Map::rotateRight(Vector2f& start, Vector2f& end, Sprite& movingCar)
{
	if (end.x > start.x && end.y > start.y) { //der
		movingCar.setRotation(15);
		movingCar.setPosition(
			start.x + interpolation * (end.x - start.x) - 10,
			start.y + interpolation * (end.y - start.y) - 8);
	}
}

void Map::rotateLeft(Vector2f& start, Vector2f& end, Sprite& movingCar)
{
	if (end.x < start.x && end.y < start.y) { //izq
		movingCar.setRotation(195);
		//movingCar.setPosition(movingCar.getPosition().y - 20, movingCar.getPosition().x);
		movingCar.setPosition(
			start.x + interpolation * (end.x - start.x) + 10,
			start.y + interpolation * (end.y - start.y) + 8);
	}
}

void Map::rotateUp(Vector2f& start, Vector2f& end, Sprite& movingCar)
{
	if (end.x > start.x && end.y < start.y) { //parriba
		movingCar.setRotation(285);
		movingCar.setPosition(
			start.x + interpolation * (end.x - start.x) - 7,
			start.y + interpolation * (end.y - start.y) + 8);
	}
}

void Map::rotateDown(Vector2f& start, Vector2f& end, Sprite& movingCar)
{
	if (end.x < start.x && end.y > start.y) { //pabajo
		movingCar.setRotation(105);
		movingCar.setPosition(
			start.x + interpolation * (end.x - start.x) + 5,
			start.y + interpolation * (end.y - start.y) - 7);
	}
}