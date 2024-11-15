#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graph.h"
#include "Node.h"
#include <vector>

using namespace std;
using namespace sf;

const int WIDTH_WINDOW = 654;
const int HEIGHT_WINDOW = 810;

void setPositions(Graph& g) {


	g.addNode(0, 592, 471);
	g.addNode(1, 568, 520);
	g.addNode(2, 547, 572);
	g.addNode(3, 530, 621);
	g.addNode(4, 509, 673);
	g.addNode(5, 503, 689);
	g.addNode(6, 470, 780);
	g.addNode(7, 446, 770);
	g.addNode(8, 453, 669);
	g.addNode(9, 458, 650);
	g.addNode(10, 499, 551);
	g.addNode(11, 521, 501);
	g.addNode(12, 492, 431);
	g.addNode(13, 471, 479);
	g.addNode(14, 451, 532);
	g.addNode(15, 430, 581);
	g.addNode(16, 412, 634);
	g.addNode(17, 379, 742);
	g.addNode(18, 324, 712);
	g.addNode(19, 342, 662);
	g.addNode(20, 355, 617);
	g.addNode(21, 370, 566);
	g.addNode(22, 389, 507);
	g.addNode(23, 374, 500);
	g.addNode(24, 393, 447);
	g.addNode(25, 422, 459);
	g.addNode(26, 439, 411);
	g.addNode(27, 450, 385);
	g.addNode(28, 459, 359);
	g.addNode(29, 483, 368);
	g.addNode(30, 473, 393);
	g.addNode(31, 507, 377);
	g.addNode(32, 520, 340);
	g.addNode(33, 487, 282);
	g.addNode(34, 477, 307);
	g.addNode(35, 445, 219);
	g.addNode(36, 421, 285);
	g.addNode(37, 404, 338);
	g.addNode(38, 386, 390);
	g.addNode(39, 368, 438);
	g.addNode(40, 348, 491);
	g.addNode(41, 326, 551);
	g.addNode(42, 307, 609);
	g.addNode(43, 299, 631);
	g.addNode(44, 232, 618);
	g.addNode(45, 239, 604);
	g.addNode(46, 278, 598);
	g.addNode(47, 257, 562);
	g.addNode(48, 242, 554);
	g.addNode(49, 271, 529);
	g.addNode(50, 298, 469);
	g.addNode(51, 321, 418);
	g.addNode(52, 332, 372);
	g.addNode(53, 335, 312);
	g.addNode(54, 320, 314);
	g.addNode(55, 315, 328);
	g.addNode(56, 312, 229);
	g.addNode(57, 367, 263);
	g.addNode(58, 368, 206);
	g.addNode(59, 421, 182);
	g.addNode(60, 345, 35);
	g.addNode(61, 310, 64);
	g.addNode(62, 295, 96);
	g.addNode(63, 343, 156);
	g.addNode(64, 276, 188);
	g.addNode(65, 274, 220);
	g.addNode(66, 254, 301);
	g.addNode(67, 292, 311);
	g.addNode(68, 225, 348);
	g.addNode(69, 281, 363);
	g.addNode(70, 268, 395);
	g.addNode(71, 243, 444);
	g.addNode(72, 258, 453);
	g.addNode(73, 232, 513);
	g.addNode(74, 212, 554);
	g.addNode(75, 190, 492);
	g.addNode(76, 166, 541);
	g.addNode(77, 157, 554);
	g.addNode(78, 144, 548);
	g.addNode(79, 127, 566);
	g.addNode(80, 102, 551);
	g.addNode(81, 45, 555);
	g.addNode(82, 103, 488);
	g.addNode(83, 138, 512);
	g.addNode(84, 139, 444);
	g.addNode(85, 168, 410);
	g.addNode(86, 207, 370);
	g.addNode(87, 204, 428);
	g.addNode(88, 192, 451);
	g.addNode(89, 390, 629);
	g.addNode(90, 395, 613);
	g.addNode(91, 532, 566);
	g.addNode(92, 544, 537);
	g.addNode(93, 489, 334);
	g.addNode(94, 346, 651);
	g.addNode(95, 365, 659);
	g.addNode(96, 477, 603);
	g.addNode(97, 405, 430);
	g.addNode(98, 137, 611);
	g.addNode(99, 270, 247);


}

