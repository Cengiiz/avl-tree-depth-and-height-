/*
* @main.cpp
* @txt doyasindan okunan bilgileri avl agacina atayip durumlara gore islem yapan kod.
* @1. Öğretim B
* @2. odev
* @Başlangıç Tarihi: 16.08.2021 13:20:00 Bitiş Tarihi:26.08.2021 23:59:00	
* @G201210376 Cengizhan KOCAL cengizhan.kocal@ogr.sakarya.edu.tr
*/



#include <dugum.hpp>
using namespace std;
Dugum::Dugum(int by)
{
	kisi.boy=by;
	kisi.isim ="";
	kisi.yas=0;
	sol = NULL;
	sag = NULL;
	yukseklik=new yigit();
	derinlik=new yigit();

}
Dugum::Dugum(Kisi* insan)
	{
		kisi.isim = insan->isim;
		kisi.boy=insan->boy;
		kisi.yas=insan->yas;
		sol = NULL;
		sag = NULL;
		yukseklik=new yigit();
		derinlik=new yigit();
	}
Dugum::Dugum(Kisi insan, Dugum *sl, Dugum *sg)
	{
		kisi.isim = insan.isim;
		kisi.boy=insan.boy;
		kisi.yas=insan.yas;
		sol = sl;
		sag = sg;
		derinlik=new yigit(); // eklenen her yeni düğüm ilk önce yaprak olarak eklenir.
	}
Dugum::~Dugum()
	{
		delete yukseklik;
		delete derinlik;
	}