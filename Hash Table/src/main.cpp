#include "hashtable.h"

int main()
{
    int option;
    bool flag = true;
    string str;

    // Create 26 Items to store in the Hash Table.
    Item * A = new Item {"Apple", NULL};
    Item * B = new Item {"Banana", NULL};
    Item * C = new Item {"Caterpillar", NULL};
    Item * D = new Item {"Dog", NULL};
    Item * E = new Item {"Elephant", NULL};
    Item * F = new Item {"Fedora", NULL};
    Item * G = new Item {"Goosebumps", NULL};
    Item * H = new Item {"House", NULL};
    Item * I = new Item {"Insects", NULL};
    Item * J = new Item {"Jam", NULL};
    Item * K = new Item {"Kite", NULL};
    Item * L = new Item {"Limestone", NULL};
    Item * M = new Item {"Mountaineering", NULL};
    Item * N = new Item {"Night", NULL};
    Item * O = new Item {"Open Sesame", NULL};
    Item * P = new Item {"Potatoes", NULL};
    Item * Q = new Item {"Quantum Mechanics", NULL};
    Item * R = new Item {"Rrrrrrrrrrawr", NULL};
    Item * S = new Item {"Snakes", NULL};
    Item * T = new Item {"Tizzy Tube", NULL};
    Item * U = new Item {"Underworld", NULL};
    Item * V = new Item {"Volcanic Ash", NULL};
    Item * W = new Item {"Who When What Why", NULL};
    Item * X = new Item {"XXX", NULL};
    Item * Y = new Item {"Yellow", NULL};
    Item * Z = new Item {"Zest of Lemon", NULL};
    
    // Create a Hash Table of 13 Linked List elements.
    HashTable table;
    
    // Add 23 items to Hash Table.
    table.insertItem(A);
    table.insertItem(B);
    table.insertItem(C);
    table.insertItem(D);
    table.insertItem(E);
    table.insertItem(F);
    table.insertItem(G);
    table.insertItem(H);
    table.insertItem(I);
    table.insertItem(J);
    table.insertItem(K);
    table.insertItem(L);
    table.insertItem(M);
    table.insertItem(N);
    table.insertItem(O);
    table.insertItem(P);
    table.insertItem(Q);
    table.insertItem(R);
    table.insertItem(S);
    table.insertItem(T);
    table.insertItem(U);
    table.insertItem(V);
    table.insertItem(W);
    table.insertItem(X);
    table.insertItem(Y);
    table.insertItem(Z);

    while(flag)
    {
        cout<<"\nHash Table Implementation in C++.\n\n";
        cout<<"What would you like to do?\n";
        cout<<"1. Display the hash table.\n";
        cout<<"2. Display the histogram representation of hash table.\n";
        cout<<"3. Add an item to the hash table.\n";
        cout<<"4. Lookup the item in the hash table.\n";
        cout<<"5. Remove the item from the hash table.\n";
        cout<<"6. Exit the program.\n\n";
        cout<<"Enter you choice: ";
        cin>>option;

        switch(option)
        {
            case 1: table.printTable();
                break;

            case 2: table.printHistogram();
                break;

            case 3: {
                cout<<"Enter the string you want to add to the hash table: ";
                cin>>str;
                Item* newItem = new Item{str,NULL};
                table.insertItem(newItem);
                cout<<"\nElement has been added to the hash table.\n";
                break;
            }

            case 4: {
                cout<<"Enter the string/element you want to lookup in the hash table: ";
                cin>>str;
                Item* result = table.getItemByKey(str);
                if(result)
                    cout<<endl<<result->key<<" exists in the hash table."<<endl;
                break;
            }

            case 5: cout<<"Enter the string/element you want to remove from the hash table: ";
                cin>>str;
                table.removeItem(str);
                break;

            case 6: //table.~HashTable();
                flag = false;
                break;

            default: cout<<"Wrong input! \n";
        }
    }

   return 0;
}