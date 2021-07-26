//  to solve missionaries and cannibals problem using BFS technique.
#include <iostream>
#include <queue>
using namespace std;

int m, c;						//m missionaries, n cannibals
int mm[] = {0, 1, 1, 2, 0};		//possible number of people who can board each time (operations)
int cc[] = {1, 0, 1, 0, 2};		//mm[i] missionaries and cc[i] cannibals
int qindex = 0;

struct node {
	int lm;		//no. of missionaries on Left
	int lc;		//no. of cannibals on Left
	int rm;		//no. of missionaries on Right
	int rc;		//no. of cannibals on Right
	int boat;	//direction of boat (1 for L,-1 for R)
	int top;
};

queue <node> moves;
struct node state[100];

int isDangerous(node state) {
	if ((state.lm >= state.lc && state.rm >= state.rc && state.lm >= 0 && state.lc >= 0 && state.rm >= 0 && state.rc >= 0) ||
	        (state.lm >= 0 && state.lc >= 0 && state.rm >= 0 && state.rc >= 0 && state.lm == 0 && state.rm >= state.rc) ||
	        (state.lm >= 0 && state.lc >= 0 && state.rm >= 0 && state.rc >= 0 && state.lm >= state.lc && state.rm == 0)) {
		return 1;	//valid move
	}
	return 0;		//invalid move
}

int isVisited(node p, int top) {
	for (int i = 0; i < top; i++) {
		if (state[i].lm == p.lm && state[i].lc == p.lc && state[i].rm == p.rm && state[i].rc == p.rc && state[i].boat == p.boat)
			return 0;	//visited
	}
	return 1;			//not visited
}

void bfs() {
	while (!moves.empty()) {
		node current_state = moves.front();
		int m1 = current_state.lm;
		int c1 = current_state.lc;
		int m2 = current_state.rm;
		int c2 = current_state.rc;

		for (int i = 0; i < 5; i++) {
			node new_state;
			if (current_state.boat == 1) {
				new_state.lm = m1 - mm[i];
				new_state.lc = c1 - cc[i];
				new_state.rm = m2 + mm[i];
				new_state.rc = c2 + cc[i];

				if (new_state.lm == 0 && new_state.lc == 0 && new_state.rm == 3 && new_state.rc == 3)
					return;		//final solution state found
			}

			if (current_state.boat == -1) {
				new_state.lm = m1 + mm[i];
				new_state.lc = c1 + cc[i];
				new_state.rm = m2 - mm[i];
				new_state.rc = c2 - cc[i];
			}

			new_state.boat = -current_state.boat;
			new_state.top = current_state.top + 1;
			if (isDangerous(new_state) == 1 && isVisited(new_state, qindex) == 1) {
				state[qindex++] = new_state;
				moves.push(new_state);
			}
		}
		moves.pop();
	}
}

void display(int mleft, int cleft, int mright, int cright) {
	cout << "State:" << endl;
	cout << "  L\t\t" << "  R" << endl;
	cout << mleft << "M " << cleft << "C\t\t" << mright << "M " << cright << "C\t" << endl;
}

int main() {
	node init;		//initial state
	init.lm = 3;
	init.lc = 3;
	init.rm = 0;
	init.rc = 0;
	init.boat = 1;
	init.top = 0;
	moves.push(init);
	state[qindex++] = init;

	bfs();

	cout << "Initial ";
	display(3, 3, 0, 0);

	for (int i = 3; i < qindex - 1; i++) {
		if (state[i].boat == 1)
			cout << endl << "Boat moves: L <-- R" << endl;
		if (state[i].boat == -1)
			cout << endl << "Boat moves: L --> R" << endl;
		cout << "New ";
		display(state[i].lm, state[i].lc, state[i].rm, state[i].rc);
	}

	cout << endl << "Boat moves: L --> R" << endl;
	cout << "Final ";
	display(0, 0, 3, 3);
	return 0;
}
