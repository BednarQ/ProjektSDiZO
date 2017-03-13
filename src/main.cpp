#include <iostream>
#include "Tablica.h"
#include "Lista.h"
#include "Heap.h"
#include <time.h>

using namespace std;

typedef enum {
	S_TAB = 1, S_LIST, S_KOP, S_DEF, S_EXIT
} state;

int main() {
	clock_t start,finish;
	double duration;
	Lista lista;
	Tablica tablica;
	Heap heap;
	state stan = state::S_DEF;
	bool isRunning = true;

	while (isRunning) {		//główny
		cout
				<< "                      Struktury Danych i Zlozonosc Obliczeniowa\n"
						"                        Autor: Mateusz Bednarek 209978\n"
						"Program pozwala na wykonywanie operacji na tablicy, liscie dwukierunkowej oraz kopcu binarnym.\n\n\n"
				<< endl;

		cout << "Wybierz podmenu:\n"
				"1 - Tablica\n"
				"2 - Lista Dwukierunkowa\n"
				"3 - Kopiec Binarny\n"
				"4 - Wyjście\n" << endl;

		int x;
		cin >> x;

		stan = (state) x;

		if (stan == state::S_EXIT) {
			exit(1);
		}

		while (stan == state::S_TAB) {
			int wybor0;
			cout << "\n\nMenu glowne programu dla operacji na tablicy.\n"
					"1 - Zaladuj tablice z pliku\n"
					"2 - Dodaj element do tablicy\n"
					"3 - Usun element z tablicy\n"
					"4 - Znajdz element w tablicy\n"
					"5 - Wyswietl cala strukture\n"
					"6 - Powrot do menu glownego\n"
					"0 - Wyjscie z programu" << endl;
			cin >> wybor0;
			switch (wybor0) {
			case 1:
				tablica.zaladujPlik();
				break;
			case 2:
				tablica.dodajElement();
				break;
			case 3:
				tablica.usunElementTablica();
				break;
			case 4:
				tablica.znajdzElementTablicy();
				break;
			case 5:
				tablica.wyswietlTablice();
				break;
			case 6:
				stan = state::S_DEF;
				break;
			case 0:
				exit(1);
			default:
				cout << "\nNie ma takiej opcji.\n" << endl;
				break;
			}
		}

		while (stan == state::S_LIST) {
			int wybor0;
			cout << "Menu glowne programu dla operacji na liscie.\n"
					"1 - Zaladuj liste z pliku\n"
					"2 - Dodaj na poczatek listy\n"
					"3 - Dodaj na koniec listy\n"
					"4 - Dodaj w losowe miejsce listy\n"
					"5 - Usun element z listy\n"
					"6 - Znajdz element w liscie\n"
					"7 - Wyswietl cala strukture rosnaco\n"
					"8 - Wyswietl cala strukture malejaco\n"
					"9 - Powrot do menu glownego\n"
					"0 - Wyjscie z programu" << endl;

			cin >> wybor0;
			switch (wybor0) {

			case 1:
				lista.load_from_file();
				break;
			case 2:
				lista.insert_beginning();
				break;
			case 3:
				lista.insert_end();
				break;
			case 4:
				lista.insert_random();
				break;
			case 5:
				lista.delete_node();
				break;
			case 6:
				lista.search();
				break;
			case 7:
				lista.display_asc();
				break;
			case 8:
				lista.display_rev();
				break;
			case 9:
				stan = state::S_DEF;
				break;
			case 0:
				exit(1);
			default:
				cout << "\nNie ma takiej opcji.\n" << endl;
				break;
			}
		}
		while (stan == state::S_KOP) {
			int wybor0;
			cout << "Menu glowne programu dla operacji na kopcu.\n"
					"1 - Zaladuj kopiec z pliku\n"
					"2 - Dodaj element do kopca\n"
					"3 - Usun minimalny element kopca\n"
					"4 - Pokaz minimalny element kopca\n"
					"5 - Wyszukaj element w kopcu\n"
					"6 - Wyswietl strukture kopca\n"
					"7 - Powrot do menu glownego\n"
					"8 - Wyjscie z programu\n" << endl;
			int choice, element;
			cin >> choice;
			switch (choice) {
			case 1:
				start = clock();
				heap.loadFromFile();
				finish = clock();
				duration = (double)(finish-start) / CLOCKS_PER_SEC;
				cout<<duration;
				break;
			case 2:
				cout << "\nWprowadz wartosc elementu, ktory chcesz wprowadzic: ";
				cin >> element;
				heap.Insert(element);
				break;
			case 3:
				heap.DeleteMin();
				break;
			case 4:
				if (heap.ExtractMin() == -1) {
					cout << "\nKopiec jest pusty\n" << endl;
				} else
					cout << "\nMinimalny element to: " << heap.ExtractMin() << endl;
				break;
			case 5:
				cout << "\nJaki element chcesz znalezc? ";
				cin >> element;
				start = clock();
				heap.SearchElement(element);
				finish = clock();
				duration = (double)(finish-start) / CLOCKS_PER_SEC;
			    cout<<duration;
				break;
			case 6:
				heap.DisplayHeap();
				break;
			case 7:
				stan = state::S_DEF;
				break;
			case 8:
				exit(1);
			default:
				cout << "\nBrak takiej opcji\n" << endl;
			}
		}
	}
	return 0;
}

