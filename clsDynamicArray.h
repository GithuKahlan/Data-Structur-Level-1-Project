#pragma once
#include<iostream>
#include"clsMyQueue.h"
using namespace std;

template<class T>

class clsDynamicArray
{
protected:

	int _Size;
	T* _TempArray;

public:

	T* OriginalArray;

	clsDynamicArray(T arraySize=0)
	{
		if (arraySize < 0)
			arraySize = 0;

		_Size = arraySize;

		OriginalArray = new T[_Size];
	}

	
	~clsDynamicArray()
	{
		delete[] OriginalArray;
	} 


	bool SetItem(int index, T Value)
	{

		if (index> _Size || index<0)
		{
			return false;
		}

		OriginalArray[index] = Value;
			return true;
    }


	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);

	}

	int Size()
	{
		return _Size;
	}


	void resize(T NewSize)
	{
	
		if (NewSize < 0)
		{
			NewSize = 0;
		}

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;


	

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;

		delete[]OriginalArray;


		OriginalArray = _TempArray;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}
	}


	T GetItem(int index)
	{
		return OriginalArray[index];

	}

	void Reverse()
	{

		_TempArray = new T[_Size];
		int counter = 0;
		for (int i =_Size-1; i>=0; i--)
		{
			_TempArray[counter]=OriginalArray[i];
			counter++;
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;

	}

	void Clear()
	{

		resize(0);

	}

	bool DeleteItemAt(int index)
	{

		if (index > _Size || index < 0)
		{
			return false;
		}

		_Size--;

		_TempArray = new T[_Size];
	
		for (int i=0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
			
		}

		for (int i = index + 1; i < _Size + 1; i++)
		{
			_TempArray[i-1] = OriginalArray[i];

		}
	
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;

	}

	void DeleteFirstItem()
	{

		DeleteItemAt(0);

	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}


	int Find(T Value)
	{

		

		for (int i = 0; i < _Size; i++)
		{
			if (Value == OriginalArray[i])
			{
				return i;
			}

		}
		return -1;

	}


	bool DeleteItem(T Value)
	{

		int index = Find(Value);

		if (index == -1)
		{
			return false;
		}

		DeleteItemAt(index);
		return true;
	}

	bool InsertAt(int Index,T Value)
	{

		if(Index > _Size || Index < 0)
		{
			return false;
		}


		_Size++;

		_TempArray = new T[_Size];

		for (int i = 0; i < Index; i++)
		{
			
			_TempArray[i] = OriginalArray[i];

		}

		_TempArray[Index] = Value;


		for (int i = Index+1; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i - 1];

		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return  true;

	}


	void InsertAtBeginning(T Value)
	{

		InsertAt(0, Value);


	}


	bool InsertBefore(int index, T Value)
	{
		if(index<1)
			return InsertAt(0, Value);
		else
		return InsertAt(index - 1, Value);

	}



	bool InsertAfter(int index, T Value)
	{
		if (index >= _Size)
			return InsertAt(_Size - 1, Value);
		else
		return InsertAt(index + 1, Value);

	}


	bool InsertAtEnd(T Value)
	{

     return	InsertAt(_Size, Value);

	}

  

};