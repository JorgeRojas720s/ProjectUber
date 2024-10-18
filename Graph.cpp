#include "Graph.h"

Graph::Graph(int numberVertices)
{
	this->numberVertices = numberVertices;
	this->adjList.resize(numberVertices);
}

vector<Node*> Graph::getNodes()
{
    return this->nodes;
}

void Graph::setNodes(const vector<Node*>& newNodes)
{
    this->nodes = newNodes;
}

vector<vector<Edge*>> Graph::getAdjList()
{
    return this->adjList;
}

void Graph::setAdjList(const vector<vector<Edge*>>& newAdjList)
{
    this->adjList = adjList;
}

void Graph::addNode(int id, int posX, int posY)
{
	Node* newNode = new Node(id, posX, posY);
	this->nodes.push_back(newNode);
}

void Graph::addEdge(int startNode, int endNode, int price, int time)
{
    Edge* aux1 = new Edge(endNode, price, time);
    Edge* aux2 = new Edge(startNode, price, time);
	adjList[startNode].push_back(aux1);
	adjList[endNode].push_back(aux2);
}

void Graph::addDirectedEdge(int startNode, int endNode, int price, int time)
{
    Edge* aux1 = new Edge(endNode, price, time);
	adjList[startNode].push_back(aux1);
}

void Graph::printGraph()
{
    for (int i = 0; i < this->numberVertices; ++i) {
        cout << "Nodo " << this->nodes[i]->getId() << " en las coordenadas(" <<
            this->nodes[i]->getPosX() << "," << this->nodes[i]->getPosY() << ") esta conectado con : \n";
        for (Edge* edge : adjList[i]) {
            cout << " -> Nodo " << edge->getTargetNode()
                << " con un precio de " << edge->getPrice()
                << " y un tiempo de " << edge->getTime() << " minutos" << endl;
        }
        cout << endl;
    } 
}

void Graph::drawPath(RenderWindow& window, const vector<Node*>& nodes)
{
    VertexArray lines(LinesStrip, this->numberVertices);

    for (int i = 0; i < this->numberVertices; ++i) {
        lines[i].position = Vector2f(nodes[i]->getPosX(), nodes[i]->getPosY());
        lines[i].color = Color::Red; 
    }

    window.draw(lines);
}

