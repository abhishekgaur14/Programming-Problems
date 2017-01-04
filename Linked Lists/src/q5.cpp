//Q5. Add two numbers stored as two different linked lists. 
//Digits are nodes of respective lists stored in reverse order. 
//The sum is stored in a similar manner as two digits.
//**Follow-up question: if the lists are stored in the forward order i.e. the 1s digit is the tail node.
//**Solution to follow-up: Just reverse the linked lists and do the same operations. 
//**Reverse the answer again to display in corrent format.
//**Reversing will happen in addLists funtion after to two do-while loops and call to addListsUtil to store the the result in right format.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include "ctci.h"
#include <math.h>					//to use pow() function in displayNum()

using namespace std;


//Function to zero pad the number with smaller number of digits
LinkedList* zeroPadding(LinkedList* list, int difference)
{
	while(difference>0)
	{
		list->insert(0,-1);
		--difference;
	}
	return list;
}


//this function saves the two numbers as two different lists
//digits are stored in reverse order i.e. 1s digit is at head of list.
void addLists(int x, int y)
{
	LinkedList* list1 = new LinkedList();
	LinkedList* list2 = new LinkedList();

	int n_digits_x=0;
	int n_digits_y=0;

	do{
		list1->insert(x%10, -1);
		++n_digits_x;
		x /= 10;
	}while(x);

	do{
		list2->insert(y%10, -1);
		++n_digits_y;
		y /= 10;
	}while(y);

	cout<<"\nFirst Number:\n";
	list1->display();
	cout<<"Second Number:\n";
	list2->display();


	if(n_digits_x > n_digits_y)
		list2 = zeroPadding(list2, n_digits_x - n_digits_y);
	else
		list1 = zeroPadding(list1, n_digits_y - n_digits_x);

	list1->head = addListsUtil(list1->head, list2->head);

	cout<<"Resulting List:\n";
	list1->display();	
	cout<<"Resulting Number: "<<displayNum(list1->head)<<endl<<endl;
}

//Utility function to add the two lists
Node* addListsUtil(Node* head1, Node* head2)
{
	int carry = 0;

	Node* n1 = head1;
	Node* n2 = head2;
	
	while(n1)
	{
		n1->data = n1->data + n2->data + carry;
		if(n1->data > 9)
		{
			carry = 1;
			n1->data %= 10;
		}
		else
			carry = 0;
		n1 = n1->next;
		n2 = n2->next;
	}

	if(carry)
	{
		n1 = head1;
		while(n1->next)
			n1=n1->next;
		n1->next = new Node();
		n1->next->data=1;
		n1->next->next=NULL;
	}
	n1= head1;
	return n1;
}


//Function to display the resulting numerical value of the nodes of the linked list.
int displayNum(Node* head)
{
	int num = 0;
	int digit = 0;
	Node* temp = head;

	while(temp)
	{
		num += pow(10,digit) * temp->data;
		++digit;
		temp = temp->next; 
	}

	return num;
}