#include<iostream>
using namespace std;

void division(int temp[],int gen[],int n,int r) {
	for(int i=0; i<n; i++) {
		if (gen[0]==temp[i]) {
			for(int j=0,k=i; j<r+1; j++,k++)
				if(!(temp[k]^gen[j]))
					temp[k]=0;
				else
					temp[k]=1;
		}
	}
}

int main() {
	int n,r,message[50],gen[50],temp[50];
	cout<<"CRC checker\n\n";
	cout<<"AT SENDER'S END "<<endl;
	cout<<"Enter the number of message bits : ";
	cin>>n;
	cout<<"Enter the message (separate bits with a space) : ";
	for(int i=0; i<n; i++)
		cin>>message[i];

	cout<<"\nEnter the number of generator bits : ";
	cin>>r;
	cout<<"Enter the generator (separate bits with a space) : ";
	for(int i=0; i<r; i++)
		cin>>gen[i];

	r--;

	for(int i=0; i<r; i++)
		message[n+i] = 0;

	for(int i=0; i<n+r; i++)
		temp[i] = message[i];

	division(temp,gen,n,r);

	cout<<" \nCRC : ";
	for(int i=0; i<r; i++) {
		cout<<temp[n+i]<<" ";
		message[n+i] = temp[n+i];
	}

	cout<<endl<<"Transmitted Message : ";
	for(int i=0; i<n+r; i++)
		cout<<message[i]<<" ";

	cout<<endl<<endl<<"AT RECIEVER'S END"<<endl;
	cout<<"Enter the received message (separate bits with a space) : ";
	for(int i=0; i<n+r; i++)
		cin>>message[i];

	for(int i=0; i<n+r; i++)
		temp[i] = message[i];

	division(temp,gen,n,r);

	for(int i=0; i<r; i++) {
		if(temp[n+i]) {
			cout<<"\nError detected in received message.";
			return 0;
		}
	}
	cout<<"\nNo error in received Message.\nReceived Original Message : ";
	for(int i=0; i<n; i++)
		cout<<message[i]<<" ";
	return 0;
}
