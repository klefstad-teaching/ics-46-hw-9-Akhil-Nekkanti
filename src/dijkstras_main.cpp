#include "dijkstras.h"

int main() {
    Graph G;
    file_to_graph("src/small.txt", G);

    int source = 0, destination = 1;
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    
    vector<int> path = extract_shortest_path(distances, previous, destination);
    print_path(path, distances[destination]);

    return 0;
}
