/*
 * Lista.h
 *
 *  Created on: 10.03.2017
 *      Author: root
 */
#include <iostream>

using namespace std;

class Lista {

	struct list {
		struct list *prev;
		int data;
		struct list *next;
	}
	*node = NULL, *first = NULL, *last = NULL;

public:
	void load_from_file();
	void insert_beginning();
	void insert_end();
	void display_asc();
	void display_rev();
	void del();
	void replace();
	void delete_node();
	void search();
	void insert_random();
};
