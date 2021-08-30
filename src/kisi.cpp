/*
* @main.cpp
* @txt doyasindan okunan bilgileri avl agacina atayip durumlara gore islem yapan kod.
* @1. Öğretim B
* @2. odev
* @Başlangıç Tarihi: 16.08.2021 13:20:00 Bitiş Tarihi:26.08.2021 23:59:00	
* @G201210376 Cengizhan KOCAL cengizhan.kocal@ogr.sakarya.edu.tr
*/


#include<kisi.hpp>
Kisi::Kisi()
{
    isim="";
    yas=0;
    boy=0;
}
Kisi::Kisi(string ad,int ys,int by)
{
    isim=ad;
    yas=ys;
    boy=by;
}
Kisi::~Kisi()
{

}