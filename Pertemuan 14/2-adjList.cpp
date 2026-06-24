#include <bits/stdc++.h>
using namespace std;

class gh {
    private:
        int v;
        vector<vector<int>> adj;

    public:
        gh(int ver) {
            v = ver;
            adj.resize(v);
        }

        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void display(void) {
            int i;
            for(i = 0; i < v; i++) {
                cout << i << " -> ";

                for(int n : adj[i]) {
                    cout << n << " ";
                }

                cout << endl;
            }
        }
};

int main(void) {
    gh g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);

    g.display();

    return 0;
}