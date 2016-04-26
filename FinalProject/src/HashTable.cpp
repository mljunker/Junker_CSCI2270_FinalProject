#include "HashTable.h"
#include <iostream>
#include <string>

HashTable::HashTable()
{
    //ctor
    for(int i = 0; i < 100; i++){
        hashTable[i]=NULL;
    }
}

HashTable::~HashTable()
{
    //dtor
}
int HashTable::hashSum(std::string x, int s){
    //initialize sum
    int sum = 0;
    //go through length of string x and add ASCII values
    for(int i = 0; i < x.length(); i++){
        sum = sum + x[i];
    }
    int num = sum%s;
    return num;
}
void HashTable::insertWord(std::string word){
    int index = hashSum(word, tableSize);
    std::cout<<index<<word<<std::endl;
    if(hashTable[index] == NULL){
        std::cout<<"check if"<<std::endl;
        hashTable[index] = new HashElem;
        hashTable[index] -> word = word;
        hashTable[index] -> number = 1;
        hashTable[index] -> next = NULL;
        hashTable[index] -> previous = NULL;
    }
    else{
        std::cout<<"check else"<<std::endl;
        bool match = false;
        HashElem * loc = hashTable[index];
        while(loc -> next != NULL && match == false){
            if(loc -> word == word){
                match = true;
            }
            loc = loc -> next;
        }
        if(match){
            loc -> number ++;
        }
        else{
            HashElem *tmp = new HashElem;
            tmp -> previous = loc;
            tmp -> next = NULL;
            tmp -> number = 1;
            tmp -> word = word;
            loc -> next = tmp;
        }
    }
}
void HashTable::printTableContents(){
    bool empty = true;
    for(int i = 0; i < 10; i++){
        if(hashTable[i]!=NULL){
            HashElem *temp = hashTable[i];
            //std::cout<<i<<temp->word<<":"<<temp->number<<std::endl;
            while(temp->next!=NULL){
                empty = false;
                temp = temp->next;
                std::cout<<temp->word<<":"<<temp->number<<std::endl;

            }
        }
    }
    if(empty){
        std::cout << "empty" << std::endl;
    }
}
