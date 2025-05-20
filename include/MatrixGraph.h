#ifndef IGRAPH_MATRIXGRAPH_H
#define IGRAPH_MATRIXGRAPH_H

#include "IGraph.h"
#include <iostream>
#include <cassert>

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(int size);

    ~MatrixGraph() = default;

    explicit MatrixGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;

    size_t VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

    void Display() const noexcept override;

private:
    std::vector<std::vector<int>> _matrix;
};


#endif //IGRAPH_MATRIXGRAPH_H
