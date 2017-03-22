/*
 * Heap.cpp
 *
 *  Created on: 13.03.2017
 *      Author: root
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "Heap.h"
#include <fstream>
#include <math.h>

using namespace std;

int Heap::Size() {
	return heap.size();
}

void Heap::Insert(int element) {
	heap.push_back(element);
	heapifyup(Size() - 1);
}
void Heap::loadFromFile() {
	int counter;
	int element;
	ifstream file;
	file.open("testtest.txt");
	if (file.good()) {
		file >> counter;
		for (int i = 0; i < counter; i++) {
			file >> element;
			Insert(element);
		}
		cout << "\nPoprawnie dodadno " << counter << " elementow do kopca\n"<< endl;
		file.close();
	} else {
		cout << "\nNie mozna zaladowac pliku.\n" << endl;
	}
}
void Heap::DeleteMin() {
	if (heap.size() == 0) {
		cout << "\nKopiec jest pusty.\n" << endl;
		return;
	}
	heap[0] = heap.at(heap.size() - 1);
	heap.pop_back();
	heapifydown(0);
	cout << "\nElement usuniety.\n" << endl;
}
int Heap::ExtractMin() {
	if (heap.size() == 0) {
		return -1;
	} else
		return heap.front();
}
void Heap::DisplayHeap() {
	int levels = 0;
	int s = heap.size();
	    cout<<"Rozmiar kopca: "<<s<<endl;
	    while(s != 1)
	    {
	        s/=2;
	        levels++;
	    }
	    ++levels;
	    int counter = 0;
	    cout<<"Liczba poziomow: "<<levels<<endl;
	    cout<<heap[0]<<endl;
	    int tmp = 2;
	    for(int i = 1;i < heap.size();i++ )
	    {
	        cout<<heap[i]<<" ";
	        counter++;
	        if (counter == tmp)
	        {
	            counter = 0;
	            tmp*=2;
	            cout<<endl;
	        }
	    }
	   cout<<endl<<endl<<endl;
}
int Heap::left(int parent) {
	int l = 2 * parent + 1;
	if (l < heap.size())
		return l;
	else
		return -1;
}
int Heap::right(int parent) {
	int r = 2 * parent + 2;
	if (r < heap.size())
		return r;
	else
		return -1;
}
int Heap::parent(int child) {
	int p = (child - 1) / 2;
	if (child == 0)
		return -1;
	else
		return p;
}
void Heap::heapifyup(int in) {
	if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in]) {
		int temp = heap[in];
		heap[in] = heap[parent(in)];
		heap[parent(in)] = temp;
		heapifyup(parent(in));
	}
}
void Heap::heapifydown(int in) {
	int child_left = left(in);
	int child_right = right(in);
	if (child_left >= 0 && child_right >= 0
			&& heap[child_left] > heap[child_right]) {
		child_left = child_right;
	}
	if (child_left > 0 && heap[in] > heap[child_left]) {
		int temp = heap[in];
		heap[in] = heap[child_left];
		heap[child_left] = temp;
		heapifydown(child_left);
	}
}
void Heap::SearchElement(int element) {
	int index = -1;
	for (int i = 0; i < heap.size(); i++) {
		if (heap[i] == element) {
			index = i;
		}
	}
	if (index != -1) {
		cout << "\nZnaleziono element na pozycji " << index << endl;
	} else {
		cout << "\nNie znaleziono elementu w kopcu\n" << endl;
	}
}
