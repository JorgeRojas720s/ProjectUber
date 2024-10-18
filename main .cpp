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
	vector<vector<int>> edges = {
		{0, 1, 10, 5},
		{1, 2, 5, 3},
		{2, 0, 8, 4},
		/*{3, 4, 7, 3},
		{4, 5, 6, 3},
		{5, 6, 10, 7},
		{6, 7, 12, 8},
		{7, 8, 5, 2},
		{8, 9, 7, 3},
		{9, 10, 9, 5},
		{10, 11, 8, 4},
		{11, 12, 6, 3},
		{12, 13, 5, 3},
		{13, 14, 7, 3},
		{14, 15, 9, 4},
		{15, 16, 10, 5},
		{16, 17, 8, 4},
		{17, 18, 12, 6},
		{18, 19, 11, 5} */
	};


	//Podria utilizar const auto& edge, que auto es para que el compilador identifique el tipo de variable, y & para que solo use la referencia
	for (vector<int> edge : edges) {
		// 1- origen, 2- destino, 3- Precio, 4- Tiempo 
		g.addEdge(edge[0], edge[1], edge[2], edge[3]);
	}
}

void loadWindow(Graph& g) {

	RenderWindow window(VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Uber :)");

	Texture mapTexture;
	if (!mapTexture.loadFromFile("PZ.jpg")) {
		cerr << "No se pudo cargar la imagen del mapa\n";
		return;
	}
	Sprite mapSprite(mapTexture);

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

	/*	g.drawPath(window, g.getNodes());*/

		window.display();
	}


}

int main() {
	const int NUMBER_NODES = 100;
	Graph g(NUMBER_NODES);

	setPositions(g);
	//addEdges(g);

	loadWindow(g);

	return 0;
}
