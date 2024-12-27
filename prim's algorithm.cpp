#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
void prim(const vector<vector<pair<int, int>>> &graph) {
    int n = graph.size();
    vector<bool> inMST(n, false);      
    vector<int> key(n, INT_MAX);      
    vector<int> parent(n, -1);       
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
    key[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        for (const auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    cout << "Edge\tWeight\n";
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "\t" << key[i] << endl;
        }
    }
}
int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    vector<vector<pair<int, int>>> graph(n);
    cout << "Enter edges (format: u v w where u and v are vertices and w is the weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    prim(graph);
    return 0;
}
