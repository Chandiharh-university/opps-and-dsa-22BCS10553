#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Structure to represent a graph edge
typedef pair<int, int> Edge; // Pair: (weight, destination)

class Graph {
public:
    int vertices;
    vector<vector<Edge>> adjList;

    Graph(int V) {
        vertices = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({weight, v});
        adjList[v].push_back({weight, u}); // For undirected graph
    }

    void dijkstra(int src) {
        vector<int> dist(vertices, INT_MAX); // Distance array
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Min-heap

        // Start from the source
        dist[src] = 0;
        pq.push({0, src}); // Push (distance, vertex)

        while (!pq.empty()) {
            int u = pq.top().second; // Current vertex
            pq.pop();

            // Explore neighbors of vertex u
            for (auto [weight, v] : adjList[u]) {
                if (dist[u] + weight < dist[v]) { // Relaxation step
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v}); // Push updated distance
                }
            }
        }

        // Print shortest distances
        cout << "Shortest distances from vertex " << src << ":\n";
        for (int i = 0; i < vertices; ++i) {
            cout << "Vertex " << i << " - Distance: " << dist[i] << "\n";
        }
    }
};

int main() {
    int V = 5; // Number of vertices
    Graph g(V);

    // Adding edges to the graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    // Run Dijkstra's Algorithm from source vertex 0
    g.dijkstra(0);

    return 0;
}
