#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }
    void printGraph() {
        for(int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": ";
            for(int v : adj[i]) cout << v << " ";
            cout << endl;
        }
    }
};

int main(void) {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 0);
    g.printGraph();
    return 0;
}