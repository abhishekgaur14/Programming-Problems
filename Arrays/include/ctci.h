#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;


// Q1. Determine if the string has unique characters.
bool isUniqueString_1(string str);
bool isUniqueString_2(string str);
bool isUniqueString_3(string str);
bool isUniqueString_4(string str);

// Q2. Reverse a null-terminated string
void reverse(char *str);

// Q3. Determine if one string is a permutation of another string.
bool isPermutation(const string& s1, const string& s2);
bool isPermutation_2(const string& s1, const string& s2);		//Alternate solution. Change in main.cpp to use this.