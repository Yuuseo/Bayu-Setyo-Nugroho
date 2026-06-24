#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm> 

using namespace std;

struct Edge {
    int targetNode;
    int weight; 
};

void printPath(int target, const vector<int>& parent) {
    vector<int> path;
    for (int curr = target; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
}

void dijkstra(int source, int destination, int totalNodes, const vector<vector<Edge>>& graph) {
    vector<int> distance(totalNodes, INT_MAX);
    
    vector<int> parent(totalNodes, -1);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        if (currentNode == destination) break;

        if (currentDistance > distance[currentNode]) continue;

        for (const Edge& edge : graph[currentNode]) {
            int neighbor = edge.targetNode;
            int weight = edge.weight;

            if (distance[currentNode] + weight < distance[neighbor]) {
                distance[neighbor] = distance[currentNode] + weight;
                parent[neighbor] = currentNode; // Catat dari mana asal jalur ini
                pq.push({distance[neighbor], neighbor});
            }
        }
    }

    cout << "\n=============================================\n";
    cout << "               HASIL PENCARIAN RUTE          \n";
    cout << "=============================================\n";
    
    if (distance[destination] == INT_MAX) {
        cout << "Tidak ada jalur yang menghubungkan Node [" << source << "] ke Node [" << destination << "].\n";
    } else {
        cout << "Jalur/Rute Terbaik : ";
        printPath(destination, parent);
        cout << "\nTotal Waktu Tempuh : " << distance[destination] << " satuan waktu\n";
    }
    cout << "=============================================\n";
}

int main() {
    int nodes, edges;
    
    cout << "==================================================\n";
    cout << "  PROGRAM DIJKSTRA: HITUNG RUTE & WAKTU TEMPUH\n";
    cout << "==================================================\n";
    
    cout << "Masukkan jumlah total Node/Vertiks: ";
    cin >> nodes;
    cout << "Masukkan jumlah total Edge/Sisi: ";
    cin >> edges;

    vector<vector<Edge>> graph(nodes);

    cout << "\nSilahkan masukkan data Edge dengan format: [Node_Asal] [Node_Tujuan] [Waktu/Bobot]\n";
    cout << "Catatan: Penomoran node dimulai dari 0 sampai " << nodes - 1 << "\n";
    cout << "-------------------------------------------------------------------------\n";
    
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cout << "Edge ke-" << i + 1 << ": ";
        cin >> u >> v >> w;
        
        if (u < 0 || u >= nodes || v < 0 || v >= nodes) {
            cout << "Input salah! Node harus berada di antara 0 sampai " << nodes - 1 << ".\n";
            i--; 
            continue;
        }
        
        graph[u].push_back({v, w}); 
    }

    int source, destination;
    cout << "\nMasukkan Node Awal: ";
    cin >> source;
    cout << "Masukkan Node Tujuan: ";
    cin >> destination;

    if (source >= 0 && source < nodes && destination >= 0 && destination < nodes) {
        dijkstra(source, destination, nodes, graph);
    } else {
        cout << "Error: Node awal atau tujuan tidak valid (di luar batas)!\n";
    }

    return 0;
}
