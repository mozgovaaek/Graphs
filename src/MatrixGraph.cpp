#include "../include/MatrixGraph.h"

MatrixGraph::MatrixGraph(int size) : _matrix(size, std::vector<int>(size, 0)) {}

MatrixGraph::MatrixGraph(const IGraph &graph) :
_matrix(graph.VerticesCount(), std::vector<int>(graph.VerticesCount(), 0)) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (const auto& v : graph.GetNextVertices(i)) {
            _matrix[i][v] = 1;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < _matrix.size());
    assert(0 <= to && to < _matrix.size());
    _matrix[from][to] = 1;
}

size_t MatrixGraph::VerticesCount() const {
    return _matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < _matrix.size());
    std::vector<int> res;
    for (size_t i = 0; i < _matrix.size(); ++i) {
        if (_matrix[vertex][i] != 0) {
            res.push_back(i);
        }
    }
    return res;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < _matrix.size());
    std::vector<int> res;
    for (size_t i = 0; i < _matrix.size(); ++i) {
        if (_matrix[i][vertex] != 0) {
            res.push_back(i);
        }
    }
    return res;
}

void MatrixGraph::Display() const noexcept {
    for (size_t i = 0; i < _matrix.size(); ++i) {
        for (size_t j = 0; j < _matrix[i].size(); ++j) {
            std::cout << _matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}