void addEdges(Graph& g) {
	// Doble via
	vector<vector<int>> edges = {
		{0, 1, 10, 5},
		{1, 2, 5, 3},
		{2, 3, 8, 4},
		{3, 4, 7, 3},
		{4, 5, 6, 3},
		{5, 6, 10, 7},
		{5, 8, 3, 2},
		{6, 7, 12, 8},
		{16, 9, 0, 0},
		{14, 10, 0, 0},
		{91, 92, 0, 0},
		{0, 32, 0, 0},
		{32, 33, 0, 0},
		{33, 35, 0, 0},
		{35, 59, 0, 0},
		{59, 60, 0, 0},
		{60, 61, 0, 0},
		{61, 62, 0, 0},
		{62, 64, 0, 0},
		{64, 65, 0, 0},
		{65, 99, 0, 0},
		{99, 66, 0, 0},
		{66, 68, 0, 0},
		{68, 86, 0, 0},
		{86, 85, 0, 0},
		{85, 84, 0, 0},
		{84, 82, 0, 0},
		{82, 81, 0, 0},
		{81, 98, 0, 0},
		{98, 18, 0, 0},
		{18, 17, 0, 0},
		{18, 19, 0, 0},
		{19, 94, 0, 0},
		{94, 95, 0, 0},
		{94, 20, 0, 0},
		{20, 89, 0, 0},
		{89, 16, 0, 0},
		{20, 21, 0, 0},
		{36, 34, 0, 0},
		{57, 36, 0, 0},
		{58, 57, 0, 0},
		{58, 59, 0, 0},
		{58, 56, 0, 0},
		{56, 65, 0, 0},
		{58, 63, 0, 0},
		{63, 64, 0, 0},
		{63, 62, 0, 0},
		{66, 67, 0, 0},
		{82, 83, 0, 0},
		{84, 75, 0, 0},
		{75, 76, 0, 0},
		{76, 77, 0, 0},
		{77, 78, 0, 0},
		{78, 79, 0, 0},
		{79, 80, 0, 0},
		{79, 44, 0, 0},
		{44, 19, 0, 0},
		{44, 45, 0, 0},
		{45, 43, 0, 0},
		{43, 42, 0, 0},
		{42, 46, 0, 0},
		{45, 47, 0, 0},
		{47, 48, 0, 0},
		{47, 49, 0, 0},
		{49, 41, 0, 0},
		{41, 42, 0, 0},
		{49, 73, 0, 0},
		{73, 74, 0, 0},
		{75, 73, 0, 0},
		{85, 87, 0, 0},
		{87, 88, 0, 0},
		{87, 71, 0, 0},
		{71, 72, 0, 0},
		{72, 73, 0, 0},
		{72, 50, 0, 0},
		{50, 49, 0, 0},
		{50, 40, 0, 0},
		{40, 41, 0, 0},
		{71, 70, 0, 0},
		{50, 51, 0, 0},
		{40, 39, 0, 0},
		{40, 23, 0, 0},
		{23, 22, 0, 0},
		{22, 14, 0, 0},
		{55, 54, 0, 0},
		{54, 53, 0, 0},
		{53, 37, 0, 0},
		{70, 69, 0, 0},
		{51, 52, 0, 0},
		{28, 29, 0, 0},
		{29, 93, 0, 0},
		{29, 31, 0, 0},
		{29, 30, 0, 0},
		{30, 27, 0, 0},
		{24, 97, 0, 0},
		{37, 28, 0, 0},
	};


	//Podria utilizar const auto& edge, que auto es para que el compilador identifique el tipo de variable, y & para que solo use la referencia
	for (vector<int> edge : edges) {
		// 1- origen, 2- destino, 3- Precio, 4- Tiempo 
		g.addEdge(edge[0], edge[1], edge[2], edge[3]);
	}
}

