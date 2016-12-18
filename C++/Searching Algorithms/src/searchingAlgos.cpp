#include <iostream>
#include "arrayUtils.h"

using namespace std;


/*------------------Linear Search Begins---------------*/
int linearSearch(int *arr, int size, int n)
{
	for(int i=0;i<size;i++)
	{
		if(n==arr[i]){
			return i;
		}
	}
	return -1;
}
/*------------------Linear Search Ends------------------*/


/*------------------Binary Search Begins------------------*/
int binarySearch(int *arr, int begin, int end, int n)
{
	int mid = (end+begin) /2;

	if(arr[mid]==n)
		return mid;

	else if(arr[mid]>n)
		return binarySearch(arr, begin, mid-1,n);

	else if(arr[mid]<n)
		return binarySearch(arr, mid+1, end, n);

	else 
		return -1;
}
/*------------------Binary Search Ends------------------*/
