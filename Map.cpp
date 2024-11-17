#include "Map.h"

Map::Map() {

	this->drawPathEnabled = false;
	this->animatePoint = false;
	this->currentNodeIndex = 0;
	this->interpolation = 0.0;
	this->speed = 0.0001;
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
		std::cerr << "No se pudo cargar la imagen del mapa\n";
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




void Map::showWindow(Graph& graph, RenderWindow& window)
{
	Sprite movingCar(this->carTexture);
	Sprite mapSprite(this->mapTexture);
	this->selectedAlgorithm = "Sin algoritmo";
	bool aux = true;

	while (window.isOpen()) {
		eventsHandler(window);

		window.clear();

		window.draw(mapSprite);

		//intenten ver porque no pinta el culo texto
		if (!drawPathEnabled) {
			for (Node* node : graph.getNodes()) {
				window.draw(node->getShape());
				window.draw(node->getText());
			}
		}

		graph.drawRadioButtons(window, radioButtons, selectedAlgorithm);

		if (drawPathEnabled) {
			if (aux == true) {
				//if floyd esta marcado en radio button ejecutar este, hacer elif para dijkstra
				aux = applyFloyd(graph);

			}

			moveCar(this->nodePath, movingCar);
			//! Ver si dejo esto
			Node* firstNode = this->nodePath.front();
			Node* lastNode = this->nodePath.back();
			window.draw(firstNode->getShape());
			window.draw(lastNode->getShape());
			//hasta aqui
			graph.drawPath(window, this->nodePath);
		}

		if (animatePoint) {
			window.draw(movingCar);
		}

		window.display();
	}
}

void Map::moveCar(vector<Node*>& nodePath, Sprite& movingCar)
{

	if (animatePoint && currentNodeIndex < nodePath.size() - 1) {
		Vector2f start(
			nodePath[currentNodeIndex]->getPosX(),
			nodePath[currentNodeIndex]->getPosY());
		Vector2f end(
			nodePath[currentNodeIndex + 1]->getPosX(),
			nodePath[currentNodeIndex + 1]->getPosY());

		rotateCar(start, end, movingCar);

		interpolation += speed;

		if (interpolation >= 1) {
			interpolation = 0.0;
			currentNodeIndex++;
		}
	}
}

bool Map::applyFloyd(Graph& graph)
{
	vector<vector<int>> next(100, vector<int>(100, -1));
	vector<vector<int>> distances = graph.floydWarshall(next);
	int dato1, dato2;
	cout << "Ingrese:";
	cin >> dato1;
	cin >> dato2;

	vector<int> path = graph.getPath(dato1, dato2, next);

	for (int nodeId : path) {
		Node* node = graph.getNodeById(nodeId);
		if (node != nullptr) {
			this->nodePath.push_back(node);
		}
		else {
			std::cout << "Nodo con id " << nodeId << " no encontrado." << std::endl;
		}
	}
	std::cout << std::endl;
	return false;
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
