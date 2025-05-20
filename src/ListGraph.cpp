#include "../include/ListGraph.h"

ListGraph::ListGraph(int size) : adjacencyLists(size) {}

ListGraph::ListGraph(const IGraph &graph) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        adjacencyLists[i] = graph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjacencyLists.size());
    assert(0 <= to && to < adjacencyLists.size());
    adjacencyLists[from].
            push_back(to);
}

size_t ListGraph::VerticesCount() const {
    return adjacencyLists.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyLists.size());
    return adjacencyLists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyLists.size());
    std::vector<int> prevVertices;

    for (int from = 0; from < adjacencyLists.size(); ++from) {
        for (const auto &x: adjacencyLists[from]) {
            if (x == vertex) {
                prevVertices.push_back(from);
            }
        }
    }
    return prevVertices;
}

void ListGraph::Display() const noexcept {
    for (size_t i = 0; i < adjacencyLists.size(); ++i) {
        std::cout << i << ": ";
        for (const int& j : adjacencyLists[i]) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }
}