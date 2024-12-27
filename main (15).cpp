#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int V) {
        vertices = V;
        adjList.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int v, int u) {
        adjList[v].push_back(u);
        adjList[u].push_back(v); // For undirected graph
    }

    // BFS Algorithm
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from vertex " << start << ": ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            // Visit all the adjacent vertices
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // DFS Algorithm (using recursion)
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS starting from vertex " << start << ": ";
        DFSHelper(start, visited);
        cout << endl;
    }

private:
    // Helper function for DFS (recursive)
    void DFSHelper(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSHelper(neighbor, visited);
            }
        }
    }
};

int main() {
    int V = 6; // Number of vertices
    Graph g(V);

    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // BFS starting from vertex 0
    g.BFS(0);

    // DFS starting from vertex 0
    g.DFS(0);

    return 0;
}
