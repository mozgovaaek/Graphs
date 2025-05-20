#include "../include/SetGraph.h"

SetGraph::SetGraph(int size) : _adjacencyMatrix(size) {}

SetGraph::SetGraph(const IGraph &graph) : _adjacencyMatrix(graph.VerticesCount()) {
    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        for (const auto& v : graph.GetNextVertices(i)) {
            _adjacencyMatrix[i].insert(v);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < _adjacencyMatrix.size());
    assert(0 <= to && to < _adjacencyMatrix.size());
    _adjacencyMatrix[from].insert(to);
}

size_t SetGraph::VerticesCount() const {
    return _adjacencyMatrix.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < _adjacencyMatrix.size());
    std::vector<int> res;
    for (const auto& v : _adjacencyMatrix[vertex]) res.emplace_back(v);
    return res;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < _adjacencyMatrix.size());
    std::vector<int> res;
    for (size_t i = 0; i < _adjacencyMatrix.size(); ++i) {
        if (_adjacencyMatrix[i].contains(vertex)) {
            res.emplace_back(i);
        }
    }
    return res;
}

void SetGraph::Display() const noexcept {
    for (size_t i = 0; i < _adjacencyMatrix.size(); ++i) {
        std::cout << i << ": ";
        for (const auto& x : _adjacencyMatrix[i]) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
}
