//Shang-Chun,Lin  CS163 program#2 assignment
#include "package.h"

using namespace std;

//the purpose of this file is to test the structs and classes that I have declared in .h file (working as client program)

int main()
{
	queue list;
	stack item;
	package * to_add;
	to_add = NULL;
	package at_top;
	at_top.sender_name = NULL;
	at_top.sender_number = NULL;
	at_top.code = NULL;
	at_top.delivery_name = NULL;
	at_top.delivery_address = NULL;
	int answer = 0;
	cout<<"Please type a integer number to choose what you want to do. If the address of a package you are going to add is same"<<endl
		<<" as the address of the last package you have added, then they will be organized in a same stack node."<<endl<<endl
		<<"1 for pushing a new package in the waiting list,    2 for poping the first package in the waiting list, "<<endl
		<<"3 for peeking the information of the first package, 4 for displaying the information of the packages in the list, "<<endl
		<<"5 for quitting the program."<<endl;
	cin>>answer;
	cin.ignore(100,'\n');

	while(answer != 5)
	{
		if(answer == 1)
		{
			to_add = new package;	
			to_add->sender_name = new char[21];
			to_add->sender_number = new char[21];
			to_add->code = new char[16];
			to_add->delivery_name = new char[21];
			to_add->delivery_address = new char[31];
			cout<<"Please type in the information of the package you want to add in the list."<<endl;
			cout<<"Please type in the sender's name of the package :"<<endl;
			cin.get(to_add->sender_name,20,'\n');
			cin.ignore(100,'\n');
			cout<<"Please type in the sender's number of the package :"<<endl;
			cin.get(to_add->sender_number,20,'\n');
			cin.ignore(100,'\n');
			cout<<"Please type in the identification code of the package :"<<endl;
			cin.get(to_add->code,15,'\n');
			cin.ignore(100,'\n');
			cout<<"Please type in the name of the person who will get this package :"<<endl;
			cin.get(to_add->delivery_name,20,'\n');
			cin.ignore(100,'\n');
			cout<<"Please type in the destination of the address of this package :"<<endl;
			cin.get(to_add->delivery_address,30,'\n');
			cin.ignore(100,'\n');

			cout<<"You have pushed "<<list.enqueue(to_add)<<" package in the list."<<endl;
			cout<<"There are "<<endl<<endl<<list.display_queue()<<" addresses in the list."<<endl;
		}

		if(answer == 2)
		{
			cout<<"You have popped "<<list.dequeue()<<" package from the list."<<endl;
			cout<<"There are "<<endl<<endl<<list.display_queue()<<" addresses in the list."<<endl;
		}

		if(answer == 3)
		{
			at_top.sender_name = new char[21];
			at_top.sender_number = new char[21];
			at_top.code = new char[16];
			at_top.delivery_name = new char[21];
			at_top.delivery_address = new char[31];
			if(list.peek(at_top))
			{
				cout<<"There are at least one package in the list."<<endl<<endl;

				cout<<"The information of the top package is :"<<endl;
				cout<<"Sender's name : "<<at_top.sender_name<<endl;
				cout<<"Sender's number : "<<at_top.sender_number<<endl;
				cout<<"Identification code : "<<at_top.code<<endl;
				cout<<"Delivery's name : "<<at_top.delivery_name<<endl;
				cout<<"Delivery's address : "<<at_top.delivery_address<<endl;
			}
			else
			{
				cout<<"There is no package in the list."<<endl;
			}
		}

		if(answer == 4)
		{
			if(!list.display_queue())
			{
				cout<<"This is an empty list."<<endl;
			}
		}
		cout<<"Please type a integer number to choose what you want to do. If the address of a package you are going to add is same"<<endl
			<<" as the address of the last package you have added, then they will be organized in a same stack node."<<endl<<endl
			<<"1 for pushing a new package in the waiting list,    2 for poping the first package in the waiting list, "<<endl
			<<"3 for peeking the information of the first package, 4 for displaying the information of the packages in the list, "<<endl
			<<"5 for quitting the program."<<endl;
		cin>>answer;
		cin.ignore(100,'\n');

		if(to_add)
		{
			delete []to_add->sender_name;
			delete []to_add->sender_number;
			delete []to_add->code;
			delete []to_add->delivery_name;
			delete []to_add->delivery_address;
			to_add->sender_name = NULL;
			to_add->sender_number = NULL;
			to_add->code = NULL;
			to_add->delivery_name = NULL;
			to_add->delivery_address = NULL;
			delete to_add;
			to_add = NULL;
		}
		if(at_top.sender_name)
		{
			delete []at_top.sender_name;
			delete []at_top.sender_number;
			delete []at_top.code;
			delete []at_top.delivery_name;
			delete []at_top.delivery_address;
			at_top.sender_name = NULL;
			at_top.sender_number = NULL;
			at_top.code = NULL;
			at_top.delivery_name = NULL;
			at_top.delivery_address = NULL;
		}
	}
	return 0;
}
