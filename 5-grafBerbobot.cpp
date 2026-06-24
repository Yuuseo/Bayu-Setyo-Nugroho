#include <bits/stdc++.h>
using namespace std;

class gh {
    private:
        map<char, vector<pair<char, int>>> adj;

    public:
        gh(int ver) {}

        void add(char u, char v, int w) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        void display() {
            for(auto const& [vertex, edges] : adj) {
                cout << "Vertex " << vertex << ": ";
                for(auto const& edge : edges) {
                    cout << "(" << edge.first << "," << edge.second << ") ";
                }
                cout << endl;
            }
        }
};

int main(void) {
    gh g(4);

    g.add('A', 'B', 5);
    g.add('B', 'D', 3);
    g.add('D', 'C', 1);
    g.add('C', 'A', 2);

    g.display();

    return 0;
}