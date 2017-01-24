#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>

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
		void DFSUtil(Node* root, int flag);
		bool searchUtil(Node* root, int data);
		void deleteTree(Node *root);


	public:
		Tree();
		~Tree();
		void insert(int data);
		void DFS();
		bool search(int data);
		void BFS();
		bool isEmpty();
};

#endif