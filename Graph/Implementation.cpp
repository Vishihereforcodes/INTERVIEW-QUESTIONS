#include <iostream>
#include <unordered_map>
#include<list>
#include<cstring>
using namespace std;

// Template for generic graph
template <typename T>
class Graph
{
    unordered_map<T, list<T> > adjList;  /* Well, it's always good to used "unordered_map" styling Graph instead of "list representation" like given on GFG and other websites..
                                            obviously  hashmap give us a node in constant time (almost). Moreover, Graph representation with unordered_map not always work because it 
                                            distores all the arrangements(random manner), to prove Graph representation with unordered_map doesn't work on kahn's DFS based algorithm..
                                            Hence, it's good to use hashmap but not always. So, to overcome this use MAP representation of graph, however it's it increases the time from constant to Logarithmic, but maintain 
                                            the order of vertices. 
                                            To more icing on cake, Don't you think Vector will be more suitable with unordered_map or map.. it'll gradually decrease the excution time and Cache friendly..
                                            Template are like this:
                                            unordered<(datatype), vector<(Datatype)>> adj;
                                            map<(datatype), vector<(Datatype)>> adj;
                                            Perhaps(most probably), you already knew this :) */
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
