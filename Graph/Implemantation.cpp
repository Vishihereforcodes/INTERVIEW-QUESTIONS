#include <iostream>
#include <unordered_map>
#include<list>
#include<cstring>
using namespace std;

// Template for generic graph
template <typename T>
class Graph
{
    unordered_map<T, list<T> > adjList;
public:
    Graph() {
    }

    // Assuming Bidiredctional Graph
    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);
        
        // If it is bidirectional
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto row : adjList)
        {
            // Here row will be a pair. Where row.first is representing current vertex & row.second is list of its neighbouring vertices.
            cout << row.first ;

            for (auto x : row.second)
            {
                cout << "-> " << x;
            }
            cout << "\n";
        }
    }
};

int main()
{
    // All T in Graph class will be replaced by string
    Graph<string> g;
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Siachen");
    g.addEdge("Delhi", "Banglore");
    g.addEdge("Delhi", "Agra");

    g.printAdjList();
    return 0;
}
