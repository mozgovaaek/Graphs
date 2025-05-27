#ifndef IGRAPH_IGRAPH_H
#define IGRAPH_IGRAPH_H

#include <vector>

namespace cgraphs {
/**
 * Абстрактный класс Графа,
 * необходимый для имплементации различных вариантов представления графа в памяти компьютера
 * и последующей работы с алгоритмами на графах.
 */
    struct IGraph {
        virtual ~IGraph() {}

        /**
         * Добавление ребра в граф.
         * @param from[in]: откуда идет путь.
         * @param to[out]: куда идет путь.
         */
        virtual void AddEdge(int from, int to) = 0;

        /**
         * Количество вершин в графе.
         * @return целое число вершин в графе.
         */
        virtual size_t VerticesCount() const = 0;

        /**
         * Получение вектора вершин, куда можно попасть из заданной.
         * @param vertex[in]: откуда идём.
         * @return вектор вершин, куда можно прийти из vertex.
         */
        virtual std::vector<int> GetNextVertices(int vertex) const = 0;

        /**
         * Получение вектора вершин, откуда можно попасть в заданную.
         * @param vertex[in]: куда идём.
         * @return вектор вершин, откуда можно попасть в vertex.
         */
        virtual std::vector<int> GetPrevVertices(int vertex) const = 0;

        /**
         * Графическое отображение графа.
         */
        virtual void Display() const noexcept {}
    };
}
#endif