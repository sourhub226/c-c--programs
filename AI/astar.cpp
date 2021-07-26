// to obtain the sequence of nodes expanded if an A* Search was applied following.
/* 
    edge        cost of edge
    S-A             3  
    S-C             4  
    A-C             5  
    A-B             4  
    C-D             3
    D-E             2  
    E-G             3  
    B-D             4 
    B-G             5  
    B-F             4  
*/
// Assume that the heuristic estimation of distances from each of the states to G are: (G is a goal state)
/* 
    S: 18.5
    A: 10.5
    C: 9.2
    D: 6.2
    E: 4.5
    B: 6
    F: infinity 
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#define INF 100000
using namespace std;

typedef pair<char, char> edgePair;
typedef struct node
{
    char name;
    char parent;
    float f;
    float g;
    bool operator<(const struct node &rhs) const
    {
        return f < rhs.f;
    }

} node;

vector<node> open_nodes;
map<char, bool> closed_nodes;
vector<node> path;
map<char, list<char>> edges;
map<edgePair, float> weights;
map<char, float> hCost;

bool edgeExists(char src, char dst)
{
    auto end = edges[src].end();
    auto start = edges[src].begin();
    return find(start, end, dst) != end;
}
void addEdge(char src, char dst, float weight, float h_src, float h_dst)
{
    //Check if edge already added
    if (edgeExists(src, dst))
        return;
    //Add to edges list
    edges[src].push_back(dst);
    edges[dst].push_back(src);
    //Add to weights list
    weights[edgePair(src, dst)] = weight;
    weights[edgePair(dst, src)] = weight;
    //Add to hCost array
    if (src != 'G')
        hCost[src] = h_src;
    if (dst != 'G')
        hCost[dst] = h_dst;
}

void addNode(vector<node> &l, node &n)
{
    l.insert(upper_bound(l.begin(), l.end(), n), n);
}

vector<node>::iterator findNode(vector<node> &l, char name)
{
    vector<node>::iterator i;
    for (i = l.begin(); i != l.end(); i++)
    {
        if ((*i).name == name)
            break;
    }
    return i;
}

void updateNode(vector<node> &l, char name, char parent, float f, float g)
{
    auto i = findNode(l, name);
    node n = node{
        name : name,
        parent : parent,
        f : f,
        g : g,
    };
    if (i == l.end())
    {
        addNode(l, n);
        return;
    }
    else if (f < (*i).f)
    {
        l.erase(i);
        addNode(l, n);
    }
    return;
}

float tracePath(char last)
{
    vector<node>::iterator it;
    it = findNode(path, last);
    if ((*it).parent == '-')
    {
        cout << last;
        return 0;
    }
    float cost = tracePath((*it).parent);
    cout << " -> " << last;
    return cost + weights[edgePair((*it).parent, last)];
}

void aStarSearch(char src, char dst)
{
    for (auto i : edges)
        closed_nodes[i.first] = false;

    node start = node{
        name : src,
        parent : '-',
        f : 0,
        g : 0,
    };

    addNode(open_nodes, start);
    while (open_nodes.size() != 0)
    {
        node curr = *open_nodes.begin();
        open_nodes.erase(open_nodes.begin());
        closed_nodes[curr.name] = true;
        path.push_back(curr);
        float f, g, h;
        for (auto i : edges[curr.name])
        {
            if (i == dst)
            {
                cout << "Optimal path: ";
                float costAtEnd = weights[edgePair(curr.name, dst)];
                float cost = tracePath(curr.name) + costAtEnd;
                cout << " -> " << dst << endl;
                cout << "Total cost = " << cost << endl;
                return;
            }
            if (closed_nodes[i])
                continue;

            g = curr.g + weights[edgePair(curr.name, i)];
            h = hCost[i];
            f = g + hCost[i];
            updateNode(open_nodes, i, curr.name, f, g);
        }
    }
    cout << "Failed" << endl;
}

int main()
{
    //Create weighted graph
    addEdge('S', 'A', 3, 18.5, 10.5);
    addEdge('S', 'C', 4, 18.5, 9.2);
    addEdge('A', 'C', 5, 10.5, 9.2);
    addEdge('A', 'B', 4, 10.5, 6);
    addEdge('C', 'D', 3, 9.2, 6.2);
    addEdge('D', 'E', 2, 6.2, 4.5);
    addEdge('E', 'G', 3, 4.5, 0);
    addEdge('B', 'D', 4, 6, 6.2);
    addEdge('B', 'G', 5, 6, 0);
    addEdge('B', 'F', 4, 6, INF);

    aStarSearch('S', 'G');
}
