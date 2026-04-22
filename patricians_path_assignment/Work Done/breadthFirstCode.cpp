
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; // process current node

        // Go through all neighbors
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 5; // number of nodes (0 to 4)
    vector<vector<int>> graph(n);

    // create edges (undirected)
    graph[0] = {1, 2};   // A connects to B and C
    graph[1] = {0, 3};   // B connects to A and D
    graph[2] = {0, 4};   // C connects to A and E
    graph[3] = {1};      // D connects to B
    graph[4] = {2};      // E connects to C

    cout << "BFS starting from node 0 (A): ";
    bfs(0, graph);
    cout << endl;

    return 0;
}
