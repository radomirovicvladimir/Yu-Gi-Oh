#pragma once
#include"Zbirka.h"
#include<iostream>
using namespace std;
class Igrac
{
	string ime;
	int zivot;
	int magija;
	Zbirka *spil, *ruka, *aktiv, *groblje;
public:
	Igrac(string i, int z, int m, Zbirka& s)
	{
		ime = i;
		zivot = z;
		magija = m;
		spil = new Zbirka(s);
		ruka = new Zbirka();
		aktiv = new Zbirka();
		groblje = new Zbirka();
	}

	string dohvIme() const { return ime; }
	int dohvZivot() const { return zivot; }
	int dohvMagija() const { return magija; }
	Zbirka* dohvSpil() const { return spil; }
	Zbirka* dohvRuka() const { return ruka; }
	Zbirka* dohvAktiv() const { return aktiv; }
	Zbirka* dohvGroblje() const { return groblje; }

	bool proveraZ() const { return zivot > 0; }
	bool proveraM(int k) { return (magija - k) >= 0; }
	bool oduzmiM(Karta &k);
	Igrac& oduzmiZ(int i);
	bool aktiviraj(Karta &k);  //da li mozemo da aktiviramo kartu na osnovu magicnih poena kojih imamo
	void porazen() const
	{
		if (zivot == 0)
			cout << "Porazen: " << ime << endl;
	}


};
