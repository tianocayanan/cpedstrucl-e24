#include <iostream>
using namespace std;

void shell_sort(int *a, int n){
	int h, i, j, k;
	cout<<"Passes: "<<endl;
	for(h = n; h /=2;){
		for(i = h; i < n; i++){
			k = a[i];
			for(j = i; j >= h && k < a[j - h]; j -=h){
				a[j] = a[j - h];
			}
			a[j] = k;
		}
		for(int i=0; i<5; i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}

int main (int ac, char **av){
	int a[] = {40, 30, 20, 50, 10}, n;
	cout<<"Original array is: "<<endl;
	for(int i=0; i<5; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	n = sizeof a / sizeof a[0];
	shell_sort (a, n);
	cout<<endl;
	cout<<"Sorted array is: "<<endl;
	for(int i=0; i<5; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
