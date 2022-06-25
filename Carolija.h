#pragma once
#include<iostream>
#include<string>
#include"Karta.h"
using namespace std;

class Carolija :public Karta {
	string kategorija="CAROLIJA";
	bool upotrebljena;
	void pisi(ostream& it) const override { Karta::pisi(it); }
public:
	Carolija(string i, int e) :Karta(i, e) {}
	void upotrebiKartu(Igrac* igrac1, Igrac* igrac2) override {}
	string dohvKategoriju() const override { return kategorija; }
};