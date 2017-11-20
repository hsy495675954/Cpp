#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <iostream>
using namespace std;

template <typename T> 
class Queue
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
		Queue()
		{
			Head.Next = NULL;
			Final = &Head;
			count = 0;
		}
		
		void MakeEmpty()
		{
			Node *Temp;
			
			do
			{
				Temp = &Head;
				Temp = Temp->Next;
				Head.Next = Head.Next->Next;
				Delete Temp;
			}
			while(Temp->Next != NULL )
			
			Final = &Head;
		}	
		
		void Enqueue(T data)
		{
			Final->Next = new Node;
			if ( Final->Next == NULL )
			{
				cout << "Out of space!!!" << endl;
				return ;
			}
			Final = Final->Next;
			Final->Data = data;
			Final->Next = NULL;
			
			count++;
		}
		
		void Dequeue()
		{
			if (count == 0)
			{
				cout << "Is empty!" << endl;
				return;
			}
			
			Node *Temp = Head.Next;
			Head.Next = Head.Next->Next;
			
			delete Temp;
			count--;
		}
		
		T GetFirstData()
		{
			return Head.Next->Data;
		}
		
		T GetFinalData()
		{
			return Final->Data;
		}
		
		int Num_Of_Nodes()
		{
			return count;
		}	
		
};
		
#endif
