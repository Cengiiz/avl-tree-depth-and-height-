/*
* @main.cpp
* @txt doyasindan okunan bilgileri avl agacina atayip durumlara gore islem yapan kod.
* @1. Öğretim B
* @2. odev
* @Başlangıç Tarihi: 16.08.2021 13:20:00 Bitiş Tarihi:26.08.2021 23:59:00	
* @G201210376 Cengizhan KOCAL cengizhan.kocal@ogr.sakarya.edu.tr
*/



#ifndef KISI_HPP
#define KISI_HPP
#include<iostream>
using namespace std;

class Kisi
{
public:
    string isim;
    int yas;
    int boy;
    Kisi();
    Kisi(string ad,int ys,int by);
    ~Kisi();
};



#endif