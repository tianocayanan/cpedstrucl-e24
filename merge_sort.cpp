#include <iostream>
using namespace std;

int main(){
	int A[]={30, 40, 20, 50, 10}, l1, l2, h1, h2, k, j, i, temp;
	cout<<"Original array is: "<<endl;
	for(int i=0; i<5; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	cout<<"Passes: "<<endl;
	for(int size=1; size<5; size=size*2){
		l1 = 0;
		k = 0;
		while(l1 + size<5){
			h1=l1+size-1;
			l2=h1+1;
			h2=l2+size-1;
			if(h2>5){
				h2=5-1;
			}
			i=l1;
			j=l2;
			while(i<=h1 && j<=h2){
				if(A[i]<=A[j]){
					temp[k++]=A[i++];
				}
				else{
					temp[k++]=A[j++];
				}
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
