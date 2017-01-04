#include <iostream>
#include "linkedListUtils.h"

using namespace std;

int subOptionSelection()
{
	int suboption;
	
	cout<<"What position would you like to insert the number at?\n";
	cout<<"\t1. Beggining of list. \n\t2. End of list. \n\t3. At a particular position in list.\n";
	cout<<"Enter your choice(1/2/3): ";
	cin>>suboption;
	
	return suboption;
}

int position()
{
	int pos;
	
	cout<<"Enter the position you want to insert the number at: ";
	cin>>pos;

	return pos;
}