#include "dijkstras.h"
#include <functional>


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int nVert = G.numVertices;
    vector<int> dist(nVert, INF);
    previous.assign(nVert, -1);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source});

    while(!minHeap.empty()){
        auto[distance, i] = minHeap.top();
        minHeap.pop();

        if(distance > dist[i]) continue;

        for(const Edge& edge : G[i]){
            int v = edge.dst, weight = edge.weight;
            if(dist[i] + weight < dist[v]){
                dist[v] = dist[i] + weight;
                previous[v] = i;
                minHeap.push({dist[v], v});
            }
        }
    }

    return dist;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    vector<int> path;
    for(int i = destination; i != -1; i = previous[i]){
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& path, int total) {
    for(int i = 0; i < path.size(); ++i){
        cout << path[i] << " ";
    }
    cout << "\nTotal cost is " << total << endl;
}
