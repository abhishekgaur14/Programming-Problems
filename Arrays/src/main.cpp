#include "ctci.h"

int main()
{
    int option;
    bool flag = true;

    while(flag)
    {
        cout<<"\nArray Programming Problems from Cracking the Coding Interview.\n";
        cout<<"\nWhat would you like to do?\n";
        cout<<"1. Determine if a string has unique characters or not.\n";
        cout<<"2. Reverse a null-terminated string.\n";
        cout<<"3. Determing is a string is a permutation of another string (case-sensitive).\n";
        cout<<"4. Exit the program.\n\n";
        cout<<"Enter you choice: ";
        cin>>option;
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        switch(option)
        {
            case 1: {
                    string str;
                    cout<<"Enter the string: ";
                    getline(cin,str);
                    if(!isUniqueString_2(str))
                        cout<<"\nThe entered string does not have unique characters.\n";
                    else
                        cout<<"\nThe entered string has all unique characters.\n";
                    break;
                }

            case 2: {
                    string str;
                    cout<<"Enter the string: ";
                    getline(cin,str);
                    char *cstr = new char[str.length() + 1];
                    strcpy(cstr,str.c_str());
                    cout<<"\nOriginal string: "<<cstr;
                    reverse(cstr);
                    cout<<"\nReversed string: "<<cstr<<endl;
                    delete [] cstr;
                    break;
                }

            case 3: {
                    string s1, s2;
                    cout<<"Enter the first string: ";
                    getline(cin,s1);
                    cout<<"Enter the second string: ";
                    getline(cin, s2);

                    if(isPermutation(s1, s2))
                        cout<<"\nThe given strings are permutation of one another.\n";
                    else
                        cout<<"\nThe given strings are not permutation of one another.\n";

                    break;
                }

            case 4: cout<<"\nExiting the program.\n\n";
                    flag = false;
                    break;

            default: cout<<"\nWrong input! \n";
        }
    }

   return 0;
}