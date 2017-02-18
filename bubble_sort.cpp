#include <iostream>
using namespace std;

int main(){
	int A[]={35, 10, 55, 20, 5}, swap;
	cout<<"Original array is: "<<endl;
	for(int i=0; i<5; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	cout<<"Passes:"<<endl;
	for(int i=5; i>1; i--){
		for(int j=0; j<i-1; j++){
			if(A[j]>A[j+1]){
				swap = A[j];
				A[j] = A[j+1];
				A[j+1] = swap;
			}
		}
		for(int i=0; i<5; i++){
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Sorted array is: "<<endl;
	for(int i=0; i<5; i++){
		cout<<A[i]<<" ";
	}
}
