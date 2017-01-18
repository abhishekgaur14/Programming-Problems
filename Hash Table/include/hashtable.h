#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"

class HashTable
{
		LinkedList* array;
		int length;
		int hash(string itemKey);

	public:
		HashTable(int tableLength=13);
		void insertItem(Item* item);
		bool removeItem(string itemKey);
		Item* getItemByKey(string itemKey);
		void printTable();
		void printHistogram();
		int getLength();
		int getNumberOfItems();
		~HashTable();
};

#endif