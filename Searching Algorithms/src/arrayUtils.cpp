/* This file contains utility functions
for array like Print etc. */

#include <iostream>
#include "arrayUtils.h"

using namespace std;

void printArray(int *arr, int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}