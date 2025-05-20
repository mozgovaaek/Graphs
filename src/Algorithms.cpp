#include "../include/Algorithms.h"

void BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void (const int& vertex)> &f) {
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        f(currentVertex);
        for (int nextVertex : graph.GetNextVertices(currentVertex)) {
            if (!visited[nextVertex]) {
                visited[nextVertex] = true;
                q.push(nextVertex);
            }
        }
    }
}

void mainBFS(const IGraph& graph, const std::function<void (const int& vertex)>& f) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            BFS(graph, i, visited, f);
        }
    }
}

void DFS(const IGraph& graph, int vertex, std::vector<bool>&visited, const std::function<void (const int& vertex)>&f) {
    visited[vertex] = true;
    f(vertex);
    for (int nextVertex : graph.GetNextVertices(vertex)) {
        if (!visited[nextVertex]) {
            DFS(graph, nextVertex, visited, f);
        }
    }
}

void mainDFS(const IGraph& graph, const std::function<void (const int& vertex)>& f) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited, f);
        }
    }
}

void topologicalSortInternal(const IGraph& graph, int vertex, std::vector<bool>& visited, std::deque<int>& sorted) {
    visited[vertex] = true;

    for (int nextVertex : graph.GetNextVertices(vertex)) {
        if (!visited[nextVertex]) {
            topologicalSortInternal(graph, nextVertex, visited, sorted);
        }
    }
    sorted.push_front(vertex);
}

std::deque<int> topologicalSort(const IGraph& graph) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::deque<int> sorted;
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            topologicalSortInternal(graph, i, visited, sorted);
        }
    }
    return sorted;
}