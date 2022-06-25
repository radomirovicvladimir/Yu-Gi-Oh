#include "Carobnjak.h"

void Carobnjak::upotrebiKartu(Igrac * igrac1, Igrac * igrac2)
{
	Karta *min = new Borac("Borislav", 100, 100);
	int ID=-1;
	int i = igrac2->dohvAktiv()->dohvBroj();
	//cout << "1AAHAHAHAHAHHA" << this->dohvSnagu();
	for (; i > 0; i--) {
		if (igrac2->dohvAktiv()->operator[](i)->dohvKategoriju() == "BORAC")
		{
			if (min > igrac2->dohvAktiv()->operator[](i))
			{
				min = igrac2->dohvAktiv()->operator[](i);
				ID = igrac2->dohvAktiv()->operator[](i)->dohvID();
			}
		}
	}
	if (this > min) {
		//cout << "2AAHAHAHAHAHHA" << this->dohvSnagu();
		igrac2->dohvGroblje()->dodaj(*min);
		igrac2->dohvAktiv()->izbaciKartu(ID);
		igrac2->oduzmiZ(2 * this->dohvSnagu());
	}
}
