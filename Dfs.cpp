*DFS*

// DFS algorithm in C++

#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
        visited = new bool[vertices];
    }
    void addEdge(int src, int dest)
    {
        adjLists[src].push_front(dest);
    }
    void DFS(int vertex)
    {
        visited[vertex] = true;
        list<int> adjList = adjLists[vertex];

        cout << vertex << " ";

        list<int>::iterator i;
        for (i = adjList.begin(); i != adjList.end(); ++i)
            if (!visited[*i])
                DFS(*i);
    }
};

int main()
{
    int v, s, d, opt;
    cout << "Enter number of vertices : ";
    cin >> v;
    Graph g(v);

    do
    {
        cout << "Enter source : ";
        cin >> s;
        cout << "Enter destination : ";
        cin >> d;
        if (s != d && s < v && d < v)
        {

            g.addEdge(s, d);
        }
        else
            cout << "Invalid edge!\n";

        cout << "Type\n 1. ADD EDGE\n 2. DFS";
        cin >> opt;
    } while (opt == 1);

    g.DFS(0);

    return 0;
}