void addDirectedEdges(Graph& g) {
	// Una via
	vector<vector<int>> directedEdges = {
		{0, 12, 0, 0},
		{12, 26, 0, 0},
		{26, 27, 0, 0},
		{27, 28, 0, 0},
		{28, 34, 0, 0},
		{34, 33, 0, 0},
		{32, 31, 0, 0},
		{31, 12, 0, 0},
		{12, 13, 0, 0},
		{13, 11, 0, 0},
		{11, 1, 0, 0},
		{13, 14, 0, 0},
		{14, 15, 0, 0},
		{15, 16, 0, 0},
		{17, 16, 0, 0},
		{17, 7, 0, 0},
		{7, 8, 0, 0},
		{8, 9, 0, 0},
		{4, 9, 0, 0},
		{9, 96, 0, 0},
		{96, 10, 0, 0},
		{10, 11, 0, 0},
		{10, 91, 0, 0},
		{91, 2, 0, 0},
		{15, 96, 0, 0},
		{15, 21, 0, 0},
		{21, 22, 0, 0},
		{23, 24, 0, 0},
		{24, 25, 0, 0},
		{25, 13, 0, 0},
		{25, 26, 0, 0},
		{26, 38, 0, 0},
		{38, 39, 0, 0},
		{39, 24, 0, 0},
		{35, 36, 0, 0},
		{36, 37, 0, 0},
		{37, 38, 0, 0},
		{38, 52, 0, 0},
		{51, 39, 0, 0},
		{52, 69, 0, 0},
		{69, 68, 0, 0},
		{86, 70, 0, 0},
		{70, 51, 0, 0},
		{52, 53, 0, 0},
		{53, 56, 0, 0},
	};


	//Podria utilizar const auto& edge, que auto es para que el compilador identifique el tipo de variable, y & para que solo use la referencia
	for (vector<int> edge : directedEdges) {
		// 1- origen, 2- destino, 3- Precio, 4- Tiempo 
		g.addDirectedEdge(edge[0], edge[1], edge[2], edge[3]);
	}
}

class RadioButton {
public:
	CircleShape outerCircle;
	CircleShape innerCircle;
	Text label;
	bool selected;

	RadioButton(float x, float y, const string& labelText, Font& font) {
		outerCircle.setRadius(10);
		outerCircle.setFillColor(Color::White);
		outerCircle.setOutlineColor(Color::Black);
		outerCircle.setOutlineThickness(2);
		outerCircle.setPosition(x, y);

		innerCircle.setRadius(5);
		innerCircle.setFillColor(Color::Black);
		innerCircle.setPosition(x + 5, y + 5); // centered within outer circle
		selected = false;

		label.setFont(font);
		label.setString(labelText);
		label.setCharacterSize(16);
		label.setFillColor(Color::Black);
		label.setPosition(x + 25, y - 3); // position label to the right of the button
	}

	void draw(RenderWindow& window) {
		window.draw(outerCircle);
		if (selected) {
			window.draw(innerCircle);
		}
		window.draw(label);
	}

	bool isClicked(Vector2f mousePos) {
		return outerCircle.getGlobalBounds().contains(mousePos);
	}

	void select() { selected = true; }
	void deselect() { selected = false; }
};

void drawRadioButtons(RenderWindow& window, vector<RadioButton>& radioButtons, string& selectedAlgorithm) {
	static bool wasMousePressed = false;

	Vector2f mousePos = (Vector2f)Mouse::getPosition(window);
	bool printRadioBtn = false;

	if (Mouse::isButtonPressed(Mouse::Left) && !wasMousePressed) {
		for (auto& button : radioButtons) {
			if (button.isClicked(mousePos)) {
				for (auto& btn : radioButtons) btn.deselect();
				button.select();
				selectedAlgorithm = button.label.getString();
				printRadioBtn = true;
				break;
			}
		}
	}

	if (printRadioBtn) {
		cout << selectedAlgorithm << endl;
	}

	for (auto& button : radioButtons) {
		button.draw(window);
	}

	wasMousePressed = Mouse::isButtonPressed(Mouse::Left);
}


void loadWindow(Graph& g) {

	RenderWindow window(VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Uber :)");

	Texture mapTexture;
	if (!mapTexture.loadFromFile("PZ.jpg")) {
		cerr << "No se pudo cargar la imagen del mapa\n";
		return;
	}
	Sprite mapSprite(mapTexture);

	string selectedAlgorithm = "Sin algoritmo";

	Font font;
	if (!font.loadFromFile("UberMoveTextRegular.otf")) {
		cerr << "Error loading font\n";
		return;
	}

    vector<RadioButton> radioButtons;
    radioButtons.emplace_back(20, 700, "Sin algoritmo", font);
    radioButtons.emplace_back(20, 730, "Dijkstra", font);
    radioButtons.emplace_back(20, 760, "Floyd", font);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(mapSprite);

		for (Node* node : g.getNodes()) {
			window.draw(node->getShape());
			//window.draw(node->getText());
		}

		drawRadioButtons(window, radioButtons, selectedAlgorithm);

		/*	g.drawPath(window, g.getNodes());*/

		window.display();
	}


}

int main() {
	const int NUMBER_NODES = 100;
	Graph g(NUMBER_NODES);

	setPositions(g);
	//addEdges(g);
	//addDirectedEdges(g);

	loadWindow(g);

	return 0;
}
