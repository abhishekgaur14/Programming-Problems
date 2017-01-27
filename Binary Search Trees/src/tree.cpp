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


void Tree::DFS()
{
	if(root==NULL)
	{
		cout<<"\nThe tree is empty right now.";
		return;
	}

	cout<<"\nIn-order Traversal:\n";
	DFSUtil(root, 0);

	cout<<"\nPre-order Traversal:\n";
	DFSUtil(root, 1);

	cout<<"\nPost-order Traversal:\n";
	DFSUtil(root, 2);
}

void Tree::DFSUtil(Node* root, int flag)		//flag: 0 -> Inorder, 1 -> Pre-order, 2 -> Post-order
{
	//Inorder Traversal
	if(flag == 0)
	{
		if(!root)
			return;
		DFSUtil(root->left,flag);
		cout<<root->data<<" ";
		DFSUtil(root->right, flag);
	}

	//Pre-order Traversal
	if(flag == 1)
	{
		if(!root)
			return;
		cout<<root->data<<" ";
		DFSUtil(root->left, flag);
		DFSUtil(root->right, flag);
	}

	//Post-order Traversal
	if(flag == 2)
	{
		if(!root)
			return;
		DFSUtil(root->left, flag);
		DFSUtil(root->right, flag);
		cout<<root->data<<" ";	
	}
}


void Tree::BFS()
{
	if(root==NULL)
	{
		cout<<"\nThe tree is empty right now.";
		return;
	}

	cout<<"\nBreadth First Traversal / Level-Order Traversal looks like this: \n";

	queue<Node*> Q;
	Q.push(root);

	while(!Q.empty())
	{
		Node* current = Q.front();
		cout<< current->data <<" ";

		if(current->left != NULL)
			Q.push(current->left);

		if(current->right != NULL)
			Q.push(current->right);

		Q.pop();
	}
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


/* Iterative solutions for finding min and max element in the tree.
int Tree::findMin()
{
	//if the tree is empty this function returns -1.
	if(root==NULL)			
	{
		cout<<"\nThe tree is empty right now.\n";
		return -1;
	}
	
	Node* rootNode = root;

	while(rootNode->left != NULL)
		rootNode = rootNode->left;

	return rootNode->data;	
}

int Tree::findMax()
{
	//if the tree is empty this function returns -1.
	if(root==NULL)			
	{
		cout<<"\nThe tree is empty right now.\n";
		return -1;
	}

	Node* rootNode = root;
	
	while(rootNode->right != NULL)
		rootNode= root->right;

	return rootNode->data;	
}
*/

//Recursive solutions for find min and max element in a tree
int Tree::findMin()
{
	if(!root)
	{
		cout<<"\nThe tree is empty right now.\n";
		return -1;
	}

	Node* rootNode = root;
	return findMinUtil(rootNode);
}

int Tree::findMinUtil(Node* root)
{
	if(root->left == NULL)
		return root->data;

	return findMinUtil(root->left);
}

int Tree::findMax()
{
	if(!root)
	{
		cout<<"\nThe tree is empty right now.\n";
		return -1;
	}

	Node* rootNode = root;
	return findMaxUtil(rootNode);
}

int Tree::findMaxUtil(Node* root)
{
	if(root->right == NULL)
		return root->data;

	return findMaxUtil(root->right);
}


int Tree::findHeight()
{
	if(root == NULL)
	{
		cout<<"\nThe tree is empty right now. Hence the height is 0.\n";
		return 0;
	}

	return findHeightUtil(root);
}

int Tree::findHeightUtil(Node* root)
{
	if(root == NULL)
		return -1;

	return max(findHeightUtil(root->left), findHeightUtil(root->right))+1;
}


bool Tree::isBST()
{
	int minValue = numeric_limits<int>::min();
	int maxValue = numeric_limits<int>::max();

	return isBSTUtil(root, minValue, maxValue);
}

bool Tree::isBSTUtil(Node* root, int minValue, int maxValue)
{
	if(root == NULL)
		return true;
	
	else if(root->data > minValue && root->data < maxValue && 
		isBSTUtil(root->left, minValue, root->data) && isBSTUtil(root->right, root->data, maxValue))
		return true;
	
	else 
		return false;
}


void Tree::deleteNode(int data)
{
	this->root = deleteNodeUtil(root, data);
}

Node* Tree::deleteNodeUtil(Node* root, int data)
{
	if(root==NULL)
		return root;

	else if(data < root->data)
		root->left = deleteNodeUtil(root->left, data);

	else if(data > root->data)
		root->right = deleteNodeUtil(root->right, data);

	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root=NULL;
		}

		else if(root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}

		else if(root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}

		else
		{
			int temp = findMinUtil(root->right);
			root->data = temp;
			root->right = deleteNodeUtil(root->right, temp);
		}
	}

	return root;
}


bool Tree::isEmpty()
{
	if(root==NULL)
		return true;

	return false;
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