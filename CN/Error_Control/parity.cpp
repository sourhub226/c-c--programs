#include<iostream>
using namespace std;

int get_parity(int arr[],int n) {
	int parity=0;
	for(int k=0; k<n; k++) {
		parity=parity^arr[k];
	}
	return parity;
}

int main() {
	int n, message[50],s_parity,r_parity;
	cout<<"Even parity error detector\n\n";
	cout<<"AT SENDER'S END "<<endl;
	cout<<"Enter the number of message bits : ";
	cin>>n;
	cout<<"Enter the message (separate bits with a space) : ";
	for(int i=0; i<n; i++)
		cin>>message[i];

	s_parity=get_parity(message,n);
	cout<<"\nSender Parity bit = "<<s_parity;

	message[n]=s_parity;
	cout<<"\nEncoded message: ";
	for(int i=0; i<n+1; i++)
		cout<<message[i]<<" ";

	cout<<endl<<endl<<"AT RECIEVER'S END"<<endl;
	cout<<"Enter the received message (separate bits with a space) : ";
	for(int i=0; i<n+1; i++)
		cin>>message[i];

	d
	r_parity=get_parity(message,n+1);
	cout<<"\nReciever Parity bit = "<<r_parity;

	if(r_parity==0)
		cout<<"\nNo error in transmission.";
	else
		cout<<"\nError detected in transmission.";
}
