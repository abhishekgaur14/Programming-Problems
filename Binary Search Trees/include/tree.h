#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <algorithm>

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
		int findMinUtil(Node* root);
		int findMaxUtil(Node* root);
		int findHeightUtil(Node* root);

	public:
		Tree();
		~Tree();
		void insert(int data);
		void DFS();
		bool search(int data);
		void BFS();
		bool isEmpty();
		int findMin();
		int findMax();
		int findHeight();
};

#endif