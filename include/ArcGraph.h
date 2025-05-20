#ifndef IGRAPH_ARCGRAPH_H
#define IGRAPH_ARCGRAPH_H

#include "IGraph.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <set>

class ArcGraph : public IGraph {
public:
    typedef std::pair<int, int> arc;

    ArcGraph() = default;

    ~ArcGraph() = default;

    explicit ArcGraph(const IGraph &other);

    void AddEdge(int from, int to) override;

    size_t VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

    void Display() const noexcept override;

private:
    std::vector<arc> _arcs;
};


#endif //IGRAPH_ARCGRAPH_H