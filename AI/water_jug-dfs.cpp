//  to solve water jug problem using DFS technique.
#include <iostream>
#include <stack>
#include <map>
using namespace std;

// Representation of a state (x, y)
// x and y are the amounts of water in litres in the two jugs respectively
struct state
{
    int x, y;

    // Used by map to efficiently implement lookup of seen states
    bool operator<(const state &that) const
    {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }
};

// Capacities of the two jugs respectively and the target amount
int capacity_x, capacity_y, target;

void dfs(state start, stack<pair<state, int>> &path)
{
    stack<state> s;
    state goal = (state){-1, -1};

    // Stores seen states so that they are not revisited and
    // maintains their parent states for finding a path through
    // the state space
    // Mapping from a state to its parent state and rule no. that
    // led to this state
    map<state, pair<state, int>> parentOf;

    s.push(start);
    parentOf[start] = make_pair(start, 0);

    while (!s.empty())
    {
        // Get the state at the front of the stack
        state top = s.top();
        s.pop();

        // If the target state has been found, break
        if (top.x == target || top.y == target)
        {
            goal = top;
            break;
        }

        // Find the successors of this state
        // This step uses production rules to produce successors of the current state
        // while pruning away branches which have been seen before

        // Rule 1: (x, y) -> (capacity_x, y) if x < capacity_x
        // Fill the first jug
        if (top.x < capacity_x)
        {
            state child = (state){capacity_x, top.y};
            // Consider this state for visiting only if it has not been visited before
            if (parentOf.find(child) == parentOf.end())
            {
                s.push(child);
                parentOf[child] = make_pair(top, 1);
            }
        }

        // Rule 2: (x, y) -> (x, capacity_y) if y < capacity_y
        // Fill the second jug
        if (top.y < capacity_y)
        {
            state child = (state){top.x, capacity_y};
            if (parentOf.find(child) == parentOf.end())
            {
                s.push(child);
                parentOf[child] = make_pair(top, 2);
            }
        }

        // Rule 3: (x, y) -> (0, y) if x > 0
        // Empty the first jug
        if (top.x > 0)
        {
            state child = (state){0, top.y};
            if (parentOf.find(child) == parentOf.end())
            {
                s.push(child);
                parentOf[child] = make_pair(top, 3);
            }
        }

        // Rule 4: (x, y) -> (x, 0) if y > 0
        // Empty the second jug
        if (top.y > 0)
        {
            state child = (state){top.x, 0};
            if (parentOf.find(child) == parentOf.end())
            {
                s.push(child);
                parentOf[child] = make_pair(top, 4);
            }
        }

        // Rule 5: (x, y) -> (min(x + y, capacity_x), max(0, x + y - capacity_x)) if y > 0
        // Pour water from the second jug into the first jug until the first jug is full
        // or the second jug is empty
        if (top.y > 0)
        {
            state child = (state){min(top.x + top.y, capacity_x), max(0, top.x + top.y - capacity_x)};
            if (parentOf.find(child) == parentOf.end())
            {
                s.push(child);
                parentOf[child] = make_pair(top, 5);
            }
        }

        // Rule 6: (x, y) -> (max(0, x + y - capacity_y), min(x + y, capacity_y)) if x > 0
        // Pour water from the first jug into the second jug until the second jug is full
        // or the first jug is empty
        if (top.x > 0)
        {
            state child = (state){max(0, top.x + top.y - capacity_y), min(top.x + top.y, capacity_y)};
            if (parentOf.find(child) == parentOf.end())
            {
                s.push(child);
                parentOf[child] = make_pair(top, 6);
            }
        }
    }

    // Target state was not found
    if (goal.x == -1 || goal.y == -1)
        return;

    // backtrack to generate the path through the state space
    path.push(make_pair(goal, 0));
    // remember parentOf[start] = (start, 0)
    while (parentOf[path.top().first].second != 0)
        path.push(parentOf[path.top().first]);
}

int main()
{
    stack<pair<state, int>> path;

    cout << "Enter the capacities of the two jugs : ";
    cin >> capacity_x >> capacity_y;
    cout << "Enter the target amount : ";
    cin >> target;

    dfs((state){0, 0}, path);
    if (path.empty())
        cout << "\nTarget cannot be reached.\n";
    else
    {
        cout << "\nNumber of moves to reach the target = " << path.size() - 1 << "\nSolution Path :\nInitial ";
        while (!path.empty())
        {
            state top = path.top().first;
            int rule = path.top().second;
            path.pop();

            switch (rule)
            {
            case 0:
                cout << "\b\b\b\bGoal State : (" << top.x << "," << top.y << ")\n";
                break;
            case 1:
                cout << "State : (" << top.x << "," << top.y << ")\n\nAction: Fill the first jug\nNew ";
                break;
            case 2:
                cout << "State : (" << top.x << "," << top.y << ")\n\nAction: Fill the second jug\nNew ";
                break;
            case 3:
                cout << "State : (" << top.x << "," << top.y << ")\n\nAction: Empty the first jug\nNew ";
                break;
            case 4:
                cout << "State : (" << top.x << "," << top.y << ")\n\nAction: Empty the second jug\nNew ";
                break;
            case 5:
                cout << "State : (" << top.x << "," << top.y << ")\n\nAction: Pour from second jug into first jug\nNew ";
                break;
            case 6:
                cout << "State : (" << top.x << "," << top.y << ")\n\nAction: Pour from second jug into second jug\nNew ";
                break;
            }
        }
    }

    return 0;
}