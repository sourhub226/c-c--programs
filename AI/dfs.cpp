#include <iostream>
#include <vector>
using namespace std;

// Data structure to store a graph edge
struct Edge
{
    int src, dest;
};

// vector to store the complete path between source and destination
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
        // resize the vector to hold `N` elements of type `vector<int>`
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

// Utility function to print a stack
void print_stack()
{
    cout << "stack = [";
    for (auto i = path.begin(); i != path.end(); ++i)
        cout << *i << ",";
    if (!path.empty())
        cout << "\b";
    cout << "]";
}

// Function to perform DFS traversal in a directed graph to find the
// complete path between source and destination vertices
bool isConnected(Graph const &graph, int src, int dest,
                 vector<bool> &discovered)
{
    // mark the current node as discovered
    discovered[src] = true;

    // include the current node in the path
    path.push_back(src);
    cout << "\nPush " << src << ", ";
    print_stack();
    // if destination vertex is found
    if (src == dest)
    {
        cout << "\nGoal node found";
        return true;
    }

    // do for every edge `src —> i`
    for (int i : graph.adjList[src])
    {
        // if `u` is not yet discovered
        if (!discovered[i])
        {
            // return true if the destination is found
            if (isConnected(graph, i, dest, discovered))
            {
                return true;
            }
        }
    }

    // backtrack: remove the current node from the path
    path.pop_back();
    cout << "\nBacktracking...";
    cout << "\nPop " << src << ", ";
    print_stack();
    // return false if destination vertex is not reachable from src
    return false;
}

int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {0, 2}, {0, 1}, {1, 2}, {1, 5}, {5, 7}, {2, 3}, {3, 4}, {3, 6}, {4, 6}
    };

    // total number of nodes in the graph (labeled from 0 to `N-1`)
    int N = 8;

    // source and destination vertex
    int src = 0, dest = 7;

    // build a graph from the given edges
    Graph graph(edges, N);

    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N);

    // perform DFS traversal from the source vertex to check the connectivity
    // and store path from the source vertex to the destination vertex
    if (isConnected(graph, src, dest, discovered))
    {
        cout << "\n\nA path exists from node " << src << " to node " << dest;
        cout << "\nThe complete solution sequence is ";
        print_path();
    }
    else
    {
        cout << "\n\nNo path exists between vertices " << src << " and " << dest;
    }

    return 0;
}