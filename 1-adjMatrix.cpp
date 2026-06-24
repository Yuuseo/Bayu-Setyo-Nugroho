#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
        int mat[100][100];
        int ver;

    public:
        Graph(int v) {
            ver = v;
            
            int i, j;
            for(i = 0; i < v; i++) {
                for(j = 0; j < v; j++) {
                    mat[i][j] = 0;
                }
            }
        }

        void addEdge(int u, int v) {
            mat[u][v] = 1;
            mat[v][u] = 1;
        }

        void display(void) {
            cout << "Adjacency Matrix" << endl;

            int i, j;
            for(i = 0; i < ver; i++) {
                for(j = 0; j < ver; j++) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(void) {
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);

    g.display();

    return 0;
}