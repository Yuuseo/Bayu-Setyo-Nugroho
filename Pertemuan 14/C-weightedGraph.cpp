#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

struct WeightedGraph {
    int V;
    vector<vector<pii>> adj;
    WeightedGraph(int V) : V(V), adj(V) {}
    void addEdge(int u, int v, int w) { adj[u].push_back({v, w}); adj[v].push_back({u, w}); }
    
    void print() {
        for(int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": ";
            for(auto& edge : adj[i]) cout << "(" << edge.first << ",w=" << edge.second << ") ";
            cout << endl;
        }
    }
};

int main() {
    WeightedGraph wg(8);
    wg.addEdge(0, 1, 5);
    wg.print();
    return 0;
}