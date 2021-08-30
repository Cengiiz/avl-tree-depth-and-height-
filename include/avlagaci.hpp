/*
* @main.cpp
* @txt doyasindan okunan bilgileri avl agacina atayip durumlara gore islem yapan kod.
* @1. Öğretim B
* @2. odev
* @Başlangıç Tarihi: 16.08.2021 13:20:00 Bitiş Tarihi:26.08.2021 23:59:00	
* @G201210376 Cengizhan KOCAL cengizhan.kocal@ogr.sakarya.edu.tr
*/




#ifndef AVLAGACI_HPP
#define AVLAGACI_HPP
#include<dugum.hpp>
#include <cmath>
using namespace std;

class AVLTree
{
private:
	
	Dugum *AraveEkle(Dugum *alt_Dugum,const int &yeni, Kisi* kisi);
	Dugum *SolCocukIleDegistir(Dugum *alt_Dugum); // Sağa dönüş
	Dugum *SagCocukIleDegistir(Dugum *alt_Dugum); // Sola dönüş
	void Inorder(Dugum *alt_Dugum) const;
	void Preorder(Dugum *alt_Dugum) const;
	void Postorder(Dugum *alt_Dugum) const;
	void SeviyeyiYazdir(Dugum *alt_Dugum, int seviye) const;
	int Yukseklik(Dugum *alt_Dugum) const;
	bool DugumSil(Dugum *&alt_Dugum);
	bool Ara(Dugum *alt_Dugum, const int &aranan);
public:
	Dugum *root;
	
	AVLTree();
	void Guncelle(Dugum *alt_Dugum,int seviye,int svy);
	void Stackguncelle(int sycc);
	bool Bosmu() const;
	void Ekle(Kisi* kisi);
	void Inorder() const;
	void Preorder() const;
	void Postorder() const;
	void Levelorder() const;
	bool Arama(const int &aranan);
	void Temizle();
	int Yukseklik() const;
	void Seviye(int dgr);
	void Goster();
	~AVLTree();
};

#endif