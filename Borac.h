#pragma once
#include<iostream>
#include<string>
#include"Karta.h"
using namespace std;

class Borac :public Karta {
	string kategorija = "BORAC";
	bool upotrebljena;
	int snaga;
public:
	Borac(string i, int e, int s) :Karta(i, e), snaga(s) {}
	void upotrebiKartu(Igrac* igrac1, Igrac* igrac2) override {}
	string dohvKategoriju() const override { return kategorija; }
	int dohvSnagu() const { return snaga; }
	friend bool operator>(const Borac& b1, const Borac& b2) { return b1.snaga > b2.snaga; }
protected:
	void pisi(ostream& it) const override { Karta::pisi(it); it << " (snaga: " << snaga << " )"; }
};