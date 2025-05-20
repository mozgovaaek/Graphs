#ifndef IGRAPH_ALGORITHMS_H
#define IGRAPH_ALGORITHMS_H

#include "IGraph.h"
#include <vector>
#include <functional>
#include <queue>
#include <deque>

namespace cgraphs {
    void BFS(const IGraph &graph,
             int vertex, std::vector<bool> &visited, const std::function<void(const int &vertex)> &f);

    void mainBFS(const IGraph &graph, const std::function<void(const int &vertex)> &f);

    void DFS(const IGraph &graph,
             int vertex, std::vector<bool> &visited, const std::function<void(const int &vertex)> &f);

    void mainDFS(const IGraph &graph, const std::function<void(const int &vertex)> &f);

    void topologicalSortInternal(const IGraph &graph, int vertex, std::vector<bool> &visited, std::deque<int> &sorted);

    std::deque<int> topologicalSort(const IGraph &graph);

    std::vector<int> dijkstra(const IGraph& graph, int start);
}
#endif //IGRAPH_ALGORITHMS_H
