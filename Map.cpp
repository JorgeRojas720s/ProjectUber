#include "Map.h"

Map::Map() {

	this->drawPathEnabled = false;
	this->animatePoint = false;
	this->currentNodeIndex = 0;
	this->interpolation = 0.0;
	this->speed = 0.0001;
}

Map::Map(bool drawPathEnabled, bool animatePoint, int currentNodeIndex, float interpolation, float speed)
{
	this->drawPathEnabled = drawPathEnabled;
	this->animatePoint = animatePoint;
	this->currentNodeIndex = currentNodeIndex;
	this->interpolation = interpolation;
	this->speed = speed;

}

void Map::loadWindow(Graph& graph, RenderWindow& window, vector<Node*>& nodePath)
{
	loadMap();
	loadFont();
	loadCarSprite();
	showWindow(graph, window, nodePath);

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
	if (!this->spriteTexture.loadFromFile("carroPequeño.png")) {
		std::cerr << "No se pudo cargar la imagen del sprite\n";
		return;
	}
}

void Map::showWindow(Graph& graph, RenderWindow& window, vector<Node*>& nodePath)
{

	Sprite movingSprite(this->spriteTexture);
	Sprite mapSprite(this->mapTexture);
	this->selectedAlgorithm = "Sin algoritmo";

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
				drawPathEnabled = true;
				animatePoint = true;
			}
		}

		if (animatePoint && currentNodeIndex < nodePath.size() - 1) {
			Vector2f start(
				nodePath[currentNodeIndex]->getPosX(),
				nodePath[currentNodeIndex]->getPosY());
			Vector2f end(
				nodePath[currentNodeIndex + 1]->getPosX(),
				nodePath[currentNodeIndex + 1]->getPosY());

			movingSprite.setPosition(
				start.x + interpolation * (end.x - start.x),
				start.y + interpolation * (end.y - start.y));

			interpolation += speed;

			if (interpolation >= 1.0) {
				interpolation = 0.0;
				currentNodeIndex++;
			}
		}

		window.clear();

		window.draw(mapSprite);

		for (Node* node : graph.getNodes()) {
			window.draw(node->getShape());
		}

		graph.drawRadioButtons(window, radioButtons, selectedAlgorithm);

		if (drawPathEnabled) {
			graph.drawPath(window, nodePath);
		}

		if (animatePoint) {
			window.draw(movingSprite);
		}

		window.display();
	}
}
