// Q1. Determine if a string has unique characters or not.
// By default, main() calls the second implementation, i.e., isUniqueString_2. 
// Make changes to main() to call any of the other implementation. 

#include "ctci.h"

//Implementation 1:
//Time Complexity: O(n); n=> length of string.
//Space Complexity: O(1)
bool isUniqueString_1(string str)
{
	if(str.length() > 256)
		return false;

	bool charPresent[256] = {false};

	for(int i=0; i<str.length(); i++)
	{
		int ascii_val = str[i];

		if(charPresent[ascii_val] == true)
			return false;

		charPresent[ascii_val] = true;
	}
	return true;
}


//Implementation 2:
//Alternate solution to reduce the space complexity by a factor of eight.
//By using a bit vector/bit. 
//Reason: 
//A bitset is an array of bool but each Boolean value is not stored separately.
//Instead bitset optimizes the space such that each bool takes 1 bit space only.
//So space taken by bitset bs is less than that of bool bs[N] and vector bs(N).
bool isUniqueString_2(string str)
{
	if(str.length()>256)
		return false;

	bitset<256> charPresent;

	for(int i=0;i<str.length();i++)
	{
		int ascii_val = str[i];

		if(charPresent[ascii_val])
			return false;

		charPresent.set(ascii_val);
	}

	return true;
}


//Implementation 3:
//Time Complexity: O(n^2)
//Space Complexity: O(1)
bool isUniqueString_3(string str)
{
	if (str.length()>256)
		return false;

	for(int i=0; i<str.length() - 1; i++)
	{
		for(int j= i+1; j< str.length(); j++)
		{
			if(str[i] == str[j])
				return false;
		}
	}

	return true;
}


//Implementation 4:
//Time Complexity: O(n+nlogn) (sorting happens in O(nlogn) and then we linearly search through the string)
//Space Complexity: O(1) (default sort function is usually quicksort and hence no extra space is used)
bool isUniqueString_4(string str)
{
	sort(str.begin(),str.end());

	for(int i=1;i<str.length();i++)
	{
		if(str[i] == str[i-1])
			return false;
	}
	return true;
}