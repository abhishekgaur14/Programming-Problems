// Q3. Determine if one string is a permutation of another string.

#include "ctci.h"

bool isPermutation(const string& s1, const string& s2)
{
	if(s1.length() != s2.length())
		return false;

	string a(s1);
	string b(s2);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if(a.compare(b) == 0)
		return true;

	return false;
}


//Alternative solution
bool isPermutation_2(const string& s1, const string& s2)
{
	if(s1.length() != s2.length())
		return false;

	string a(s1);
	string b(s2);

	int letters[256] = {0};

	for(int i=0;i<a.length();i++)
		letters[(int)a[i]]++;

	for(int j=0;j<b.length();j++)
	{
		if(--letters[(int)b[j]] < 0)
			return false;
	}

	return true;
}