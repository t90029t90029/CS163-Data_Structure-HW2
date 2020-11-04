//Shang-Chun,Lin  CS163 program#2 assignment
#include "package.h"

using namespace std;

//the purpose of this file is to implement the classes and structs which in the .h file to manage the data in a queue and a stack
stack::stack()
{
	top_index = 0;
	head = NULL;
}
stack::~stack()
{
	while(head)
	{
		if(top_index == 1)
		{
			if(head->next)
			{
				s_node * hold = head;
				delete []head->data[top_index-1].sender_name;
				delete []head->data[top_index-1].sender_number;
				delete []head->data[top_index-1].code;
				delete []head->data[top_index-1].delivery_name;
				delete []head->data[top_index-1].delivery_address;
				head->data[top_index-1].sender_name = NULL;
				head->data[top_index-1].sender_number = NULL;
				head->data[top_index-1].code = NULL;
				head->data[top_index-1].delivery_name = NULL;
				head->data[top_index-1].delivery_address = NULL;
				head = head->next;
				delete []hold->data;
				hold->data = NULL;
				top_index = 5;
			}
			else
			{
				delete []head->data[top_index-1].sender_name;
				delete []head->data[top_index-1].sender_number;
				delete []head->data[top_index-1].code;
				delete []head->data[top_index-1].delivery_name;
				delete []head->data[top_index-1].delivery_address;
				head->data[top_index-1].sender_name = NULL;
				head->data[top_index-1].sender_number = NULL;
				head->data[top_index-1].code = NULL;
				head->data[top_index-1].delivery_name = NULL;
				head->data[top_index-1].delivery_address = NULL;
				delete []head->data;
				head->data = NULL;
				delete head;
				head = NULL;
				top_index = 0;
			}
		}
		else
		{
			delete []head->data[top_index-1].sender_name;
			delete []head->data[top_index-1].sender_number;
			delete []head->data[top_index-1].code;
			delete []head->data[top_index-1].delivery_name;
			delete []head->data[top_index-1].delivery_address;
			head->data[top_index-1].sender_name = NULL;
			head->data[top_index-1].sender_number = NULL;
			head->data[top_index-1].code = NULL;
			head->data[top_index-1].delivery_name = NULL;
			head->data[top_index-1].delivery_address = NULL;
			--top_index;
		}
	}
	head = NULL;
	top_index = 0;
}
int stack::push(package *to_add)
{
	if(!to_add)
	{
		return 0;
	}
	return push(head,to_add);
}
int stack::push(s_node * &head,package *to_add)
{
	if(!head)			//the very first push : top_index = 0
	{
		head = new s_node;
		head->data = new package[MAX];
		head->data[top_index].sender_name = new char[strlen(to_add->sender_name)+1];
		head->data[top_index].sender_number = new char[strlen(to_add->sender_number)+1];
		head->data[top_index].code = new char[strlen(to_add->code)+1];
		head->data[top_index].delivery_name = new char[strlen(to_add->delivery_name)+1];
		head->data[top_index].delivery_address = new char[strlen(to_add->delivery_address)+1];
		strcpy(head->data[top_index].sender_name,to_add->sender_name);
		strcpy(head->data[top_index].sender_number,to_add->sender_number);
		strcpy(head->data[top_index].code,to_add->code);
		strcpy(head->data[top_index].delivery_name,to_add->delivery_name);
		strcpy(head->data[top_index].delivery_address,to_add->delivery_address);
		for(int i=1;i<5;++i)
		{
			head->data[i].sender_name = NULL;
			head->data[i].sender_number = NULL;
			head->data[i].code = NULL;
			head->data[i].delivery_name = NULL;
			head->data[i].delivery_address = NULL;
		}
		head->next = NULL;
		++top_index;
		return 1;
	}
	if(top_index == 5)
	{
		s_node * temp = new s_node;
		temp->data = new package[MAX];
		temp->data[0].sender_name = new char[strlen(to_add->sender_name)+1];
		temp->data[0].sender_number = new char[strlen(to_add->sender_number)+1];
		temp->data[0].code = new char[strlen(to_add->code)+1];
		temp->data[0].delivery_name = new char[strlen(to_add->delivery_name)+1];
		temp->data[0].delivery_address = new char[strlen(to_add->delivery_address)+1];
		strcpy(temp->data[0].sender_name,to_add->sender_name);
		strcpy(temp->data[0].sender_number,to_add->sender_number);
		strcpy(temp->data[0].code,to_add->code);
		strcpy(temp->data[0].delivery_name,to_add->delivery_name);
		strcpy(temp->data[0].delivery_address,to_add->delivery_address);
		for(int i=1;i<5;++i)
		{
			temp->data[i].sender_name = NULL;
			temp->data[i].sender_number = NULL;
			temp->data[i].code = NULL;
			temp->data[i].delivery_name = NULL;
			temp->data[i].delivery_address = NULL;
		}
		temp->next = head;
		head = temp;
		top_index = 1;
		return 1;
	}
	else if(top_index < 5)		//the stack is not full
	{
		head->data[top_index].sender_name = new char[strlen(to_add->sender_name)+1];
		head->data[top_index].sender_number = new char[strlen(to_add->sender_number)+1];
		head->data[top_index].code = new char[strlen(to_add->code)+1];
		head->data[top_index].delivery_name = new char[strlen(to_add->delivery_name)+1];
		head->data[top_index].delivery_address = new char[strlen(to_add->delivery_address)+1];
		strcpy(head->data[top_index].sender_name,to_add->sender_name);
		strcpy(head->data[top_index].sender_number,to_add->sender_number);
		strcpy(head->data[top_index].code,to_add->code);
		strcpy(head->data[top_index].delivery_name,to_add->delivery_name);
		strcpy(head->data[top_index].delivery_address,to_add->delivery_address);
		++top_index;
		return 1;
	}
}

