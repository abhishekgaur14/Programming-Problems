/* This file contains implementation of 
all sorting algorithms*/

#include <iostream>
#include "sortingAlgos.h"

using namespace std;

/*---------------------------------Merge Sort Begins------------------------------------*/
void merge(int *arr, int *left, int *right, int left_size, int right_size)
{
	int i, j, k;
	i=0; j=0; k=0;

	while(i<left_size && j<right_size){
		if(left[i]<right[j]){
			arr[k++]=left[i++];
		}
	
		else{
			arr[k++]=right[j++];
		}
	}
	
	while(i<left_size){
		arr[k++] = left[i++];
	}
	
	while(j<right_size){
		arr[k++] = right[j++];
	}
}

void mergeSort(int *arr, int n)
{
	int mid, i, *L, *R;

	if(n<2)
		return;

	mid=n/2;

	L=new int[mid];
	R= new int[n-mid];

	for(i=0;i<mid;i++)
		L[i] = arr[i];

	for(i=mid;i<n;i++)
		R[i-mid] = arr[i];

	mergeSort(L,mid);
	mergeSort(R,n-mid);
	merge(arr,L,R,mid, n-mid);
}
/*------------------Merge Sort Ends---------------------*/



/*------------------Quick Sort Begins---------------------*/
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
/*------------------Quick Sort Ends---------------------*/