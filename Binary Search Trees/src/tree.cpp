#include "tree.h"

Tree::Tree()
{
	this->root = NULL;
}


Node* Tree::getNewNode(int data)
{
	Node* newNode = new Node;
	
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;

	return newNode;
}


void Tree::insert(int data)
{
	if(root == NULL)
		root = getNewNode(data);

	else										
		insertUtil(root, data);
}

void Tree::insertUtil(Node* root, int data)
{
 	if(data <= root->data)
	{
		if(!root->left)
			root->left = getNewNode(data);
		else
			insertUtil(root->left, data);
	}

	else
	{
		if(!root->right)
			root->right = getNewNode(data);
		else
			insertUtil(root->right, data);
	}
}


void Tree::print()
{
	printUtil(root);
}

void Tree::printUtil(Node* root)
{
	if(!root)
		return;

	printUtil(root->left);
	cout<<root->data<<" ";
	printUtil(root->right);
}


bool Tree::search(int data)
{
	if(root == NULL)
		return false;

	else if(root->data == data)
		return true;

	else
		return searchUtil(root,data);	
}

bool Tree::searchUtil(Node* root, int data)
{
	if(root == NULL)
		return false;

	else if(data == root->data)
		return true;

	else if(data < root->data)
		return searchUtil(root->left, data);

	else
		return searchUtil(root->right, data);
}


void Tree::deleteTree(Node* root)
{
	if(root != NULL)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}
}

Tree::~Tree()
{
	deleteTree(root);
	cout<<"\nThe tree has been deleted from the memory.\n";
}