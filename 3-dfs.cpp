#include <bits/stdc++.h>
using namespace std;

class gh {
    private:
        int v;
        vector<vector<int>> adj;
        vector<bool> vis;
    
    public:
        gh(int ver) {
            v = ver;
            adj.resize(v);
            vis.resize(v, false);
        }

        void add(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void dfs(int v) {
            vis[v] = true;
            cout << v << " ";

            for(int u : adj[v]) {
                if(!vis[u]) {
                    dfs(u);
                }
            }
        }
};

int main(void) {
    gh g(5);

    g.add(0,1);
    g.add(0,2);
    g.add(1,3);
    g.add(2,4);

    cout << "DFS: ";
    g.dfs(0);

    return 0;
}