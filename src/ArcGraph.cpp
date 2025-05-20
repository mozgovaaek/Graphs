#include "../include/ArcGraph.h"

ArcGraph::ArcGraph(const IGraph &other) {
    for (size_t i = 0; i < other.VerticesCount(); ++i) {
        for (const int &v: other.GetNextVertices(i)) {
            _arcs.emplace_back(i, v);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    auto vertices = VerticesCount();
    assert(0 <= from && from < vertices);
    assert(0 <= to && to < vertices);
    _arcs.emplace_back(from, to);
}

size_t ArcGraph::VerticesCount() const {
    std::set<int> vertices;
    for (const arc &a: _arcs) {
        vertices.insert(a.first);
        vertices.insert(a.second);
    }
    return vertices.size();
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < VerticesCount());
    std::vector<int> res;
    for (const arc &a: _arcs) {
        if (a.first == vertex) {
            res.push_back(a.second);
        }
    }
    return res;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < VerticesCount());
    std::vector<int> res;
    for (const arc &a: _arcs) {
        if (a.second == vertex) {
            res.push_back(a.first);
        }
    }
    return res;
}

void ArcGraph::Display() const noexcept {
    size_t i = 0;
    std::cout << "[";
    for (const arc &a: _arcs) {
        std::cout << "(" << a.first << ", " << a.second << ")";
        if (++i < _arcs.size()) std::cout << ", ";
    }
    std::cout << "]\n";
}