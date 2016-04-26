#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

struct HashElem{
	std::string word;
	int number;
	HashElem *next;
    HashElem *previous;

	HashElem(){};
	HashElem(std::string in_word, int in_number)
	{
		word = in_word;
		number = in_number;
		next = NULL;
		previous = NULL;
	}

};

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void printTableContents();
		void insertWord(std::string word);
		void deleteWord(std::string word);
		void findWord(std::string word);
	private:
		int hashSum(std::string x, int s);
		int tableSize = 100;
		HashElem* hashTable[100];

};

#endif // HASHTABLE_H
