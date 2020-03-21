/*
 *Serkan Can Caglayan
 * 7.04.2019
 */
#include "sozluk.h"
#include <iostream>
#include <vector>
#include "kayit.h"
using namespace std;

Sozluk::Sozluk()
{
	kayitlar=nullptr;
	toplamKayitSayisi=0;
}
Sozluk::Sozluk(const Kayit &kayit)
{
	kayitlar= new Kayit[1];
	if(kayitlar != nullptr)
		kayitlar[0]=kayit;
	toplamKayitSayisi=1;
}
Sozluk::Sozluk(const Sozluk &other)
{
	if(kayitlar != nullptr)
		delete[] kayitlar;
		
	toplamKayitSayisi=other.toplamKayitSayisi;
	kayitlar=new Kayit [toplamKayitSayisi];
	
	if(kayitlar == nullptr)
		exit(-1);
	for(unsigned i=0;i<toplamKayitSayisi;i++)
		kayitlar[i]=other.kayitlar[i];
}

Sozluk::~Sozluk()
{
	if(kayitlar != nullptr)
		delete[] kayitlar;
}
Sozluk::Sozluk(const vector<Kayit> & kayitlar)
{
	this->kayitlar=new Kayit[kayitlar.size()];
	if(this->kayitlar == nullptr) exit(-1);
	
	for(unsigned i=0;i<kayitlar.size();i++)
		this->kayitlar[i]=kayitlar[i];
}

Kayit & Sozluk::operator[](const string & kelime)
{
	for(unsigned i=0;i<toplamKayitSayisi;i++)
		if(kayitlar[i].getter_Kelime() == kelime)
			return kayitlar[i];
}

Sozluk & Sozluk::operator=(const Sozluk &other)
{
	if(kayitlar != nullptr)
		delete[] kayitlar;
	toplamKayitSayisi=other.toplamKayitSayisi;
	kayitlar=new Kayit[toplamKayitSayisi];
	if(kayitlar == nullptr)
		exit(-1);
	for(unsigned i=0;i<toplamKayitSayisi;i++)
		kayitlar[i]=other.kayitlar[i];
	
	return *this;
	
}
ostream & operator<<(ostream & o, const Sozluk & s)
{
	int toplamAciklama=0;
	o<<"Toplam kayit sayisi:"<<s.toplamKayitSayisi<<endl;
	for(unsigned i=0;i<s.toplamKayitSayisi;i++)
		toplamAciklama+=s.kayitlar[i].getter_Aciklamasize();
	o<<"Toplam aciklama sayisi:"<<toplamAciklama<<endl;
	return o;
}
bool  Sozluk::operator<(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	if(toplamAciklama_this > toplamAciklama_other)
		return false;
	return true;
}
bool Sozluk::operator>(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	if(toplamAciklama_this > toplamAciklama_other)
		return true;
	return false;
}
bool  Sozluk::operator<=(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	if(toplamAciklama_this >= toplamAciklama_other)
		return false;
	return true;
}
bool  Sozluk::operator>=(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	if(toplamAciklama_this >= toplamAciklama_other)
		return true;
	return false;
}
bool  Sozluk::operator==(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
		
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	
	if(toplamAciklama_this == toplamAciklama_other)
		return true;
	return false;
}
bool  Sozluk::operator!=(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
		
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
		
	if(toplamAciklama_this != toplamAciklama_other)
		return true;           
	return false;
}

Sozluk & Sozluk::operator+=(const Sozluk & digerSozluk)
{
	Sozluk temp;
	temp.kayitlar=new Kayit[toplamKayitSayisi];
	if(temp.kayitlar == nullptr) exit(-1);
	temp.toplamKayitSayisi=toplamKayitSayisi;
	for(unsigned x=0;x<temp.toplamKayitSayisi;x++)
		temp.kayitlar[x]=kayitlar[x];
		
	if(kayitlar != nullptr)
		delete[] kayitlar;
	
	toplamKayitSayisi=digerSozluk.toplamKayitSayisi+temp.toplamKayitSayisi;
	kayitlar=new Kayit[toplamKayitSayisi];
	if(kayitlar == nullptr) exit(-1);
	
	for(unsigned i=0;i<temp.toplamKayitSayisi;i++)
		kayitlar[i]=temp.kayitlar[i];
		
	for(unsigned j=0;j<digerSozluk.toplamKayitSayisi;j++)
		kayitlar[temp.toplamKayitSayisi+j]=digerSozluk.kayitlar[j];
	return *this;
}
Sozluk Sozluk::operator+(const Sozluk & digerSozluk)
{
	Sozluk temp;
	temp.toplamKayitSayisi=toplamKayitSayisi+digerSozluk.toplamKayitSayisi;
	temp.kayitlar=new Kayit[temp.toplamKayitSayisi];
	if(temp.kayitlar == nullptr) exit(-1);
	
	for(unsigned i=0;i<toplamKayitSayisi;i++)
		temp.kayitlar[i]=kayitlar[i];
		
	for(unsigned j=0;j<digerSozluk.toplamKayitSayisi;j++)
		temp.kayitlar[toplamKayitSayisi+j]=digerSozluk.kayitlar[j];
		
	return temp;
}
Sozluk & Sozluk::operator-=(const string & kelime)
{
	for(unsigned i=0;i<toplamKayitSayisi;i++)
		if(kelime == kayitlar[i].getter_Kelime())
			kayitlar[i].deleter();
	return *this;
}

Sozluk & Sozluk::operator-=(const Kayit & kayit)
{
	for(unsigned i=0;i<toplamKayitSayisi;i++)
	{
		if(kayit.getter_Kelime() == kayitlar[i].getter_Kelime())
		{
			if(kayitlar[i].getter_Aciklamasize() == 0)
				delete &kayitlar[i];
			else
				kayitlar[i].deleter();
		}		
	}
	return *this;
}


