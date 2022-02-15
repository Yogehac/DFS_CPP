*BFS*

// BFS algorithm in C++

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
    }
    void addEdge(int src, int dest)
    {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }
    void BFS(int startVertex)
    {
        visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;

        list<int> queue;

        visited[startVertex] = true;
        queue.push_back(startVertex);

        list<int>::iterator i;

        while (!queue.empty())
        {
            int currVertex = queue.front();
            cout << "Visited " << currVertex << " ";
            queue.pop_front();

            for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
            {
                int adjVertex = *i;
                if (!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
        }
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

        cout << "Type\n 1. ADD EDGE\n 2. BFS";
        cin >> opt;
    } while (opt == 1);

    g.BFS(0);

    return 0;
}
