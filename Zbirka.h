#pragma once
#include"Karta.h"
#include<iostream>
using namespace std;
class Zbirka
{
	struct Elem
	{
		Karta* karta;
		Elem* sled;
		Elem(Karta *k) :karta(k), sled(nullptr) {}
	};

	Elem *prvi=nullptr, *posl=nullptr;
	void kopiraj(const Zbirka& z);
	void premesti(Zbirka& z);
public:
	Zbirka() { prvi = nullptr; posl = nullptr; }
	~Zbirka();
	Zbirka(const Zbirka& z) { kopiraj(z); }
	Zbirka(Zbirka&& z) { premesti(z); }
	Zbirka& operator=(const Zbirka& z);
	Zbirka& operator=(Zbirka&&);
	int dohvBroj();
	//int dohvN() const { return n; }
	Zbirka& dodaj(Karta& k);
	Karta* operator[](int index) const;
	Karta* dohvKartu(int ID) const;
	//Karta* operator()(int index);
	void operator()(int index);
	//Karta* izbaciKartu(int ID); vlado
	void izbaciKartu(int ID);
	//Karta* operator~();
	void operator~();

	void pisi(ostream&it) const
	{
		Elem* tek;
		for (tek = prvi; tek; tek = tek->sled)
			it << *(tek->karta) << endl;
	}
	friend ostream& operator<<(ostream& it, const Zbirka& z)
	{
		z.pisi(it);
		return it;
	}

};