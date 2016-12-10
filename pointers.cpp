#include <iostream>
#include <string>
using namespace std;

void strcat(char *n1, char *n2)
void strcpy(char *n1, char *n2)
void strrev(char *n1, char *n2)
void strcmp(char *n1, char *n2)

int main(){
	int choice = 0;
	char firstMessage, secondMessage;
	cout<<"Enter first message: ";
	gets(firstMessage);
	cout<<"Enter second message: ";
	gets(secondMessage);
	getch();
	while(1){
		cout<<"MAIN MENU\n";
		cout<<"[1] - strcat\n";
		cout<<"[2] - strcpy\n";
		cout<<"[3] - strrev\n";
		cout<<"[4] - strcmp\n";
		cout<<"[5] - Exit\n";
		cout<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1: strcat(firstMessage, secondMessage);
			break;
			case 2: strcpy(firstMessage, secondMessage);
			break;
			case 3: strrev(firstMessage, secondMessage);
			break;
			case 4: strcmp(firstMessage, secondMessage);
			break;
			case 5: cout<<"\nThank you for using the program!\n";
			exit(1);
			break;
			default: cout<<"INVALID CHOICE! Please try again.";
		}
	}
	cout<<endl;
	system("pause");
}

void strcat(char *n1, char *n2){
	while(*n1!='\0'){
		cout<<*n1;
	}
	while(*n2!='\0'){
		cout<<*n2;	
	}
	getch();
}

void strcpy(char *n1, char *n2){
	while(*n1!='\0'||*n2!='0'){
		*n1=*n2;
		cout<<*n1;
		*n1++;
		*n2++;
	}
	getch();
}

void strrev(){
	int *n1=0
}

void strcmp(){
	
}
