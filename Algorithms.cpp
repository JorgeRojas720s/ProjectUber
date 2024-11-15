#include "Algorithms.h"

// Función recursiva para encontrar la distancia mínima
void Algorithms::findShortest(int node, vector<vector<pair<int, int>>>& graph, vector<int>& dist, set<int>& visited) {
    visited.insert(node);

    // Recorremos todos los vecinos del nodo actual
    for (auto& neighbor : graph[node]) {
        int adjNode = neighbor.first;
        int weight = neighbor.second;

        // Si se encuentra una distancia menor, la actualizamos
        if (dist[node] + weight < dist[adjNode]) {
            dist[adjNode] = dist[node] + weight;
        }
    }

    // Encontramos el siguiente nodo con la distancia mínima no visitado
    int nextNode = -1;
    int minDist = INF;
    for (int i = 0; i < dist.size(); i++) {
        if (visited.find(i) == visited.end() && dist[i] < minDist) {
            minDist = dist[i];
            nextNode = i;
        }
    }

    // Llamada recursiva al siguiente nodo
    if (nextNode != -1) {
        findShortest(nextNode, graph, dist, visited);
    }
}

// Función para inicializar el algoritmo de Dijkstra y llamar a la recursiva
void Algorithms::dijkstra(int start, vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);  // Distancia inicial a todos los nodos es infinita
    set<int> visited;          // Conjunto de nodos visitados

    dist[start] = 0;           // La distancia del nodo de inicio es 0
    findShortest(start, graph, dist, visited);

    // Imprimir las distancias
    cout << "Distancias desde el nodo " << start << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            cout << "Nodo " << i << ": INF\n";
        else
            cout << "Nodo " << i << ": " << dist[i] << "\n";
    }
}