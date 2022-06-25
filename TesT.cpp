//#include<iostream>
//#include<string>
//#include"Carolija.h"
//#include"Carolija.h"
//#include"Carobnjak.h"
//using namespace std;
//int main() {
//	Carolija c("Obelisk", 10);
//	cout << c << endl;
//	cout << "Energija:" << c.dohvEnergiju() << endl;
//	cout << "Kategorija:" << c.dohvKategoriju() << endl;
//	Borac c1("Celavi portir", 7, 3);
//	Borac c2("Radioaktivna tetkica", 1, 10);
//	cout << c1 << endl;
//	cout << "Energija:" << c1.dohvEnergiju() << endl;
//	cout << "Kategorija:" << c1.dohvKategoriju() << endl;
//	cout << "Snaga:" << c1.dohvSnagu() << endl;
//	if (c1 > c2) cout << "Jaci je celavko";
//	else cout << "Tetka ga ubi bez metka";
//	Carobnjak cr1("Merlin", 10, 100);
//	cout << cr1 << endl;
//	cout << "Energija:" << cr1.dohvEnergiju() << endl;
//	cout << "Kategorija:" << cr1.dohvKategoriju() << endl;
//	cout << "Snaga:" << cr1.dohvSnagu() << endl;
//	Carobnjak cr2("Agumon", 2, 99);
//	if (cr1 > cr2)cout << "Merlin je jaci";
//	else cout << "Agumon je jaci";
//	if (cr1 > c2) cout << "Merlincic";
//	system("pause");
//	return 0;
//}

#include"Carolija.h"
#include"Carobnjak.h"
#include"Zbirka.h"
#include"Igrac.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	/*Carolija c("zmaj", 30);
	cout << c << endl;
	Borac b("zmaj1", 45, 9);
	cout << b;
	cout << "-------------" << endl;
	Carolija c1("zmaj1", 30);
	Carolija c2("zmaj2", 35);
	Carolija c3("zmaj3", 40);
	Borac b1("zmaj4", 50, 10);
	Borac b2("zmaj5", 55, 11);
	Borac b3("zmaj6", 60, 12);
	Borac b4("zmaj7", 70, 14);
	cout << c1 << c2 << c3 << b1 << b2 << b3 << endl;
	Zbirka z;
	z.dodaj(c1); z.dodaj(c2); z.dodaj(c3); z.dodaj(b1); z.dodaj(b2); z.dodaj(b3); z.dodaj(b4);
	cout << z;
	cout << z.dohvBroj() << endl;
	z(5);
	cout << z << "NAKON " << endl;
	srand(time(NULL));
	int r = rand() % z.dohvBroj() + 1;
	cout << r;
	~z;
	cout << z<<"ABRAKADABRA";*/
	//cout << z;
	//cout << *z[1];

	Karta* k1 = new Borac("Dama", 13, 20);
	Karta * k2 = new Carobnjak("Dvojka", 2, 30);
	//cout << k1 << k2;
	//cout << k1.kategorija();

	Carolija c1("Vatra", 5);
	Carolija c2("Voda", 5);
	//cout << c1 << c2;
	//cout << c1.kategorija();

	Borac b1("Strelac", 8, 10);
	Borac b2("Macevalac", 10, 14);
	//cout << b1 << b2;
	//cout << b1.kategorija();

	Carobnjak ca1("Merlin", 10, 20);
	Carobnjak ca2("Hary", 9, 25);
	//cout << ca1;

	Zbirka spil1;
	Zbirka spil2;
	spil1.dodaj(*k1);
	spil1.dodaj(c2);
	spil1.dodaj(*k2);
	spil1.dodaj(ca2);

	spil2.dodaj(b2);
	spil2.dodaj(c1);
	spil2.dodaj(b1);
	spil2.dodaj(ca1);

	cout << spil1 << spil2;

	Igrac player1("Tea", 3, 20, spil1);
	Igrac player2("Nena", 3, 20, spil2);
	player1.dohvSpil()->dodaj(c2);
	cout << "IDEMO OPET: ";
	cout << *player1.dohvSpil() << endl;
	cout << "DRUGI SPIL: ";
	cout << *player2.dohvSpil() << endl;
	cout << "Zivot pre napada: ";
	cout << player2.dohvZivot() << endl;;


	player2.dohvAktiv()->dodaj(b2);
	player2.dohvRuka()->dodaj(b1);
	player2.dohvSpil()->izbaciKartu(b1.dohvID());
	//player1.dohvSpil()->dohvKartu(ca2.dohvID());
	cout << *player2.dohvRuka()<<"Dohvaceno"<<endl;
	player2.aktiviraj(b1);
	player2.dohvAktiv()->dodaj(c2);
	cout <<"AKTIVNA RUKA"<< *player2.dohvAktiv();
	ca2.upotrebiKartu(&player1, &player2);
	cout << "Zivot posle napada: ";
	cout << player2.dohvZivot();

	/*cout << ca2;
	cout << b2;*/


	/*cout << endl;
	cout << z;*/
	/*cout << "Dohvatanje:"<<endl;
	cout << *z[3];
	cout << *z.dohvKar(3);
	cout << endl;*/

	/*cout << "Izbacivanje:" << endl;
	z(4);
	cout << endl;
	cout << z;
	z.izbaciKar(4);
	cout << endl;
	cout << z;
	~z;
	cout << endl;
	cout << z;*/


	system("pause");
}