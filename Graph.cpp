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

vector<vector<int>> Graph::floydWarshall(vector<vector<int>>& next) {
    // Obtener el número de nodos
    int n = nodes.size();

    // Crear la matriz de distancias
    vector<vector<int>> dist(numberVertices, vector<int>(numberVertices, INT_MAX));

    // Inicializar las distancias y la matriz `next`
    for (int i = 0; i < numberVertices; ++i) {
        dist[i][i] = 0; // La distancia de un nodo a sí mismo es 0
        next[i][i] = i; // El siguiente nodo en el camino a sí mismo es el propio nodo
        for (Edge* edge : adjList[i]) {
            dist[i][edge->getTargetNode()] = edge->getPrice();
            next[i][edge->getTargetNode()] = edge->getTargetNode(); // El siguiente nodo es el destino de la arista
        }
    }

    // Algoritmo de Floyd-Warshall
    for (int k = 0; k < numberVertices; ++k) {
        for (int i = 0; i < numberVertices; ++i) {
            for (int j = 0; j < numberVertices; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    int newDist = dist[i][k] + dist[k][j];
                    if (newDist < dist[i][j]) {
                        dist[i][j] = newDist;
                        next[i][j] = next[i][k]; // Actualiza el siguiente nodo
                    }
                }
            }
        }
    }

    return dist;
}

vector<int> Graph::dijkstra(int start, int end, int metric) {
    vector<int> distances(numberVertices, INT_MAX);
    vector<bool> visited(numberVertices, false);
    vector<int> parent(numberVertices, -1);
    distances[start] = 0;
    parent[start] = start;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (current == end) break;

        if (visited[current] || currentDist > distances[current]) continue;

        visited[current] = true;

        for (Edge* edge : adjList[current]) {
            int neighbor = edge->getTargetNode();

            int weight = (metric == 0) ? edge->getPrice() : edge->getTime();

            if (!visited[neighbor] && distances[current] + weight < distances[neighbor]) {
                distances[neighbor] = distances[current] + weight;
                parent[neighbor] = current; 
                pq.push({ distances[neighbor], neighbor });
            }
        }
    }

    vector<int> path;
    if (distances[end] != INT_MAX) { 
        int current = end;
        while (current != start) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
    }

    return path;
}

vector<int> Graph::getPath(int start, int end, const vector<vector<int>>& next) {
    vector<int> path;
    if (next[start][end] == -1) return path;  // No hay camino

    int currentNode = start;
    while (currentNode != end) {
        path.push_back(currentNode);
        currentNode = next[currentNode][end];
        if (currentNode == -1) break;  // Si no hay más caminos, se rompe
    }
    path.push_back(end);
    return path;
}

void Graph::drawPath(RenderWindow& window, const vector<Node*>& nodes)
{
    VertexArray lines(LinesStrip, nodes.size());

    for (int i = 0; i < nodes.size(); ++i) {
        lines[i].position = Vector2f(nodes[i]->getPosX(), nodes[i]->getPosY());
        lines[i].color = Color::Red; 
    }

    window.draw(lines);
}

Node* Graph::getNodeById(int id) {
    for (Node* node : nodes) {
        if (node->getId() == id) {
            return node;  // Devuelve el nodo si se encuentra con el id
        }
    }
    return nullptr;  // Si no se encuentra el nodo, devuelve nullptr
}

void Graph::drawRadioButtons(RenderWindow& window, vector<RadioButton>& radioButtons, string& selectedAlgorithm) {
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

