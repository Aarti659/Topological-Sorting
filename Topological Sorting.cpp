#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int source, destination;
};
class Graph
{
public:

    vector<vector<int>> adjList;
     Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
        for (auto &edge: edges) {
            adjList[edge.source].push_back(edge.destination);
        }
    }
};

void DFS(Graph const &graph, int v, vector<bool>
    &discovered, vector<int> &depart, int &Time)
{
    discovered[v] = true;
     Time++;

    for (int u: graph.adjList[v])
    {

        if (!discovered[u]) {
            DFS(graph, u, discovered, depart, Time);
        }
    }
     depart[Time] = v;
    Time++;
}
 void Topological_Sorting(Graph const &graph, int n)
{
    vector<int> depart(2*n, -1);

    vector<bool> discovered(n);
    int Time = 0;
    for (int i = 0; i < n; i++)
    {
        if (!discovered[i]) {
            DFS(graph, i, discovered, depart, Time);
        }
    }
     for (int i = 2*n - 1; i >= 0; i--)
    {
        if (depart[i] != -1) {
            cout << depart[i] << " ";
        }
    }
}
 int main()
{
       vector<Edge> edges =
    {
        {0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4}, {5, 1}, {7, 0}, {7, 1}
    };

    int n = 8;
     Graph graph(edges, n);
     Topological_Sorting(graph, n);
    return 0;
}

