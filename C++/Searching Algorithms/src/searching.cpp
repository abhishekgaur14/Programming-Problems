/* This file contains the main function which accepts
input from the user in form of array size, array elements,
algorithm to use and element to search*/

#include <iostream>
#include "arrayUtils.h"
#include "searchingAlgos.h"

using namespace std;

int main(){
	int *arr;			//initial array
	int size;			//size of the array
	char algo;			//algo to use
	int element;        		//element to be searched
	int index;			//index of the found element; assigned -1 if element not found.
	char sorted_data;

	cout<<"Please specify the size of your array:"<<endl;
	cin>>size;
	
	arr= new int [size];

	cout<<"Please enter the elements of array:"<<endl;
	
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}

	cout<<"Which number would you like to find?"<<endl;
	cin>>element;

	cout<<"Which algorithm would you like to use: Linear Search(L/l) or Binary Search(B/b)?"<<endl;
	cin>>algo;	

	cout<<endl;

	switch(algo)
	{
		case 'L': cout<<"Using Linear Search..."<<endl;
			  	index = linearSearch(arr,size,element);
				break;
		case 'l': cout<<"Using Linear Search..."<<endl;
			  	index = linearSearch(arr,size,element);
				break;
		case 'B': cout<<"Binary Search can only be done on sorted data? Is your data sorted? [Y/N]"<<endl;
				cin>>sorted_data;
				if(sorted_data == 'Y' || sorted_data == 'y')
				{
					cout<<"Using Binary Search..."<<endl;
			  		index = linearSearch(arr,size,element);
			  	}
			  	else
			  	{
			  		cout<<"Can't perform search on unsorted data."<<endl;
			  		exit(0);
			  	}
				break;
		case 'b': cout<<"Binary Search can only be done on sorted data? Is your data sorted? [Y/N]"<<endl;
				cin>>sorted_data;
				if(sorted_data == 'Y' || sorted_data == 'y')
				{
					cout<<"Using Binary Search..."<<endl;
			  		index = linearSearch(arr,size,element);
			  	}
			  	else
			  	{
			  		cout<<"Can't perform search on unsorted data."<<endl;
			  		exit(0);
			  	}
				break;
		default:  cout<<"Using Linear Search..."<<endl;
			  	index = linearSearch(arr,size,element);
	}

	(index != -1) ? cout<<"Number found at position: "<<index+1<<endl : cout<<"Number is not present in the array."<<endl;
				
	free(arr);
	return 0;
}
