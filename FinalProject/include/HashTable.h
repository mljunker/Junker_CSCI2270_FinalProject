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

struct wordinfo{
    std::string word;
    int number;
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
		void commonWords(int num);
		void sortarray(wordinfo mostcommon[],int num);
		int wordcount();
		int totalwords();
	private:
		int hashSum(std::string x, int s);
		int tableSize = 100;
		HashElem* hashTable[100];
        std::string ignore[50] = {"the","be","to","of","and","a","in","that","have","i","it","for","not","on","with","he","as","you","do","at","this","but","his","by","from","they","we","say","her","she","or","an","will","my","one","all","would","there","their","what","so","up","out","if","about","who","get","which","go","me"};

};

#endif // HASHTABLE_H
