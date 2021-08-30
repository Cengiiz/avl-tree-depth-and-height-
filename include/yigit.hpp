/*
* @main.cpp
* @txt doyasindan okunan bilgileri avl agacina atayip durumlara gore islem yapan kod.
* @1. Öğretim B
* @2. odev
* @Başlangıç Tarihi: 16.08.2021 13:20:00 Bitiş Tarihi:26.08.2021 23:59:00	
* @G201210376 Cengizhan KOCAL cengizhan.kocal@ogr.sakarya.edu.tr
*/




#ifndef YIGIT_HPP
#define YIGIT_HPP
#include<iostream>
using namespace std;
class yigit
{
private:
	int *items;
	int head;
	int length;
	int capacity;
	bool IsFull();
	void Reserve(int capacity);

public:
	yigit();
	bool IsEmpty() const;
	void Push(const int &obj);
	void Pop();
	const int &Top() const;
	void Clear();
	~yigit();
};

#endif