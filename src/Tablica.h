/*
 * Tablica.h

 *
 *  Created on: 10.03.2017
 *      Author: root
 */
#include <iostream>
using namespace std;

class Tablica{
public:
	Tablica();
	int rozmiar=0;
	int* tablica = new int[rozmiar];
	void zaladujPlik();
	void wyswietlTablice();
	void dodajElement();
	void usunElementTablica();
	void znajdzElementTablicy();
};
