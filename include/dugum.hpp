/*
* @main.cpp
* @txt doyasindan okunan bilgileri avl agacina atayip durumlara gore islem yapan kod.
* @1. Öğretim B
* @2. odev
* @Başlangıç Tarihi: 16.08.2021 13:20:00 Bitiş Tarihi:26.08.2021 23:59:00	
* @G201210376 Cengizhan KOCAL cengizhan.kocal@ogr.sakarya.edu.tr
*/



#ifndef DUGUM_HPP
#define DUGUM_HPP
#include<iostream>
#include<kisi.hpp>
#include<yigit.hpp>
using namespace std;
class Dugum
{
    public:
	Kisi kisi;
	Dugum *sol;
	Dugum *sag;
	yigit *yukseklik;
    yigit *derinlik;
	Dugum(int by);
	Dugum(Kisi* insan);
	Dugum(Kisi insan, Dugum *sl , Dugum *sg);
	~Dugum();
};
#endif