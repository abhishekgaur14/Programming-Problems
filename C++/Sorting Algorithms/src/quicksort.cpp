#include <iostream>
#include <algorithm>
#include "arrayUtils.h"

using namespace std;

int partition(int *arr,int begin, int end)
{
	int pivot=end;
	int pIndex=begin;

	for(int i=begin;i<end;i++)
	{
		if(arr[i]<=arr[pivot])
		{
			swap(arr[i],arr[pIndex]);
			pIndex++;
		}
	}

	swap(arr[pIndex],arr[pivot]);

	return pIndex;
}

void quickSort(int *arr, int begin, int end)
{
	if(begin<end){
		int pIndex = partition(arr, begin, end);
		quickSort(arr,begin,pIndex-1);
		quickSort(arr, pIndex+1, end);
	}
}

int main(){
	int *arr;
	int size;
	
	cout<<"Please specify the size of your array:"<<endl;
	cin>>size;
	
	arr= new int [size];

	cout<<"Please enter the elements of array:"<<endl;
	
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}

	cout<<"Unsorted Array:"<<endl;
	printArray(arr,size);

	quickSort(arr,0,size-1);

	cout<<"Sorted Array:"<<endl;
	printArray(arr,size);

	free(arr);
	return 0;
}


