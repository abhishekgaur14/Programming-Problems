/* This file contains the main function which accepts
input from the user in form of array size, array element 
and the algorithm to use*/

#include <iostream>
#include "arrayUtils.h"
#include "sortingAlgos.h"

using namespace std;

int main(){
	int *arr;
	int size;
	char algo;

	cout<<"Please specify the size of your array:"<<endl;
	cin>>size;
	
	arr= new int [size];

	cout<<"Please enter the elements of array:"<<endl;
	
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}

	cout<<"Which algorithm would you like to use: Quicksort(Q/q) or Mergesort(M/m)?"<<endl;
	cin>>algo;
	
	cout<<"Unsorted Array:"<<endl;
	printArray(arr,size);

	cout<<endl;

	switch(algo)
	{
		case 'M': cout<<"Using Mergesort..."<<endl;
			  mergeSort(arr,size);
				break;
		case 'm': cout<<"Using Mergesort..."<<endl;
			  mergeSort(arr,size);
				break;
		case 'Q': cout<<"Using Quicksort..."<<endl;
			  quickSort(arr,0,size-1);
				break;
		case 'q': cout<<"Using Quicksort..."<<endl;
			  quickSort(arr,0,size-1);
				break;
		default:  cout<<"Using Mergesort..."<<endl;
			  quickSort(arr,0,size-1);
	}

	cout<<endl<<"Sorted Array:"<<endl;
	printArray(arr,size);

	free(arr);
	return 0;
}
