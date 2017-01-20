#include "ctci.h"

int main()
{
    int option;
    bool flag = true;
    string str;

    while(flag)
    {
        cout<<"\nArray Programming Problems from Cracking the Coding Interview.\n";
        cout<<"\nWhat would you like to do?\n";
        cout<<"1. Determine if a string has unique characters or not.\n";
        cout<<"2. Exit the program.\n\n";
        cout<<"Enter you choice: ";
        cin>>option;
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        switch(option)
        {
            case 1: cout<<"Enter the string: ";
                getline(cin,str);
                if(!isUniqueString_2(str))
                    cout<<"\nThe entered string does not have unique characters.\n";
                else
                    cout<<"\nThe entered string has all unique characters.\n";
                break;

            case 2: cout<<"\nDeleting the string from memory and exiting.\n\n";
                flag = false;
                break;

            default: cout<<"\nWrong input! \n";
        }
    }

   return 0;
}