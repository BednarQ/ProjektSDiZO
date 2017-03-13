/*
 * Tablica.cpp
 *
 *  Created on: 10.03.2017
 *      Author: root
 */

//============================================================================
// Name        : SdizoP1.cpp
// Author      : Mateusz Bednarek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : Tablica.cpp
// Author      : Mateusz Bednarek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "Tablica.h"


using namespace std;

Tablica::Tablica(){
	this -> rozmiar;
	this -> tablica;
}

void Tablica::zaladujPlik(){
	int size;
	ifstream inputFile("test.txt");
	inputFile >> size;
	rozmiar = size;
	tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++) {
	        inputFile >> tablica[i];
	}
}

void Tablica::wyswietlTablice(){
	for(int i=0;i<rozmiar;i++){
		cout << tablica[i] << " ";
	}

}
void Tablica::dodajElement(){
	srand( time( NULL ) );
	rozmiar++;
	int element;
	int wybor;
	int pos;
	int *temp;
	temp = new int[rozmiar];
	cout<< "\nJaki element chcesz dodac?"<<endl;;
	cin >> element;
	cout << "W ktorym miejscu dodac element?\n"
			"1 - Poczatek\n"
			"2 - Koniec\n"
			"3 - Losowe miejsce"<<endl;
	cin >> wybor;
	switch(wybor){
	case 1:
		pos = 0;
		break;
	case 2:
		pos = rozmiar-1;
		break;
	case 3:
		pos = rand() % (rozmiar - 1);
		break;
	default:
		cout<<"Zly wybor";
		break;
	}

	for(int i =0;i<pos;i++){
		temp[i]=tablica[i];
	}
	temp[pos] = element;
	for(int i=pos;i<rozmiar;i++){
		temp[i+1]=tablica[i];
	}
	delete [] tablica;
	tablica = temp;
}
void Tablica::usunElementTablica(){
	srand( time( NULL ) );
	rozmiar--;
	int pos;
	int* temp;
	int wybor;
	temp = new int[rozmiar];
	cout << "\nKtory element usunac?\n"
			"1 - Poczatek\n"
			"2 - Koniec\n"
			"3 - Losowe miejsce"<<endl;
	cin >> wybor;
	switch(wybor){
		case 1:
			pos = 0;
			break;
		case 2:
			pos = rozmiar;
			break;
		case 3:
			pos = rand() % (rozmiar - 1);
			break;
		default:
			cout<<"Zly wybor";
			break;
	}
	for(int i=0;i<pos;i++){
		temp[i] = tablica[i];
	}
	for(int i=pos;i<rozmiar;i++){
		temp[i]=tablica[i+1];
	}
	delete [] tablica;
	tablica = temp;

}

void Tablica::znajdzElementTablicy(){
	int element;
	int index = -1;
	cout<<"Jaki element chcesz znalezc?"<<endl;
	cin >> element;

	cout << "\nSzukanie elemntu "<<element<<endl;
	for(int i=0;i<rozmiar;i++){
		if(tablica[i]==element){
			index = i;
			cout << "Element znaleziony na pozycji "<<index+1;
		}
		}
	if(index == -1){
		cout << "Brak podanego elementu w tablicy";
	}
}

/*int main(){
Tablica tablica;
tablica.zaladujPlik();
tablica.wyswietlTablice();
}*/



