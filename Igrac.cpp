#include "Igrac.h"

/*Igrac::~Igrac()
{

}*/

bool Igrac::oduzmiM(Karta & k)
{
	if (proveraM(k.dohvEnergiju()))
	{
		magija -= k.dohvEnergiju();
		return true;
	}
	return false;
}

Igrac & Igrac::oduzmiZ(int i)
{
	if (proveraZ())
		zivot -= i;
	return *this;

}

bool Igrac::aktiviraj(Karta & k)
{
	if (oduzmiM(k))
	{
		ruka->izbaciKartu(k.dohvID());
		aktiv->dodaj(k);
		return true;
	}
	else
		return false;

}
