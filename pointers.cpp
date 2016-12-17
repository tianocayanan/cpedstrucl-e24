#include <iostream>
#include <iomanip>
using namespace std;

void copy(char *mess3,char *mess1);

void concat(char *mess1, char *mess2);

void reverse(char *mess1);

int comp(char *mess1, char *mess2);

void menu();

int string_length(char*);

int main()
{
	int choice, mess;
	char mess1[20], mess2[20], mess3[20];
	main:
	menu();
	cin >>choice;
	system("cls");
	switch (choice){

		case 1:
			cin.ignore();
			cout<<"Enter message: ";
			gets(mess1);
			copy(mess3, mess1);
			cout << "Copied message: " <<mess3;
			break;
		case 2:
			cin.ignore();
			cout << "Enter first message: ";
			gets(mess1);
			cout << "Enter second message: ";
			gets(mess2);
			concat(mess1,mess2);
			cout<<"\nConcatinate message: " <<mess1;
			break;
		case 3:
			cin.ignore();
			cout <<"Enter message: ";
			gets(mess1);
			reverse(mess1);
			cout <<"\nReverse message: " <<mess1;
			break;
		case 4:
			cin.ignore();
			cout <<"Enter first message: ";
			gets(mess1);
			cout << "Enter second message: ";
			gets(mess2);
			comp(mess1,mess2);
			if (comp(mess1,mess2))
			cout <<"Both message are equal" <<endl;
			else
			cout <<"Both messages are not equal" <<endl;
			break;
		case 5:
			exit(1);
		default:
			cout <<"\nInvalid Input";
			goto main;
			
	}
}

void menu()
{
	system("cls");
	cout <<endl <<"Main Mennu\n";
	cout <<endl;
	cout <<"[ 1 ] strcpy . . .\n";
	cout <<"[ 2 ] strcat . . .\n";
	cout <<"[ 3 ] strrev . . .\n";
	cout <<"[ 4 ] strcmp . . .\n";
	cout <<"[ 5 ] Exit . . .\n";
	
	cout <<"\n Enter: ";

}

void copy(char *mess1, char *mess3)
{
	while(*mess1++ = *mess3++);
}

void concat(char *mess1, char *mess2)
{
	while(*mess1)
		*mess1++;
	while(*mess1++ = *mess2++);
}

void reverse(char *mess1)

{
	int length, c;
	char *begin, *end, temp;
	length = string_length(mess1);
	begin = mess1;
	end = mess1;
	for(c=0;c<(length-1);c++)
		end++;
	for(c=0;c<length/2;c++)
	{
		temp = *end;
		*end = *begin;
		*begin = temp;
		begin++;
		end--;
	}
	
	
	
}

int string_length(char *pointer)
{
	int c = 0;
	while(*(pointer+c)!='\0')
		c++;
	return c;
}

int comp(char *s1, char *s2){
	while(*s1 == *s2){
		if(*s1 == '\0' || *s2 == '\0')
			break;
		s1++;
		s2++;
	}
	if(*s1 == '\0' && *s2 == '\0')
		return 1;
	return 0;
}
