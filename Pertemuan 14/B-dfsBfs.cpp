#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true; q.push(start);
        cout << "BFS: ";
        while(!q.empty()) {
            int u = q.front(); q.pop(); cout << u << " ";
            for(int v : adj[u]) if(!visited[v]) { visited[v]=true; q.push(v); }
        }
        cout << endl;
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);
        cout << "DFS: ";
        while(!s.empty()) {
            int u = s.top(); s.pop();
            if(!visited[u]) { visited[u]=true; cout << u << " "; }
            for(int v : adj[u]) if(!visited[v]) s.push(v);
        }
        cout << endl;
    }
};

int main() {
    Graph g(8);
    g.addEdge(0, 1); g.addEdge(0, 2); g.addEdge(1, 3);
    g.BFS(0);
    g.DFS(0);
    return 0;
}