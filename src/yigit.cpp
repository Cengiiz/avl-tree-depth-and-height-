/*
* @main.cpp
* @txt doyasindan okunan bilgileri avl agacina atayip durumlara gore islem yapan kod.
* @1. Öğretim B
* @2. odev
* @Başlangıç Tarihi: 16.08.2021 13:20:00 Bitiş Tarihi:26.08.2021 23:59:00	
* @G201210376 Cengizhan KOCAL cengizhan.kocal@ogr.sakarya.edu.tr
*/



#include<yigit.hpp>
	bool yigit::IsFull()
	{
		return length == capacity;
	}
	void yigit::Reserve(int capacity)
	{
		int *tmp = new int[capacity];
		for (int j = 0; j < length; j++)
			tmp[j] = items[j];
		if (items != NULL)
			delete[] items;
		items = tmp;
		this->capacity = capacity;
	}
	yigit::yigit()
	{
		items = NULL;
		head = -1;
		length = 0;
		capacity = 0;
	}
	bool yigit::IsEmpty() const
	{
		return head == -1;
	}
	void yigit::Push(const int &obj)
	{
		if (IsFull())
		{
			Reserve(max(1, 2 * capacity));
		}
		head++;
		items[head] = obj;
		length++;
	}
	void yigit::Pop()
	{
		if (IsEmpty()==0)
		{
				cout<<items[head]<<",";
				head--;
				length--;
			Pop();
		}
		
	}
	const int &yigit::Top() const
	{
		if (IsEmpty())
			throw "yigit is empty!";
		return items[head];
	}
	void yigit::Clear()
	{
		head = -1;
		length = 0;
	}
	yigit::~yigit()
	{
		if (items != NULL)
			delete[] items;
		items = NULL;
	}