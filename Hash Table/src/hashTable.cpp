#include "hashtable.h"

HashTable::HashTable(int tableLength)
{
	if(tableLength<=0)
		tableLength=13;

	array = new LinkedList[tableLength];
	length = tableLength;
}

int HashTable::hash(string itemKey)
{
	int value =0;
	for(int i=0; i<itemKey.length();i++)
		value += itemKey[i];
	return ((value * itemKey.length()) % length); 
}

void HashTable::insertItem(Item* newItem)
{
	int index = hash(newItem->key);
	array[index].insertItem(newItem->key);
}

bool HashTable::removeItem(string itemKey)
{
	int index = hash(itemKey);
	return array[index].removeItem(itemKey);
}

Item* HashTable::getItemByKey(string itemKey)
{
	int index = hash(itemKey);
	Item* searched = array[index].getItem(itemKey);
	if(!searched)
		cout<<endl<<itemKey<<" does not exist in the hash table.\n";

	return searched;
}

void HashTable::printTable()
{
	cout<<"\nHash Table:\n";
	for(int i=0;i<length;i++)
	{
		cout<<"Bucket "<<i+1<<": ";
		array[i].display();
	}
}

void HashTable::printHistogram()
{
	cout << "\nHash Table Contains ";
	cout << getNumberOfItems() << " Items total\n";
	
	for (int i = 0; i < length; i++)
	{
	    cout << i + 1 << ":\t";
	    for ( int j = 0; j < array[i].getLength(); j++ )
	        cout << " X";
	    cout << "\n";
	}
	cout<<endl;
}

int HashTable::getLength()
{
	return length;
}


int HashTable::getNumberOfItems()
{
	int itemCount = 0;

	for(int i=0;i<length;i++)
	{
		itemCount += array[i].getLength();
	} 

	return itemCount;
}

HashTable::~HashTable()
{
	cout<<"\nDeleting the hash table from the memory.\n\n";
	delete [] array;
}