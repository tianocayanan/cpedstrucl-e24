#include <iostream>
#include <conio.h>
using namespace std;

class Stack {
  public:
    Stack(int num) {
      top = 0;
      maxelem = num;
      s = new int[maxelem];
    }
    
  void push(int t) {
  	cout << "Push "<<t<<": \n";
    if (top == maxelem) 
		return;
    s[top++] = t;
  }
  
  int pop() {
  	cout << "Pop: \n";
    if (top == 0) 
		return -1;
    return s[--top];
  }
  
  void display() {
    if (top == 0) {
      cout << "(empty)\n";
      return;
    }
    for (int t = 0; t < top; t++) 
		cout << s[t] << " ";
    cout << "\n";
  }
  
  int empty() {
    return top == 0;
  }
  
  private:
    int * s;
  int top;
  int maxelem;
};

void menu(){
	cout << "What would you like to do?: \n";
	cout << "1: Push \n";
	cout << "2: Pop \n";
	cout << "3: Display \n";
	cout << "4: Exit \n";
	
}

int main(){
	int givChoice = 0, numPush;
  	Stack * s = new Stack(100);
  	while(1){
		menu();
		cout<<endl;
		cout<<"Your choice: "<<endl;
		cin>>givChoice;
		cout<<endl;
  		switch(givChoice){
			case 1:{
				cout<<"Enter a given number: "<<endl;
				cin>>numPush;
				s -> push(numPush);
				getch();
				break;
			}
			break;
			case 2:{
				s -> pop();
				getch();
				break;
			}
			break;
			case 3:{
				s -> display();
				getch();
				break;
			}
			break;
			case 4:{
				cout<<"\nThank you for using the program!\n";
				exit(1);
				break;
			}
			default:{
				cout<<"INVALID CHOICE! Please try again.";
				getch();
				break;
			}
		}
	}
  return 1;
}
