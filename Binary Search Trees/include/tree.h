#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class Tree
{
		Node* root;
		Node* getNewNode(int data);
		void insertUtil(Node* root, int data);
		void printUtil(Node* root);
		bool searchUtil(Node* root, int data);
		void deleteTree(Node *root);

	public:
		Tree();
		~Tree();
		void insert(int data);
		void print();
		bool search(int data);
};

#endif