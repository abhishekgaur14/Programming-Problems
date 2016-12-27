#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
	int data;
	Node* next;
};

class LinkedList{
	Node *head;

public:
	LinkedList()
	{
		head = NULL;
	}	

	void insert(int data, int pos);
	void display();
	void deleteByPosition(int pos);
	void deleteByData(int data);
};

#endif 