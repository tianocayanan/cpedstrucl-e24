#include <iostream>
#include <conio.h>
using namespace std;

class LinkedList{
    struct Node {
        int x;
        Node *next;
    };

public:
    LinkedList(){
        head = NULL; // set head to NULL
    }

    void addValue(int val){
        Node *n = new Node();   
        n->x = val;             
        n->next = head;         
                               
        head = n;              
    }

    int popValue(){
        Node *n = head;
        int ret = n->x;

        head = head->next;
        delete n;
        return ret;
    }
    
    void display(){
		Node *n;
		n = head;
		if (n == NULL){
			cout<<"There is nothing to display. Input values first.";
		}
		else{
			while(n!=NULL){
				cout<< n->x <<" ";
				n = n->next;
			}	
		}
		getch();
	}

private:
    Node *head; 
};

void menu(){
	cout << "What would you like to do?: \n";
	cout << endl;
	cout << "1: Insert into linked list (Push) \n";
	cout << "2: Pop \n";
	cout << "3: Exit \n";
	cout << "4: Display \n";
	
}

int main() {
	LinkedList list;
	int givChoice = 0, givNum;
  	while(1){
  		system("cls");
		menu();
		cout<<endl;
		cout<<"Your choice: ";
		cin>>givChoice;
		cout<<endl;
  		switch(givChoice){
  			case 1:{
  				cout<<"Insert a desired number: ";
  				cin>>givNum;
				list.addValue(givNum);
				cout<<endl;
				cout<<"Insertion is success!";
				getch();
				break;
			}
			case 2:{
				cout<<list.popValue()<<" has been erased!";
				getch();
				break;
			}
			case 3:{
				cout<<"\nThank you for using the program!\n";
				exit(1);
				break;
			}
			case 4:{
				list.display();
				break;
			}
			default:{
				cout<<"INVALID CHOICE! Please try again.";
				getch();
				break;
			}
		}
		cout<<endl;
	}
  return 1;
}
