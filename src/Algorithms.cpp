#include "../include/Algorithms.h"

namespace cgraphs {

    void
    BFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(const int &vertex)> &f) {
        std::queue<int> q;
        q.push(vertex);
        visited[vertex] = true;
        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            f(currentVertex);
            for (int nextVertex: graph.GetNextVertices(currentVertex)) {
                if (!visited[nextVertex]) {
                    visited[nextVertex] = true;
                    q.push(nextVertex);
                }
            }
        }
    }

    void mainBFS(const IGraph &graph, const std::function<void(const int &vertex)> &f) {
        std::vector<bool> visited(graph.VerticesCount(), false);
        for (int i = 0; i < graph.VerticesCount(); ++i) {
            if (!visited[i]) {
                BFS(graph, i, visited, f);
            }
        }
    }

    void
    DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(const int &vertex)> &f) {
        visited[vertex] = true;
        f(vertex);
        for (int nextVertex: graph.GetNextVertices(vertex)) {
            if (!visited[nextVertex]) {
                DFS(graph, nextVertex, visited, f);
            }
        }
    }

    void mainDFS(const IGraph &graph, const std::function<void(const int &vertex)> &f) {
        std::vector<bool> visited(graph.VerticesCount(), false);
        for (int i = 0; i < graph.VerticesCount(); ++i) {
            if (!visited[i]) {
                DFS(graph, i, visited, f);
            }
        }
    }

    void topologicalSortInternal(const IGraph &graph, int vertex, std::vector<bool> &visited, std::deque<int> &sorted) {
        visited[vertex] = true;

        for (int nextVertex: graph.GetNextVertices(vertex)) {
            if (!visited[nextVertex]) {
                topologicalSortInternal(graph, nextVertex, visited, sorted);
            }
        }
        sorted.push_front(vertex);
    }

    std::deque<int> topologicalSort(const IGraph &graph) {
        std::vector<bool> visited(graph.VerticesCount(), false);
        std::deque<int> sorted;
        for (int i = 0; i < graph.VerticesCount(); ++i) {
            if (!visited[i]) {
                topologicalSortInternal(graph, i, visited, sorted);
            }
        }
        return sorted;
    }

    std::vector<int> dijkstra(const IGraph& graph, int start) {
        std::vector<int> dist(graph.VerticesCount(), std::numeric_limits<int>::max());
        std::vector<bool> visited(graph.VerticesCount(), false);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

        dist[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (const auto& v : graph.GetNextVertices(u)) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    }
}
