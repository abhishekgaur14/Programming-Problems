#include "LinkedList.h"

//Question 1: Remove duplicate elements of Linked Lists
void removeDuplicates(Node* head);

//Question 2: Find nth node to last node of the Linked List 
Node* nthToLast_r(Node* head, int k, int& i);
Node* nthToLast_i(Node* head, int k);
Node* nthToLast_alt(Node* head, int k);

//Question 3: Delete a node in middle of the Linked List, given access to only that node
bool removeFromMiddle(Node* node);

//Question 4: Partition the Linked List around a value x, such that 
//all nodes less than x come before all node greater than or equal to x.
Node* partition(Node* head, int x);