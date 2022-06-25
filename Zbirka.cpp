#include "Zbirka.h"
#include <cstdlib>
#include <ctime>

void Zbirka::kopiraj(const Zbirka & z)
{
	prvi = posl = nullptr;
	Elem*tek;
	for (tek = z.prvi; tek; tek = tek->sled)
	{
		Elem* novi = new Elem(tek->karta);
		if (!prvi)
			prvi = novi;
		else
			posl->sled = novi;
		posl = novi;
	}

}
void Zbirka::premesti(Zbirka & z)
{
	prvi = z.prvi;
	z.prvi = nullptr;
}
Zbirka & Zbirka::operator=(const Zbirka & z)
{
	Elem* stari;
	while (prvi)
	{
		stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	kopiraj(z);
	return *this;

}
Zbirka & Zbirka::operator=(Zbirka && z)
{
	Elem* stari;
	while (prvi)
	{
		stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	premesti(z);

	return *this;
}
Zbirka::~Zbirka()
{
	Elem* stari;
	while (prvi)
	{
		stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
}

int Zbirka::dohvBroj()
{
	int i = 0;
	for (Elem* tek = prvi; tek; tek=tek->sled)
		++i;
	return i;
}

Zbirka & Zbirka::dodaj(Karta & k)
{
	Elem* novi = new Elem(&k);
	posl = (prvi ? posl->sled : prvi) = novi;
	return *this;
}

Karta* Zbirka::operator[](int index) const
{
		int i = 1;
		for (Elem* tek = prvi; tek; tek = tek->sled, ++i)
			if (i == index) { return tek->karta; }
		return nullptr;
}

Karta * Zbirka::dohvKartu(int ID) const
{
	Elem* tek;
	for (tek = prvi; tek; tek = tek->sled)
		if (tek->karta->dohvID() == ID)
			return tek->karta;
	return nullptr;

}

void Zbirka::operator()(int index)
{
	if (index == 1) { Elem* t = prvi; prvi = prvi->sled; delete t; }
	else {
		int i = 2;
		for (Elem *tek = prvi->sled, *pret = prvi; tek; pret = tek, tek = tek->sled, ++i)
			if (i == index) {
				pret->sled = tek->sled;
				delete tek;
				break;
			}
		if (i != index) exit(2);
	}
}

//Karta * Zbirka::izbaciKartu(int ID)
//{
//	Elem* tek = nullptr;
//	Elem *preth = nullptr;
//	for (tek = prvi; tek; preth = tek, tek = tek->sled)
//		if (tek->karta->dohvID() == ID)
//		{
//			if (preth == nullptr)
//			{
//				if (prvi == posl)
//					posl = nullptr;
//				prvi = tek->sled;
//				return tek->karta;
//			}
//			else
//			{
//				preth->sled = tek->sled;
//				tek->sled = nullptr;
//				return tek->karta;
//			}
//		}
//	return nullptr;
//}

//Karta* Zbirka::operator()(int index)
//{
//	Elem*tek = prvi;
//	Elem *preth = nullptr;
//
//	while (index > 1)
//	{
//		if (!tek) break;
//		preth = tek;
//		tek = tek->sled;
//		index--;
//	}
//	if (tek)
//	{
//		if (preth == nullptr)
//		{
//			if (prvi == posl)
//				posl = nullptr;
//			prvi = tek->sled;
//			return tek->karta;
//		}
//		else
//		{
//			preth->sled = tek->sled;
//			tek->sled = nullptr;
//			return tek->karta;
//		}
//	}
//	return nullptr;
//}



void Zbirka::izbaciKartu(int ID)
{
	if (this->prvi == nullptr) cout << "nullptr";
	else
	{
		if (prvi->karta->dohvID() == ID) { Elem*t = prvi; prvi = prvi->sled; delete t; }
		else
		{
			for (Elem* tek = prvi->sled, *pret = prvi; tek; pret = tek, tek = tek->sled)
				if (tek->karta->dohvID() == ID) {
					pret->sled = tek->sled;
					delete tek;
					break;
				}
		}
	}
}

void Zbirka::operator~()
{
	srand(time(NULL));
	int r = rand() % dohvBroj()+1;

	if (r == 1) { Elem* t = prvi; prvi = prvi->sled; delete t; }
	else {
		int i = 2;
		for (Elem *tek = prvi->sled, *pret = prvi; tek; pret = tek, tek = tek->sled, ++i)
			if (i == r) {
				pret->sled = tek->sled;
				delete tek;
				break;
			}
	}
}


//Karta * Zbirka::operator~()
//{
//	srand(time(NULL));
//	int r = rand() % dohvBroj() + 1;
//	return izbaciKartu(r);
//
//}