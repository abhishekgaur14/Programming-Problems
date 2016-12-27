#include <iostream>
#include "LinkedList.h"
#include "linkedListUtils.h"

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
		cout<<"Enter your option(1/2/3/4/5): ";
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
						listObj.printReverse(listObj.getHead());
					}
					cout<<endl<<endl;
					break;

			case 5: cout<<"The number of elements in the Linked List are: "<<listObj.getLength()<<"\n\n";
					break;

			default: cout<<"\nWrong input.";
		}
	}
	
	return 0;
}