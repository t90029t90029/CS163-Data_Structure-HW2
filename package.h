//Shang-Chun,Lin  CS163 program#2 assignment
#include <iostream>
#include <cctype>
#include <cstring>

//the purpose of this file is to declare the structs and the classes I need in this program to deal with ADT
const int MAX = 5;

struct package
{
	char * sender_name;
	char * sender_number;
	char * code;		//identification code of the package
	char * delivery_name;
	char * delivery_address;
};

struct s_node		//stack node
{
	package * data;
	s_node * next;
};

class stack
{
	public:
		stack();
		~stack();
		int push(package *to_add);
		int pop();
		int display();
		int peek(package & at_top)const;

	private:
		int push(s_node * &head,package *to_add);
		int pop(s_node * &head);
		int display(s_node * head);
		int top_index;
		s_node * head;
};

struct q_node		//queue node
{
	char * address;
	stack  stack_object;
	q_node * next_queue;
};

class queue
{
	public:
		queue();
		~queue();
		int enqueue(package *to_add);
		int dequeue();
		int peek(package & at_top)const;
		int display_queue();

	private:
		int enqueue(q_node * &rear,package *to_add);
		int display_queue(q_node * rear,q_node * temp);
		q_node * front;
		q_node * rear;
};

