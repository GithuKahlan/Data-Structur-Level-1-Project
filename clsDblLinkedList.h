#pragma once
#include<iostream>
using namespace std;

template<class T>

class clsDblLinkedList
{

protected:
	int _Size = 0;
public:

	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;

	};
	
	Node* head = NULL;


	void InsertAtBeginning(T Value)
	{
		Node* newNode = new  Node();

		newNode->value = Value;
		newNode->prev = NULL;
		newNode->next = head;

		if (head != NULL)
		{
			head->prev = newNode;
		}
		head = newNode;
		_Size++;
	}


	void Print()
	{
		Node* Current = head;
		

		while (Current != NULL)
		{
			cout << Current->value <<" ";
			Current = Current->next;

		}
		cout << "\n";

	}


	Node* Find(T Value)
	{

		Node* Current = head;

		while (Current != NULL)
		{
			if (Current->value == Value)
				return Current;

			Current = Current->next;
		}

	return 	NULL;

	}

	
	void InsertAfter(Node * Current,T Value)
	{

		Node* newNode = new Node();

		newNode->value = Value;
		newNode->next = Current->next;
		newNode->prev = Current;
		
		if (Current->next!= NULL)
		{
			Current->next->prev = newNode;
		}
		Current->next = newNode;
		_Size++;
	}

	void InsertAtEnd(T Value)
	{

		Node* newNode = new Node();
		newNode->value = Value;
		newNode->next = NULL;
	

		if (head == NULL)
		{
			newNode->prev = NULL;
			head = newNode;
		}

		else
		{

			Node* Current = head;
			
			while (Current->next != NULL)
			{
				Current = Current->next;

			}

			Current->next = newNode;
			newNode->prev = Current;
		}
		_Size++;
	}



	void DeleteNode(Node*& NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL)
		{
			return;

		}
		
		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;

		}

		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev= NodeToDelete->prev;

		}

		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}	

		delete NodeToDelete;
		_Size--;

	}

	void DeleteFirstNode()
	{

		if (head == NULL)
		{
			return;
		}

		Node* temp = head;
		head = head->next;

		if (head != NULL)
		{
			head->prev = NULL;

		}
		delete temp;
		_Size--;
	}


	void DeleteLastNode()
	{

		if (head == NULL)
		{
			return;
		}

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return;

		}


		Node* Current = head;
		while (Current->next->next != NULL)
		{
			Current = Current->next;

		}

		Node* temp = Current->next;
		Current->next = NULL;
		delete temp;
		_Size--;

	}


	int Size()
	{

		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);

	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* current = head;
		Node* temp = nullptr;
	/*	
	The main Idea of the Reverse Function is that we change the pointer directions the prev becomes next and vice versa
	here in the reverse function we start with Current value = 1
			and Current.prev=NULL and Current.next=2.

			after we finish the first iteration we start from the begining 
			that Current Value=2 and Current.prev=1 and Current.next=3 and so on

			/////
			the if condition is used to let the first head points to 5 because temp.prev=5
			so the head equal to 5 and than in the print function it updated it self by head=head.next(4) and so on
		//	
		Original List head > 1>< 2 >< 3>< 4>< 5
		Reversed List	head > 5 >< 4 >< 3 >< 2 >< 1
	*/
		while(current!=nullptr)
		{
			temp = current->prev;
			current->prev= current->next;
			current->next = temp;
			current = current->prev;

		}

		if (temp != nullptr)
		{
			head = temp->prev;
		}
	}



	Node* GetNode(int index)
	{
		int Counter = 0;
		Node* current = head;
		if (index > _Size - 1 || index < 0)
			return NULL;
	
		while (current != NULL && (current->next != NULL))
		{
				if (index == Counter)
					break;

				current = current->next;
				Counter++;			
		}

		return current;

	}

	T GetItem(int index)
	{
		Node* ItemNode = GetNode(index);

		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->value;

	
	}

	bool UpdateItem(T index, T NewValue)
	{

		Node* ItemUpdate = GetNode(index);

		if (ItemUpdate != NULL)
		{
			ItemUpdate->value = NewValue;
			return true;
		}
		else
			return  false;


	}



	bool InsertAfter(int index, T Value)
	{

		Node* ItemNode = GetNode(index);

		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, Value);
			return true;
		}

		else
			return false;
	}

};






