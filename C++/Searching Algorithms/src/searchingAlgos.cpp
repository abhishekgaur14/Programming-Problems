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