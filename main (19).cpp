#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

class Graph {
public:
    int vertices, edges;
    vector<Edge> edgeList;

    Graph(int V, int E) {
        vertices = V;
        edges = E;
    }

    void addEdge(int src, int dest, int weight) {
        edgeList.push_back({src, dest, weight});
    }

    // Find the subset of an element (uses path compression)
    int find(Subset subsets[], int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }

    // Perform union of two subsets (by rank)
    void Union(Subset subsets[], int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        if (subsets[xroot].rank < subsets[yroot].rank) {
            subsets[xroot].parent = yroot;
        } else if (subsets[xroot].rank > subsets[yroot].rank) {
            subsets[yroot].parent = xroot;
        } else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    // Kruskal's Algorithm to find MST
    void kruskalMST() {
        vector<Edge> result; // Store the MST
        int e = 0;           // Count edges in MST

        // Step 1: Sort edges by weight
        sort(edgeList.begin(), edgeList.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        // Create subsets for union-find
        Subset* subsets = new Subset[vertices];
        for (int v = 0; v < vertices; ++v) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }

        // Step 2: Pick edges until MST has V-1 edges
        for (auto edge : edgeList) {
            if (e == vertices - 1) break;

            int x = find(subsets, edge.src);
            int y = find(subsets, edge.dest);

            // If x and y are in different subsets, include the edge in MST
            if (x != y) {
                result.push_back(edge);
                Union(subsets, x, y);
                e++;
            }
        }

        // Print the MST
        cout << "Minimum Spanning Tree (MST):\n";
        int totalWeight = 0;
        for (auto edge : result) {
            cout << edge.src << " - " << edge.dest << " (Weight: " << edge.weight << ")\n";
            totalWeight += edge.weight;
        }
        cout << "Total Weight of MST: " << totalWeight << endl;

        delete[] subsets;
    }
};

int main() {
    int V = 6; // Number of vertices
    int E = 9; // Number of edges
    Graph g(V, E);

    // Adding edges to the graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);

    // Run Kruskal's Algorithm
    g.kruskalMST();

    return 0;
}
