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
int binarySearch(int *arr, int size, int n, char flag)
{
	int low = 0;
	int high = size-1;
	int result = -1;							//to find the first/last occurence of the number
	while(low<=high){
		int mid = (high+low) /2;

		if(arr[mid]==n)
		{
			if(flag == 'F' || flag =='f')
			{	
				high = mid - 1;
			}
			else if(flag == 'L' || flag == 'l')
			{
				low = mid + 1;
			}
			else if(flag == 'A' || flag == 'a')
				return mid;
			result = mid;
		}

		else if(arr[mid]>n)
			high = mid-1;

		else if(arr[mid]<n)
			low = mid+1;
	}
	
	return result;	
}
/*------------------Binary Search Ends------------------*/