#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graph.h"
#include "Node.h"
#include "Map.h"
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
	{16, 9, 15, 10},
	{14, 10, 20, 12},
	{91, 92, 18, 11},
	{0, 32, 25, 15},
	{32, 33, 22, 14},
	{33, 35, 30, 20},
	{35, 59, 27, 18},
	{59, 60, 12, 8},
	{60, 61, 15, 10},
	{61, 62, 18, 11},
	{62, 64, 20, 13},
	{64, 65, 25, 14},
	{65, 99, 28, 16},
	{99, 66, 22, 12},
	{66, 68, 19, 10},
	{68, 86, 30, 18},
	{86, 85, 25, 15},
	{85, 84, 20, 12},
	{84, 82, 18, 11},
	{82, 81, 22, 14},
	{81, 98, 27, 16},
	{98, 18, 30, 20},
	{18, 17, 12, 8},
	{18, 19, 15, 9},
	{19, 94, 20, 13},
	{94, 95, 18, 10},
	{94, 20, 22, 14},
	{20, 89, 27, 16},
	{89, 16, 25, 15},
	{20, 21, 30, 18},
	{36, 34, 15, 9},
	{57, 36, 20, 12},
	{58, 57, 18, 10},
	{58, 59, 22, 13},
	{58, 56, 19, 11},
	{56, 65, 25, 14},
	{58, 63, 27, 15},
	{63, 64, 20, 12},
	{63, 62, 18, 10},
	{66, 67, 22, 13},
	{82, 83, 25, 15},
	{84, 75, 20, 12},
	{75, 76, 30, 18},
	{76, 77, 15, 9},
	{77, 78, 18, 10},
	{78, 79, 22, 14},
	{79, 80, 27, 16},
	{79, 44, 25, 15},
	{44, 19, 30, 18},
	{44, 45, 20, 13},
	{45, 43, 15, 9},
	{43, 42, 18, 11},
	{42, 46, 22, 13},
	{45, 47, 27, 16},
	{47, 48, 25, 14},
	{47, 49, 30, 18},
	{49, 41, 20, 12},
	{41, 42, 18, 10},
	{49, 73, 22, 14},
	{73, 74, 27, 16},
	{75, 73, 25, 15},
	{85, 87, 30, 18},
	{87, 88, 20, 12},
	{87, 71, 18, 10},
	{71, 72, 22, 13},
	{72, 73, 27, 16},
	{72, 50, 25, 14},
	{50, 49, 30, 18},
	{50, 40, 20, 12},
	{40, 41, 15, 9},
	{71, 70, 18, 11},
	{50, 51, 22, 13},
	{40, 39, 27, 16},
	{40, 23, 25, 14},
	{23, 22, 30, 18},
	{22, 14, 20, 13},
	{55, 54, 18, 10},
	{54, 53, 22, 13},
	{53, 37, 27, 16},
	{70, 69, 25, 15},
	{51, 52, 30, 18},
	{28, 29, 20, 12},
	{29, 93, 18, 10},
	{29, 31, 22, 13},
	{29, 30, 27, 16},
	{30, 27, 25, 14},
	{24, 97, 30, 18},
	{37, 28, 20, 12},
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
	{0, 12, 15, 10},
	{12, 26, 18, 12},
	{26, 27, 20, 14},
	{27, 28, 22, 15},
	{28, 34, 25, 16},
	{34, 33, 17, 11},
	{32, 31, 19, 13},
	{31, 12, 21, 14},
	{12, 13, 23, 16},
	{13, 11, 24, 15},
	{11, 1, 26, 17},
	{13, 14, 28, 18},
	{14, 15, 30, 20},
	{15, 16, 18, 12},
	{17, 16, 20, 13},
	{17, 7, 22, 15},
	{7, 8, 24, 16},
	{8, 9, 26, 17},
	{4, 9, 28, 18},
	{9, 96, 30, 20},
	{96, 10, 15, 10},
	{10, 11, 18, 12},
	{10, 91, 20, 13},
	{91, 2, 22, 15},
	{15, 96, 24, 16},
	{15, 21, 26, 17},
	{21, 22, 28, 18},
	{23, 24, 30, 20},
	{24, 25, 18, 12},
	{25, 13, 20, 13},
	{25, 26, 22, 14},
	{26, 38, 24, 16},
	{38, 39, 26, 17},
	{39, 24, 28, 18},
	{35, 36, 30, 20},
	{36, 37, 18, 12},
	{37, 38, 20, 13},
	{38, 52, 22, 15},
	{51, 39, 24, 16},
	{52, 69, 26, 17},
	{69, 68, 28, 18},
	{86, 70, 30, 20},
	{70, 51, 18, 12},
	{52, 53, 20, 13},
	{53, 56, 22, 15},
	};


	//Podria utilizar const auto& edge, que auto es para que el compilador identifique el tipo de variable, y & para que solo use la referencia
	for (vector<int> edge : directedEdges) {
		// 1- origen, 2- destino, 3- Precio, 4- Tiempo 
		g.addDirectedEdge(edge[0], edge[1], edge[2], edge[3]);
	}
}

int main() {

	const int NUMBER_NODES = 100;
	RenderWindow window(VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Uber :)");
	Graph graph(NUMBER_NODES);

	setPositions(graph);
	addEdges(graph);
	addDirectedEdges(graph);


	vector<vector<int>> next(100, vector<int>(100, -1));
	vector<vector<int>> distances = graph.floydWarshall(next);

	vector<int> path = graph.getPath(27, 97, next);

	vector<Node*> nodePath;  

	for (int nodeId : path) { 
		Node* node = graph.getNodeById(nodeId); 
		if (node != nullptr) { 
			nodePath.push_back(node);
		}
		else {
			std::cout << "Nodo con id " << nodeId << " no encontrado." << std::endl;
		}
	}
	std::cout << std::endl;

	/*loadWindow(graph, window, nodePath);*/

	Map* map = new Map();
	map->loadWindow(graph, window, nodePath);
	//graph.drawPath(window, nodePath);

	return 0;
}
