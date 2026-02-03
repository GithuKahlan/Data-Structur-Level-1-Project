#pragma once
#include<iostream>
#include"clsDynamicArray.h"
using namespace std;


template<class T>

class clsMyQueueArr
{
protected:

	clsDynamicArray<int>_MyList;


public:



	void push(int Value)
	{
		_MyList.InsertAtEnd(Value);

	}

	void pop()
	{
		_MyList.DeleteFirstItem();

	}


	void Print()
	{
		_MyList.PrintList();
	}


	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}


	T GetItem(int index)
	{
		return _MyList.GetItem(index);
	}



	void Reverse()
	{

		_MyList.Reverse();
	}



	void UpdateItem(int index, T NewValue)
	{

		_MyList.SetItem(index, NewValue);

	}

	
	void InsertAfter(int index, T NewValue)
	{
		_MyList.InsertAfter(index, NewValue);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Clear()
	{
		_MyList.Clear();
	}


};

