#pragma once
#include<iostream>
#include<string>
using namespace std;
class Igrac;
class Karta {
private:
	string ime;
	int energija;
	static int posID;
		int ID = ++posID;
public:
	Karta(string i, int e) :ime(i), energija(e){}
	Karta(const Karta&) = delete;
	Karta& operator=(const Karta&) = delete;
	//Metode
	string dohvIme() const { return ime; }
	int dohvEnergiju() const { return energija; }
	int dohvID() const { return ID; }
	virtual void upotrebiKartu(Igrac* igrac1,Igrac* igrac2) = 0;
	virtual string dohvKategoriju() const = 0;
protected:
	virtual void pisi(ostream& it) const { it << " [ " << ID << " ] " << ime << " ( " << energija << " ) "; }
	friend ostream& operator<<(ostream& it, const Karta& k) { k.pisi(it); return it; }
};