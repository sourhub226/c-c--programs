// C program for Dijkstra's single
// source shortest path algorithm.
// The program is for adjacency matrix
// representation of the graph.
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Number of vertices
// in the graph
#define V 10

// A utility function to find the
// vertex with minimum distance
// value, from the set of vertices
// not yet included in shortest
// path tree
int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false &&
            dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print shortest
// path from source to j
// using parent array
void printPath(int parent[], int j)
{

    // Base Case : If j is source
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf("-> %c ", j + 65);
}

// A utility function to print
// the constructed distance
// array
int printSolution(int dist[], int n,
                  int parent[])
{
    int src = 0;
    printf("Vertex\t\tDistance\tPath");
    for (int i = 1; i < V; i++)
    {
        printf("\n%c -> %c\t\t%d\t\t%c ",
               src + 65, i + 65, dist[i], src + 65);
        printPath(parent, i);
    }
}

// Funtion that implements Dijkstra's
// single source shortest path
// algorithm for a graph represented
// using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{

    // The output array. dist[i]
    // will hold the shortest
    // distance from src to i
    int dist[V];

    // sptSet[i] will true if vertex
    // i is included / in shortest
    // path tree or shortest distance
    // from src to i is finalized
    bool sptSet[V];

    // Parent array to store
    // shortest path tree
    int parent[V];

    // Initialize all distances as
    // INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex
    // from itself is always 0
    dist[src] = 0;

    // Find shortest path
    // for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance
        // vertex from the set of
        // vertices not yet processed.
        // u is always equal to src
        // in first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex
        // as processed
        sptSet[u] = true;

        // Update dist value of the
        // adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is
            // not in sptSet, there is
            // an edge from u to v, and
            // total weight of path from
            // src to v through u is smaller
            // than current value of
            // dist[v]
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // print the constructed
    // distance array
    printSolution(dist, V, parent);
}

// Driver Code
int main()
{
    // Let us create the example
    // graph discussed above
    int graph[V][V] =
        //A  B  C  D  E  F  G  H  I  J
        {{0, 0, 2, 0, 6, 0, 0, 0, 0, 1},  //A
         {0, 0, 5, 2, 0, 0, 0, 0, 4, 0},  //B
         {2, 5, 0, 0, 0, 0, 0, 0, 7, 0},  //C
         {0, 2, 0, 0, 0, 3, 0, 0, 0, 0},  //D
         {6, 0, 0, 0, 0, 0, 0, 5, 0, 0},  //E
         {0, 0, 0, 3, 0, 0, 3, 0, 1, 0},  //F
         {0, 0, 0, 0, 0, 3, 0, 4, 8, 0},  //G
         {0, 0, 0, 0, 5, 0, 4, 0, 0, 3},  //H
         {0, 4, 7, 0, 0, 1, 8, 0, 0, 6},  //I
         {1, 0, 0, 0, 0, 0, 0, 3, 6, 0}}; //J

    dijkstra(graph, 0);
    return 0;
}