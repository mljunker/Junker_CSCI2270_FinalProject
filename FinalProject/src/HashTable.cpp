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
    if(word != " " && word != "\n"&& word != ""){

        int index = hashSum(word, tableSize);
        //std::cout<<index<<word<<std::endl;
        if(hashTable[index] == NULL){
            //std::cout<<"check if"<<std::endl;
            hashTable[index] = new HashElem;
            hashTable[index] -> word = word;
            hashTable[index] -> number = 1;
            hashTable[index] -> next = NULL;
            hashTable[index] -> previous = NULL;
        }
        else{
            //std::cout<<"check else"<<std::endl;
            bool match = false;
            HashElem * loc = hashTable[index];
            while(loc -> next != NULL && match == false){
                if(loc -> word == word){
                    match = true;
                    break;
                }
                loc = loc -> next;
            }
            if(match){
                loc -> number ++;
            }
            else{
                if(loc -> word == word){
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
    }
}
void HashTable::printTableContents(){
    bool empty = true;
    for(int i = 0; i < 100; i++){
        if(hashTable[i]!=NULL){
            //std::cout<<i<<std::endl;
            HashElem *temp = hashTable[i];
            std::cout<<temp->word<<" appears: "<<temp->number<<" times"<<std::endl;
            while(temp->next!=NULL){
                empty = false;
                temp = temp->next;
                std::cout<<temp->word<<" appears: "<<temp->number<<" times"<<std::endl;

            }
        }
    }
    if(empty){
        std::cout << "empty" << std::endl;
    }
}
void HashTable::sortarray(wordinfo mostcommon[],int num){
    //bubble sort algorithm based on that of https://www.cs.cmu.edu/~adamchik/15-121/lectures/Sorting%20Algorithms/sorting.html
    for (int i = (num - 1); i >= 0; i--){
        for (int j = 1; j <= i; j++){
            if (mostcommon[j-1].number > mostcommon[j].number){
                wordinfo temp = mostcommon[j-1];
                mostcommon[j-1] = mostcommon[j];
                mostcommon[j] = temp;
            }
        }
   }
}
void HashTable::commonWords(int num){
    wordinfo mostcommon[num];
    for(int x = 0; x < num; x++){
        mostcommon[x].word = hashTable[x]->word;
        mostcommon[x].number = hashTable[x]->number;
        //to allow comparison without seg fault
    }
    sortarray(mostcommon,num);
    //to start with word with greatest occurences at front
    for(int i = 0; i < 100; i++){
        if(hashTable[i]!=NULL){
            HashElem * loc = hashTable[i];
            wordinfo temp;
            temp.number = hashTable[i]->number;
            temp.word = hashTable[i]->word;
            if(temp.number >= mostcommon[0].number){
                bool add = true;
                for(int k = 0; k < num; k++){
                    if(temp.word == mostcommon[k].word){
                        add = false;
                    }
                }
                if(add){
                    //if word more frequent that least frequent word in most common array
                    //it gets added to the array
                    mostcommon[0] = temp;
                    //it may still be greater than some of the other words too so the common array must be sorted
                    sortarray(mostcommon,num);
                }
            }
            while(loc->next!=NULL){
                loc = loc->next;
                temp.number = loc->number;
                temp.word = loc->word;
                if(temp.number >= mostcommon[0].number ){
                    bool add = true;
                    for(int k = 0; k < num; k++){
                        if(temp.word == mostcommon[k].word){
                            add = false;
                        }
                    }
                    if(add){
                        //if word more frequent that least frequent word in most common array
                        //it gets added to the array
                        mostcommon[0] = temp;
                        //it may still be greater than some of the other words too so the common array must be sorted
                        sortarray(mostcommon,num);
                    }
                }
            }
        }
    }
    //once hash table has been run through, top words should be correctly organized
    int count = 1;
    for(int j = num-1; j >=0; j--){
        std::cout<< count<< " : " << mostcommon[j].word << " appears: " << mostcommon[j].number<< std::endl;
        count++;
    }
}
void HashTable::findWord(std::string word){
    bool found = false;
    int index = hashSum(word,tableSize);
    HashElem *temp = hashTable[index];
    if(temp!=NULL){
        while(temp->next!=NULL&&found==false){
            temp = temp->next;
            if(temp->word == word){
                found = true;
            }
        }
        if(found){
            std::cout << index << ":" << temp->word << " appears:" << temp->number << std::endl;
        }
        else{
            std::cout << "not found" << std::endl;
        }
    }
    else{
        std::cout << "not found" << std::endl;
    }

}
void HashTable::deleteWord(std::string word){
    bool found = false;
    int index = hashSum(word,tableSize);
    HashElem *temp = hashTable[index];
    if(temp!=NULL){
        while(temp->next!=NULL&&found==false){
            temp = temp->next;
            if(temp->word == word){
                found = true;
            }
        }
        if(found){
            if(temp->next != NULL){
                //has nodes after
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
            }
            if(temp-> next == NULL){
                //is last node in list
                temp->previous->next = temp->next;

            }

            if(hashTable[index]->next == NULL){
                hashTable[index]=NULL;
            }
            delete temp;
        }
    }

}
