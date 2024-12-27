#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
void dijkstra(const vector<vector<pair<int, int>>> &graph, int source) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    distance[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        int dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (visited[current]) continue;
        visited[current] = true;
        for (const auto &neighbor : graph[current]) {
            int next = neighbor.first;
            int weight = neighbor.second;

            if (!visited[next] && distance[current] + weight < distance[next]) {
                distance[next] = distance[current] + weight;
                pq.push({distance[next], next});
            }
        }
    }
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << (distance[i] == INT_MAX ? -1 : distance[i]) << endl;
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
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    dijkstra(graph, source);
    return 0;
}
