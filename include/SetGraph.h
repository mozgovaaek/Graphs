#ifndef IGRAPH_SETGRAPH_H
#define IGRAPH_SETGRAPH_H

#include "IGraph.h"
#include <iostream>
#include <cassert>
#include <set>
#include <vector>

class SetGraph : public IGraph {
public:
    explicit SetGraph(int size);

    explicit SetGraph(const IGraph& graph);

    ~SetGraph() = default;

    void AddEdge(int from, int to) override;

    size_t VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

    void Display() const noexcept override;
private:
    std::vector< std::set<int> > _adjacencyMatrix;
};


#endif //IGRAPH_SETGRAPH_H
