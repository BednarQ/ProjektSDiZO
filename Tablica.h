/*
 * Tablica.h

 *
 *  Created on: 10.03.2017
 *      Author: root
 */
#include <iostream>
using namespace std;

class Tablica{
private:

	  int rozmiar;
	  int *tablica;
public:
	Tablica();
	void zaladujPlik();
	void wyswietlTablice();
	void dodajElementPoczatek(int element);
	void dodajElementKoniec(int element);
	void dodajElementLosowo(int element);
	void usunElementTablica();
	void znajdzElementTablicy();
	int getValue(int element);
	int getSize();
};
