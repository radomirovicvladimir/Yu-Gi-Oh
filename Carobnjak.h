#pragma once
#include<iostream>
#include<string>
#include"Borac.h"
#include"Igrac.h"
using namespace std;

class Carobnjak :public Borac {
	string kategorija = "CAROBNJAK";
	bool upotrebljena;
	int snaga;
	void pisi(ostream& it) const override { Borac::pisi(it); it << "-CAROBNJAK"; }
public:
	Carobnjak(string i, int e, int s) :Borac(i, e, s) {}
	void upotrebiKartu(Igrac* igrac1, Igrac* igrac2) override;
	string dohvKategoriju() const override { return kategorija; }
};