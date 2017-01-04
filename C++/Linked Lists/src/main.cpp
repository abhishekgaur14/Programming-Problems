#include <iostream>
#include "LinkedList.h"
#include "linkedListUtils.h"
#include "ctci.h"

using namespace std;

int main()
{
	LinkedList listObj;
	int option, num, suboption, pos;

	while(1){
		cout<<"What would you like to do?\n";
		cout<<"1. Display the content of the Linked List.\n";
		cout<<"2. Insert element into Linked List.\n";
		cout<<"3. Delete an element from the Linked List.\n";
		cout<<"4. Display the Linked List in reversed order.\n";
		cout<<"5. Display the number of elements in the Linked List.\n";
		cout<<"6. Reverse the Linked List.\n";
		cout<<"7. Cracking the Coding Interview Solutions.\n";
		cout<<"Enter your option(1-7): ";
		cin>>option;
		cout<<endl;
		
		switch(option)
		{
			case 1: if(!listObj.isEmpty())
						listObj.display();
					else
						cout<<"The Linked List is empty.\n\n";
					break;
					
			case 2: cout<<"Enter the number you want to insert into Linked List: ";
					cin>>num;
					
					suboption = subOptionSelection();

					if(suboption==1)
						pos = 1;
					else if(suboption==2)
						pos = -1;					//denoting the end of list as '-1'
					else{
						pos = position();
						if(pos>listObj.getLength()+1){
							cout<<"The list is currently filled till position "<<listObj.getLength()<<". You can start inserting the numbers from position "<<listObj.getLength() + 1<<".\n\n";
							continue;
						}
					}
					
					listObj.insert(num, pos);

					cout<<"\nElement inserted into Linked List.\n\n";
					break;

			case 3: if(listObj.isEmpty())
						cout<<"The Linked List is empty. There's nothing to delete.\n\n";
					
					else{
						cout<<"What would you like to do?\n";
						cout<<"\t1. Delete a particular element.\n";
						cout<<"\t2. Delete an element from a particular position.";
						cout<<"\nEnter your choice(1/2): ";
						cin>>suboption;
						if(suboption==1){
							cout<<"Enter the element you want to delete: ";
							cin>>num;
							listObj.deleteByData(num);
						}
						else{
							cout<<"Enter the position of the element you want to delete: ";
							cin>>pos;
							
							if(pos > listObj.getLength())
								cout<<"The position number you entered is greater than the number of elements in the list.\n\n";
							else{
								listObj.deleteByPosition(pos);
								cout<<"\nElement deleted from the list.\n\n";
							}
						}
					}
					break;

			case 4: if(listObj.isEmpty())
						cout<<"The Linked List is empty.";
					else{
						cout<<"The Linked List is reversed order looks like this:\n";
						listObj.printReverse(listObj.head);
					}
					cout<<endl<<endl;
					break;

			case 5: cout<<"The number of elements in the Linked List are: "<<listObj.getLength()<<"\n\n";
					break;

			case 6: cout<<"Would you like to reverse the Linked List- \n\t1. Iteratively\n\t2. Recursively\nThe result will remain the same. Enter your choice: ";
					cin>>suboption;
					
					if(suboption==1)
						listObj.reverse(0);
					else if(suboption==2)
						listObj.reverse(1);	
					else
						cout<<"Invalid choice. Exiting! \n\n";

					break;

			case 7: cout<<"Please select the question number which you want to run:\n";
					cout<<"1. Remove duplicates from an unsorted Linked List.\n";
					cout<<"2. Find out nth node to last node of the Linked List.\n";
					cout<<"Enter your choice: ";
					cin>>suboption;

					if(suboption==1){					
					 	removeDuplicates(listObj.head);
					}

					if(suboption==2)
					{
						if(!listObj.isEmpty())
						{
							cout<<"Enter the value of n: ";
							cin>>pos;
							//int i=0;													//Uncomment this to use the recursive solution.
							//Node* nthToLastNode = nthToLast_r(listObj.head, pos, i);	//Uncomment this and comment the next two lines to use recursive solution
							//Node* nthToLastNode = nthToLast_i(listObj.head, pos);		//Uncomment this and comment the previous two and the next line to use the iterative solution.
							Node* nthToLastNode = nthToLast_alt(listObj.head, pos);		//Comment this to use the recursive or iterative solution. Also uncomment the one you want to use.
							if(nthToLastNode)
								cout<<"\nThe nth node to the last node of the Linked List is: "<<nthToLastNode->data<<endl<<endl;
							else{
								cout<<"\nYou've probably entered a value of n larger than the number of nodes in the list or a negative value. 0 and negative numbers are invalid."; 
								cout<<"\nThe list has "<<listObj.getLength()<<" nodes right now. Enter a number equal to or smaller than this. \n\n";
							}
						}

						else
							cout<<"\nThe list is empty right now.\n\n";
					}
					break;

			default: cout<<"\nWrong input.";
		}
	}
	
	return 0;
}