/*
* @main.cpp
* @txt doyasindan okunan bilgileri avl agacina atayip durumlara gore islem yapan kod.
* @1. Öğretim B
* @2. odev
* @Başlangıç Tarihi: 16.08.2021 13:20:00 Bitiş Tarihi:26.08.2021 23:59:00	
* @G201210376 Cengizhan KOCAL cengizhan.kocal@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <avlagaci.hpp>
using namespace std;
int main()
{
    AVLTree *agac = new AVLTree();
    fstream dosya;
    dosya.open("kisiler.txt");
    string satir="";
    int st=0;
    if (dosya.is_open())
    {
        while (dosya>>satir)
        {
            st++;
        }
    dosya.close();
    }
    //cout<<st;
    Kisi kisiler[st];
    //Kisi *dizi{ new Kisi[st]{} };
    dosya.open("kisiler.txt");
    satir="";
    string bilgiler[3];
    Kisi **dizi = new Kisi*[st]();

    for (int i = 0 ; i < st ; i++)
        {
	        dizi[i] = new Kisi();
        }
    if (dosya.is_open())
    {
        
        for(int a=0;a<st;a++)
        {
            
            getline(dosya,satir);
            stringstream ss(satir);
            getline(ss,bilgiler[0],'#');
            getline(ss,bilgiler[1],'#');
            getline(ss,bilgiler[2]);
            dizi[a]->isim=bilgiler[0];
            dizi[a]->yas=stoi(bilgiler[1]);
            dizi[a]->boy=stoi(bilgiler[2]);
            
        }
        
        
        
        dosya.close();
    }
    for (int i = 0; i < st; i++)
    {
        agac->Ekle(dizi[i]);
        agac->Stackguncelle(0);
    }
    agac->Levelorder();

    agac->~AVLTree();
    delete dizi;

    return 0;

}