int stack::pop()
{
	if(!head)
	{
		return 0;
	}
	return pop(head);
}
int stack::pop(s_node * &head)
{
	if(top_index == 1)
	{
		if(head->next)
		{
			s_node * hold = head;
			delete []head->data[top_index-1].sender_name;
			delete []head->data[top_index-1].sender_number;
			delete []head->data[top_index-1].code;
			delete []head->data[top_index-1].delivery_name;
			delete []head->data[top_index-1].delivery_address;
			head->data[top_index-1].sender_name = NULL;
			head->data[top_index-1].sender_number = NULL;
			head->data[top_index-1].code = NULL;
			head->data[top_index-1].delivery_name = NULL;
			head->data[top_index-1].delivery_address = NULL;
			head = head->next;
			hold->data = NULL;
			top_index = 5;
			return 1;
		}
		else
		{
			delete []head->data[top_index-1].sender_name;
			delete []head->data[top_index-1].sender_number;
			delete []head->data[top_index-1].code;
			delete []head->data[top_index-1].delivery_name;
			delete []head->data[top_index-1].delivery_address;
			head->data[top_index-1].sender_name = NULL;
			head->data[top_index-1].sender_number = NULL;
			head->data[top_index-1].code = NULL;
			head->data[top_index-1].delivery_name = NULL;
			head->data[top_index-1].delivery_address = NULL;
			delete []head->data;
			head->data = NULL;
			delete head;
			head = NULL;
			top_index = 0;
			return 0;		//return 0 : means empty / just like pop()
		}
	}
	delete []head->data[top_index-1].sender_name;
	delete []head->data[top_index-1].sender_number;
	delete []head->data[top_index-1].code;
	delete []head->data[top_index-1].delivery_name;
	delete []head->data[top_index-1].delivery_address;
	head->data[top_index-1].sender_name = NULL;
	head->data[top_index-1].sender_number = NULL;
	head->data[top_index-1].code = NULL;
	head->data[top_index-1].delivery_name = NULL;
	head->data[top_index-1].delivery_address = NULL;
	--top_index;
	return 1;
}
int stack::peek(package & at_top)const
{
	if(!head)
	{
		return 0;
	}
	strcpy(at_top.sender_name, head->data[top_index-1].sender_name);
	strcpy(at_top.sender_number, head->data[top_index-1].sender_number);
	strcpy(at_top.code, head->data[top_index-1].code);
	strcpy(at_top.delivery_name, head->data[top_index-1].delivery_name);
	strcpy(at_top.delivery_address, head->data[top_index-1].delivery_address);
	return 1;
}

