#include<iostream>
#include "Lista.h"
#include <fstream>
using namespace std;

int counter;

void Lista::load_from_file() {
	ifstream file;
	file.open("test.txt");
	if (file.good()) {
		file >> counter;
		for (int i = 0; i < counter; i++) {
			list *temp = new list;
			file >> temp->data;
			if (first == NULL) {
				temp->prev = NULL;
				temp->next = NULL;
				first = temp;
				last = temp;
			} else {
				temp->prev = NULL;
				first->prev = temp;
				temp->next = first;
				first = temp;
			}
		}
		cout << "Poprawnie dodano " << counter << " liczb do listy" << endl;
	} else {
		cout << "Nie mozna zaladowac pliku." << endl;
	}
}
void Lista::search() {
	list *search = new list;
	search = first;
	int element;
	cout<<"Jaki element chcesz wyszukac?"<<endl;
	cin >> element;
	for(int i=0;i<counter;i++){
		if(search->data == element){
			cout<<"Znaleziono element "<<element<<endl;
			break;
		}
		search = search->next;
	}
}
void Lista::replace() {
	list *replace = new list;
	int index, newData;
	cout << "Wybierz numer elementu do zamiany." << endl;
	cin >> index;
	cout << "Wprowadz nowa wartosc elementu." << endl;
	cin >> newData;
	replace = first;
	for (int i = 0; i < index - 1; i++) {
		replace = replace->next;
	}
	replace->data = newData;
	replace = replace->next;
}
void Lista::delete_node() {
	list *delete_node = new list;
	delete_node = first;
	int pos;
	int wybor;
	cout << "Usun element z:\n"
			"1. poczatku listy,\n"
			"2. konca listy,\n"
			"3. dowolnego miejsca"<<endl;
	cin >> wybor;
	switch (wybor) {
	case 1:
		first = delete_node->next;
		delete first;
		counter--;
		break;
	case 2:
		last = last->prev;
		delete last;
		counter--;
		break;
	case 3:
		cout << "Podaj numer elementu, ktory chcesz usunac."<<endl;
		cin >> pos;
		if(pos<=1){
			cout<<"Bledny numer elementu, byc moze chciales usunac pierwszy lub ostatni?";
		}
		else{
		for (int i = 0; i < pos - 2; i++) {
			delete_node = delete_node->next;
		}
		list *temp = delete_node->next;
		delete_node->next = temp->next;
		delete temp;
		counter--;
		}
	}

}

void Lista::insert_beginning() {
	list *addBeg = new list;
	cout << "Wprwadz wartosc jaka chesz dodac na poczatku listy: " << endl;
	cin >> addBeg->data;
	if (first == NULL) {
		addBeg->prev = NULL;
		addBeg->next = NULL;
		first = addBeg;
		last = addBeg;
		cout << "Lista zostala utworzona" << endl;
	} else {
		addBeg->prev = NULL;
		first->prev = addBeg;
		addBeg->next = first;
		first = addBeg;
		cout << "Wartosc zostala poprawnie dodana na poczatku listy." << endl;
	}
	counter++;
}

void Lista::insert_end() {
	list *addEnd = new list;
	cout << "Wprwadz wartosc jaka chesz dodac na koniec listy: " << endl;
	cin >> addEnd->data;
	if (first == NULL) {
		addEnd->prev = NULL;
		addEnd->next = NULL;
		first = addEnd;
		last = addEnd;
		cout << "Lista zostala utworzona. " << endl;
	} else {
		addEnd->next = NULL;
		last->next = addEnd;
		addEnd->prev = last;
		last = addEnd;
		cout << "Wartosc zostala poprawnie dodana na koncu listy. " << endl;
	}
	counter++;
}
void Lista::insert_random() {
	srand(time(NULL));
	list *addRandom = new list;
	addRandom->next = NULL;
	int pos = rand() % (counter - 1);
	cout << "Wylosowana pozycja to " << pos << endl;
	cout << "Jaka wartosc chcesz wstawic?" << endl;
	cin >> addRandom->data;
	if (pos == 1) {
		cout << "Wstawianie na poczatku." << endl;
		insert_beginning();
	} else if (pos == counter) {
		cout << "Wstawianie na koncu." << endl;
		insert_end();
	} else {
		list *temp2 = first;
		for (int i = 0; i < pos - 2; i++) {
			temp2 = temp2->next;
		}
		addRandom->next = temp2->next;
		temp2->next = addRandom;
		counter++;
	}
}
void Lista::display_asc() {
	node = first;
	while (node != NULL) {
		if (node == last) {
			cout << node->data;
			break;
		} else {
			cout << node->data << "<->";
			node = node->next;
		}
	}
	cout << endl;
}
void Lista::display_rev() {
	node = last;
	while (node != NULL) {
		if (node == first) {
			cout << node->data;
			break;
		} else {
			cout << node->data << "<->";
			node = node->prev;
		}
	}
	cout << endl;
}
