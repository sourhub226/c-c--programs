// to solve 8 puzzle problem using Hill Climbing technique.
#include <iostream>
using namespace std;


void printArray(int array[][3]) {
	for(int a=0; a<3; a++) {
		for(int b=0; b<3; b++) {
			cout<<array[a][b]<<"\t";
		}
		cout<<endl;
	}
}

int heuristic(int ini[][3],int fin[][3]) {
	int hx=0;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(ini[i][j]>0) {
				for(int k=0; k<3; k++) {
					for(int l=0; l<3; l++) {
						if (fin[k][l]==ini[i][j]) {
							hx=hx + (abs(i-k)+abs(j-l));

						}
					}
				}
			}
		}
	}
	return hx;
}

void makeMove(int temp[][3],int move) {
	int flag=0;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(temp[i][j]==-1) {
				if(move==1) {
					temp[i][j]=temp[i-1][j];
					temp[i-1][j]=-1;
					flag=1;
					break;
				} else if(move==2) {
					temp[i][j]=temp[i+1][j];
					temp[i+1][j]=-1;
					flag=1;
					break;
				} else if(move==3) {
					temp[i][j]=temp[i][j-1];
					temp[i][j-1]=-1;
					flag=1;
					break;
				} else {
					temp[i][j]=temp[i][j+1];
					temp[i][j+1]=-1;
					flag=1;
					break;
				}
			}
		}
		if(flag==1) break;
	}
}

int childTraverse(int curr[][3],int fin[][3],int move) {
	int temp [3][3];
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			temp[i][j]=curr[i][j];
		}
	}
	makeMove(temp,move);
	printArray(temp);
	int h=heuristic(temp,fin);
	cout<<"      h = "<<h<<endl<<endl;
	return h;
}

void steepestHillClimb( int ini[][3], int fin[][3],int previous) {
	int arr[4]= {99,99,99,99};
	int c=1;
	cout<<"------------------------------------------------------------"<<endl;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(ini[i][j]==-1) {
				if(i>0 && previous!=2) {
					cout<<"Expanding -> moving -1 up, Child "<<c++<<":"<<endl;
					arr[0]=childTraverse(ini,fin,1);
				}
				if(i<2 && previous!=1) {
					cout<<"Expanding -> moving -1 down, Child "<<c++<<":"<<endl;
					arr[1]=childTraverse(ini,fin,2);
				}
				if(j>0 && previous!=4) {
					cout<<"Expanding -> moving -1 left, Child "<<c++<<":"<<endl;
					arr[2]=childTraverse(ini,fin,3);
				}
				if(j<2 && previous!=3) {
					cout<<"Expanding -> moving -1 right, Child "<<c++<<":"<<endl;
					arr[3]=childTraverse(ini,fin,4);
				}
			}
		}
	}
	int locOpt=99;
	int index=0;
	for(int i=0; i<4; i++) {
		if(arr[i]<locOpt) {
			locOpt=arr[i];
			index=i+1;
		}
	}
	makeMove(ini,index);
	cout<<"------------------------------------------------------------"<<endl;
	cout<<"Next state (with minimum h value) :"<<endl;
	printArray(ini);
	if(locOpt==0) {
		cout<<"\nGoal state found!"<<endl;
		return;
	} else
		steepestHillClimb(ini,fin,index);
}

int main() {
	int initial[3][3];
	int final[3][3];
	int userEntry;
	cout<<"Enter initial state 3x3 matrix (-1 as empty position) "<<endl;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			cout<<"Enter element S["<<i<<"]["<<j<<"]: ";
			cin>>userEntry;
			initial[i][j]=userEntry;
		}
	}
	cout<<"\nEnter goal state 3x3 matrix (-1 as empty position) "<<endl;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++) {
			cout<<"Enter element G["<<i<<"]["<<j<<"]: ";
			cin>>userEntry;
			final[i][j]=userEntry;
		}
	cout<<endl<<"------------------------------------------------------------";
	cout<<"\nInitial state:"<<endl;

	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			cout<<initial[i][j]<<"\t";
		}
		cout<<endl;
	}

	steepestHillClimb(initial,final,0);
	return 0;
}
