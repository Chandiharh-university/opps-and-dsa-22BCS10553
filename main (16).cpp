#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> Edge; // Pair: (weight, vertex)

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

    void primMST() {
        vector<int> key(vertices, INT_MAX);  // Minimum weights to reach vertices
        vector<int> parent(vertices, -1);   // Store MST edges
        vector<bool> inMST(vertices, false); // Track vertices included in MST
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Min-heap

        key[0] = 0; // Start from vertex 0
        pq.push({0, 0}); // Push (weight, vertex)

        while (!pq.empty()) {
            int u = pq.top().second; // Get the vertex with minimum weight
            pq.pop();

            if (inMST[u]) continue; // Skip if already in MST
            inMST[u] = true;

            for (auto [weight, v] : adjList[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        // Print the MST
        cout << "Minimum Spanning Tree (MST):\n";
        for (int v = 1; v < vertices; ++v) {
            cout << parent[v] << " - " << v << " (Weight: " << key[v] << ")\n";
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

    // Run Prim's Algorithm
    g.primMST();

    return 0;
}
