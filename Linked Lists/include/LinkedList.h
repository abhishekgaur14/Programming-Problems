#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
	int data;
	Node* next;
};

class LinkedList{
	
public:
	Node *head;

	LinkedList();
	~LinkedList();
	
	void insert(int data, int pos);
	void display();
	void deleteByPosition(int pos);
	void deleteByData(int data);
	void printReverse(Node* node);
	Node* getHead();
	bool isEmpty();
	int getLength();
	void reverse(int flag);
	void reverseUtil(Node** head_ref);
};

#endif 