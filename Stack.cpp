#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
	private:
		struct Node
		{
			T Data;
			Node *Next;
		};
		
		Node Head;
		Node *Final;
		int count;
	
	public:
		Stack()
		{
			Head.Next = NULL;
			Final = &Head;
			count = 0;
		}
		
		void Push(T data)
		{
			Final->Next = new Node;
			Final = Final->Next;
			
			Final->Data = data;
			Final->Next = NULL;
			
			count++;
		}
		
		void Pop()
		{
			if ( count == 0 )
			{
				cout << "Is empty!" << endl;
				return;
			}
			
			Node *Temp;
			Temp = Head.Next;
			
			Head.Next = Head.Next->Next;
			delete Temp;
			count--;
		}
		
		int Num_Of_Nodes()
		{
			return count;
		}
};


#endif