int stack::display()
{
	if(!head)
	{
		return 0;
	}
	int i = 0;
	if(i == 5)			//all nodes are full
	{
		return MAX*display(head);
	}
	else
	{
		int count = 0;
		int after_first_node = 0;
		while(i < top_index)				//display from the bottom
		{
			cout<<"package info : "<<endl;
			cout<<"The sender name : "<<head->data[i].sender_name<<endl;
			cout<<"The sender number : "<<head->data[i].sender_number<<endl;
			cout<<"The identification code : "<<head->data[i].code<<endl;
			cout<<"The delivery name : "<<head->data[i].delivery_name<<endl;
			cout<<"The delivery address : "<<head->data[i].delivery_address<<endl<<endl;
			++i;
			++count;
		}

		if(head->next)
		{
			after_first_node =  display(head->next);
		}
		return count + MAX*after_first_node;		//first node + 5*how many full nodes have dispalyed = all stacks
	}
}
int stack::display(s_node * head)
{
	if(!head)
	{
		return 0;
	}
	int i = 0;
	while(i < 5)					//display from the bottom
	{
		cout<<"package info : "<<endl;
		cout<<"The sender name : "<<head->data[i].sender_name<<endl;
		cout<<"The sender number : "<<head->data[i].sender_number<<endl;
		cout<<"The identification code : "<<head->data[i].code<<endl;
		cout<<"The delivery name : "<<head->data[i].delivery_name<<endl;
		cout<<"The delivery address : "<<head->data[i].delivery_address<<endl<<endl;
		++i;
	}
	return display(head->next) + 1;	
}

queue::queue()
{
	front = NULL;
	rear = NULL;
}
queue::~queue()
{
	while(front)		//at least one node exists
	{
		if(front == front->next_queue)	//only one node
		{
			front->stack_object.~stack();
			delete []front->address;
			front->address = NULL;
			front->next_queue = NULL;
			delete front;
			front = rear = NULL;
		}
		else
		{
			front->stack_object.~stack();
			delete []front->address;
			front->address = NULL;
			rear->next_queue = front->next_queue;
			front->next_queue = NULL;
			delete front;
			front = rear->next_queue;
		}
	}
	front = rear = NULL;
}
int queue::enqueue(package *to_add)
{
	if(!to_add)
	{
		return 0;
	}
	return enqueue(rear,to_add);
}
int queue::enqueue(q_node * &rear,package *to_add)
{
	if(!front || !rear)
	{
		rear = new q_node;
		rear->stack_object.push(to_add);
		rear->address = new char[strlen(to_add->delivery_address)+1];
		strcpy(rear->address,to_add->delivery_address);
		rear->next_queue = rear;
		front = rear;
		return 1;
	}
	if(strcmp(to_add->delivery_address,rear->address) == 0)
	{
		return rear->stack_object.push(to_add);	//if the address is same, then we do not need to enqueue
	}
	q_node * hold = rear;
	rear = new q_node;
	rear->stack_object.push(to_add);
	rear->address = new char[strlen(to_add->delivery_address)+1];
	strcpy(rear->address,to_add->delivery_address);
	rear->next_queue = front;
	hold->next_queue = rear;
	return 1;
}

int queue::dequeue()
{
	if(!front)
	{
		return 0;
	}
	if(front->next_queue == front)		//just 1 queue node
	{
		if(!front->stack_object.pop())	//if = 0, means the stack is empty
		{
			delete []front->address;
			front->address = NULL;
			front->next_queue = NULL;
			delete front;
			front = rear = NULL;
			return 1;
		}
	}

	else
	{
		if(!front->stack_object.pop())
		{
			delete []front->address;
			front->address = NULL;
			rear->next_queue = front->next_queue;
			front->next_queue = NULL;
			delete front;
			front = rear->next_queue;
			return 1;
		}
	}
}
int queue::peek(package & at_top)const
{
	if(!front)
	{
		return 0;
	}
	return front->stack_object.peek(at_top);
}
int queue::display_queue()
{
	if(!front)
	{
		return 0;
	}
	if(front == front->next_queue)			//just 1 q_node
	{
		int success = front->stack_object.display();
		return	success; 
	}
	return display_queue(front,rear);		//if 2 more nodes
}
int queue::display_queue(q_node * front,q_node * rear)
{
	int success = 0;
	if(front == rear)
	{
		success = front->stack_object.display();
		return 1;
	}
	success = front->stack_object.display();
	return display_queue(front->next_queue,rear) + 1;
}
