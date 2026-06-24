#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int v;
    vector<vector<int>> adj;
    vector<string> users;

public:
    Graph(int ver, vector<string> userNames) {
        v = ver;
        users = userNames;
        adj.resize(v);
    }

    void addEdge(int u, int v_idx) {
        adj[u].push_back(v_idx);
        adj[v_idx].push_back(u);
    }

    void display() {
        for (int i = 0; i < v; i++) {
            cout << users[i] << " berteman dengan: ";
            for (int neighbor : adj[i]) {
                cout << users[neighbor] << " ";
            }
            cout << endl;
        }
    }
};

int main(void) {
    vector<string> names = {"Andi", "Budi", "Citra", "Dina", "Eko"};
    Graph g(5, names);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.display();

    return 0;
}