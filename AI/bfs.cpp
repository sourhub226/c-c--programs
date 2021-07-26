#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Data structure to store a graph edge
struct Edge
{
    int src, dest;
};

// Data structure to store solution path
vector<int> path;

// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list in C++
    vector<vector<int>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements each of type `vector<int>`
        adjList.resize(N);

        // add edges to the directed graph
        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

// Utility function to print the path
void print_path()
{
    for (auto i = path.begin(); i != path.end(); ++i)
        cout << *i << "->";
    cout << "\b \b\b ";
}

// Utility function to print a queue
void print_queue(queue<int> myqueue)
{
    cout << "queue = [";
    while (!myqueue.empty())
    {
        cout << myqueue.front() << ",";
        myqueue.pop();
        if (myqueue.empty())
            cout << "\b";
    }
    cout << "]";
}

// Function to perform BFS traversal from a given source vertex in a graph to
// determine if a destination vertex is reachable from the source or not
bool isConnected(Graph const &graph, int src, int dest,
                 vector<bool> &discovered)
{
    // create a queue for doing BFS
    queue<int> q;

    // mark the source vertex as discovered
    discovered[src] = true;

    // enqueue source vertex
    q.push(src);
    cout << "\nPush " << src << ", ";
    print_queue(q);

    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and print it
        int v = q.front();
        q.pop();
        cout << "\nPop " << v << ", ";
        print_queue(q);
        path.push_back(v);

        // if destination vertex is found
        if (v == dest)
        {
            cout << "\nGoal node found";
            return true;
        }

        // do for every edge `v —> u`
        for (int u : graph.adjList[v])
        {
            if (!discovered[u])
            {
                // mark it as discovered and enqueue it
                discovered[u] = true;
                q.push(u);
                cout << "\nPush " << u << ", ";
                print_queue(q);
            }
        }
    }

    return false;
}

int main()
{
    // vector of graph edges as per the diagram
    vector<Edge> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 5}, {5, 7}, {2, 3}, {6, 7}, {3, 4}, {3, 6}, {4, 6}
    };

    // total number of nodes in the graph (labeled from 0 to `N-1`)
    int N = 8;

    // source and destination vertex
    int src = 0, dest = 7;

    // build a graph from the given edges
    Graph graph(edges, N);

    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N);

    // perform BFS traversal from the source vertex to check the connectivity
    if (isConnected(graph, src, dest, discovered))
    {
        cout << "\n\nA path exists from node " << src << " to node " << dest;
        cout << "\nThe complete solution sequence is ";
        print_path();
    }
    else
    {
        cout << "\n\nNo path exists between nodes " << src << " and " << dest;
    }

    return 0;
}