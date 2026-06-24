#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

struct WeightedGraph {
    int V;
    vector<vector<pii>> adj;
    WeightedGraph(int V) : V(V), adj(V) {}
    void addEdge(int u, int v, int w) { adj[u].push_back({v, w}); adj[v].push_back({u, w}); }

    void Dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[start] = 0; pq.push({0, start});
        while(!pq.empty()) {
            int d = pq.top().first, u = pq.top().second; pq.pop();
            if(d > dist[u]) continue;
            for(auto& edge : adj[u]) {
                if(dist[u] + edge.second < dist[edge.first]) {
                    dist[edge.first] = dist[u] + edge.second;
                    pq.push({dist[edge.first], edge.first});
                }
            }
        }
        for(int i=0; i<V; ++i) cout << "Jarak terpendek ke " << i << ": " << dist[i] << endl;
    }
};

int main() {
    WeightedGraph wg(8);
    wg.addEdge(0, 1, 4); wg.addEdge(0, 2, 1);
    wg.Dijkstra(0);
    return 0;
}