#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <iostream>

using namespace std;

struct Item{
	string key;
	Item* next;
};

class LinkedList{
	
	Item *head;
	int length;

public:
	LinkedList();
	void insertItem(string itemKey);
	bool removeItem(string itemKey);
	Item* getItem(string itemKey);
	void display();
	int getLength();
	~LinkedList();
};

#endif 