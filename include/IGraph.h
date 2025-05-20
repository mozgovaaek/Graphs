#ifndef IGRAPH_IGRAPH_H
#define IGRAPH_IGRAPH_H

#include <vector>

struct IGraph {
    virtual ~IGraph() {}

    virtual void AddEdge(int from, int to) = 0;
    virtual size_t VerticesCount() const = 0;
    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
    virtual void Display() const noexcept {}
};

#endif