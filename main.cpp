#include <iostream>
#include "include/MatrixGraph.h"
#include "include/Algorithms.h"

void print(const int &vertex) {
    std::cout << vertex << '\n';
}

int main() {
    cgraphs::MatrixGraph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 3);
    cgraphs::mainBFS(g, print);
    return 0;
}