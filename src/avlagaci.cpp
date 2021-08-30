/*
* @main.cpp
* @txt doyasindan okunan bilgileri avl agacina atayip durumlara gore islem yapan kod.
* @1. Öğretim B
* @2. odev
* @Başlangıç Tarihi: 16.08.2021 13:20:00 Bitiş Tarihi:26.08.2021 23:59:00	
* @G201210376 Cengizhan KOCAL cengizhan.kocal@ogr.sakarya.edu.tr
*/


#include "avlagaci.hpp"

	Dugum* AVLTree::AraveEkle(Dugum *alt_Dugum, const int &yeni,Kisi* kisi)
	{
		
		// alt_Dugum = z, alt_Dugum->sol = y, yeni = x,w
		if (alt_Dugum == NULL)
		{
			alt_Dugum = new Dugum(kisi);
		}
		else if (yeni < alt_Dugum->kisi.boy||yeni == alt_Dugum->kisi.boy) // y, z'nin sol çocuğu ise
		{
			alt_Dugum->sol = AraveEkle(alt_Dugum->sol, yeni,kisi);

			if (Yukseklik(alt_Dugum->sol) - Yukseklik(alt_Dugum->sag) == 2)
			{
				// Sol Sol Durumu
				if (yeni < alt_Dugum->sol->kisi.boy) // x, y'nin sol çocuğu ise
					alt_Dugum = SolCocukIleDegistir(alt_Dugum); //sağa dönüş z
				else // Sol Sağ Durumu
				{														  
					alt_Dugum->sol = SagCocukIleDegistir(alt_Dugum->sol); // sola dönüş y
					alt_Dugum = SolCocukIleDegistir(alt_Dugum); // sağa dönüş z
				}
			}
		}
		else if (yeni > alt_Dugum->kisi.boy)
		{
			alt_Dugum->sag = AraveEkle(alt_Dugum->sag, yeni,kisi);

			if (Yukseklik(alt_Dugum->sag) - Yukseklik(alt_Dugum->sol) == 2)
			{
				// Sağ Sağ Durumu
				if (yeni > alt_Dugum->sag->kisi.boy)
					alt_Dugum = SagCocukIleDegistir(alt_Dugum);
				else
				{ // Sağ Sol Durumu
					alt_Dugum->sag = SolCocukIleDegistir(alt_Dugum->sag);
					alt_Dugum = SagCocukIleDegistir(alt_Dugum);
				}
			}
		}
		else
			; // Aynı eleman var.

		//Yüksekliği güncelle
		// Derinlik Güncelle
		
		
		return alt_Dugum;
	}
	
	Dugum* AVLTree::SolCocukIleDegistir(Dugum *alt_Dugum) // Sağa dönüş
	{
		//swap
		Dugum *tmp = alt_Dugum->sol;
		alt_Dugum->sol = tmp->sag;
		tmp->sag = alt_Dugum;

		// Yükseklikleri Güncelle
		// Derinlik Güncelle
		return tmp;
	}
	Dugum* AVLTree::SagCocukIleDegistir(Dugum *alt_Dugum) // Sola dönüş
	{
		//swap
		Dugum *tmp = alt_Dugum->sag;
		alt_Dugum->sag = tmp->sol;
		tmp->sol = alt_Dugum;

		// Yükseklikleri Güncelle
		// Derinlik Güncelle
		
		return tmp;
	}
	void AVLTree::Inorder(Dugum *alt_Dugum) const
	{
		if (alt_Dugum != NULL)
		{
			Inorder(alt_Dugum->sol);
			cout << alt_Dugum->kisi.boy << " ";
			Inorder(alt_Dugum->sag);
		}
	}
	void AVLTree::Preorder(Dugum *alt_Dugum) const
	{
		if (alt_Dugum != NULL)
		{
			cout << alt_Dugum->kisi.boy << " ";
			Preorder(alt_Dugum->sol);
			Preorder(alt_Dugum->sag);
		}
	}
	void AVLTree::Postorder(Dugum *alt_Dugum) const
	{
		if (alt_Dugum != NULL)
		{
			Postorder(alt_Dugum->sol);
			Postorder(alt_Dugum->sag);
			cout << alt_Dugum->kisi.boy << " ";
		}
	}
	void AVLTree::SeviyeyiYazdir(Dugum *alt_Dugum, int seviye) const
	{
		if (alt_Dugum == NULL)
			return;
		if (seviye == 0)
		{
			cout << alt_Dugum->kisi.isim << " ";
			cout << alt_Dugum->kisi.yas << " ";
			cout << alt_Dugum->kisi.boy << " ";
			cout << endl;
			cout<<"Yukseklik:"<<"(";
			alt_Dugum->yukseklik->Pop();cout<<")";
			cout << endl;
			cout<<"Derinlik:"<<"(";
			alt_Dugum->derinlik->Pop();cout<<")";
			cout << endl;
			
			
		}
		else
		{
			SeviyeyiYazdir(alt_Dugum->sol, seviye - 1);
			SeviyeyiYazdir(alt_Dugum->sag, seviye - 1);
		}
	}
	void AVLTree::Guncelle(Dugum *alt_Dugum,int seviye,int svy)
	{
		
		if (alt_Dugum == NULL)
			return;
		if (seviye == 0)
		{
			alt_Dugum->derinlik->Push(svy);
			alt_Dugum->yukseklik->Push(Yukseklik(alt_Dugum));
		}
		else
		{
			
			Guncelle(alt_Dugum->sol, seviye - 1,svy);
			Guncelle(alt_Dugum->sag, seviye - 1,svy);
		}
	}
	void AVLTree::Stackguncelle(int sycc)
	{
		int h=Yukseklik(root);
		for (int level = 0; level <= h; level++)
			Guncelle(root, level,level);
	}
	int AVLTree::Yukseklik(Dugum *alt_Dugum) const
	{
		if (alt_Dugum == NULL)
			return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 kisi.boylmektedir.
		return 1 + max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));
	}
	bool AVLTree::DugumSil(Dugum *&alt_Dugum)
	{
		Dugum *silinecekDugum = alt_Dugum;

		if (alt_Dugum->sag == NULL)
			alt_Dugum = alt_Dugum->sol;
		else if (alt_Dugum->sol == NULL)
			alt_Dugum = alt_Dugum->sag;
		else
		{
			silinecekDugum = alt_Dugum->sol;
			Dugum *ebeveynDugum = alt_Dugum;
			while (silinecekDugum->sag != NULL)
			{
				ebeveynDugum = silinecekDugum;
				silinecekDugum = silinecekDugum->sag;
			}
			alt_Dugum->kisi.boy = silinecekDugum->kisi.boy;
			if (ebeveynDugum == alt_Dugum)
				alt_Dugum->sol = silinecekDugum->sol;
			else
				ebeveynDugum->sag = silinecekDugum->sol;
		}
		delete silinecekDugum;
		return true;
	}
	bool AVLTree::Ara(Dugum *alt_Dugum, const int &aranan)
	{
		
		if (alt_Dugum == NULL)
			return false;
		if (alt_Dugum->kisi.boy == aranan)
			return true;
		if (aranan < alt_Dugum->kisi.boy)
		{
			return Ara(alt_Dugum->sol, aranan);
		}
		if (aranan > alt_Dugum->kisi.boy)
		{
			return Ara(alt_Dugum->sag, aranan);
		}
	}
	AVLTree::AVLTree()
	{
		root = NULL;
	}
	bool AVLTree::Bosmu() const
	{
		return root == NULL;
	}
	void AVLTree::Ekle(Kisi* kisi)
	{
		root = AraveEkle(root,kisi->boy,kisi);
	}
	void AVLTree::Inorder() const
	{
		Inorder(root);
	}
	void AVLTree::Preorder() const
	{
		Preorder(root);
	}
	void AVLTree::Postorder() const
	{
		Postorder(root);
	}
	void AVLTree::Levelorder() const
	{
		int h = Yukseklik(root);
		for (int level = 0; level <= h; level++)
			SeviyeyiYazdir(root, level);
	}
	bool AVLTree::Arama(const int &aranan)
	{
		return Ara(root, aranan);
	}
	void AVLTree::Temizle()
	{
		while (!Bosmu())
			DugumSil(root);
	}
	int AVLTree::Yukseklik() const
	{
		return Yukseklik(root);
	}
	void AVLTree::Seviye(int dgr)
	{
		SeviyeyiYazdir(root, dgr);
	}
	void AVLTree::Goster()
	{

	}
	AVLTree::~AVLTree()
	{
		Temizle();
	}