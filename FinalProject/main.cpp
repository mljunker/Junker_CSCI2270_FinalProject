#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "HashTable.h"


using namespace std;

int main()
{
    HashTable h;

    ifstream inFile; // create instance
    string data;
    int ranking;
    string word;
    int number;
    int quantity;


    //input
    int input = 0 ;
    //menu

    while(input != 7){
        cout << "======Main Menu======" << endl;
        cout << "1. Build Table" << endl;
        cout << "2. Most Common Words" << endl;
        cout << "3. Find Frequency" << endl;
        cout << "4. Print Table"<<endl;
        cout << "5. Delete Word" << endl;
        cout << "6. Specs"<<endl;
        cout << "7. Quit" << endl;
        //make sure input is in right format
        string temp;
        getline(cin,temp);
        input= atoi(temp.c_str());

        if(input == 1){
            inFile.open("HungerGames_edit.txt");
            if (inFile.good()){
                while(getline(inFile,data,' ')){
                    stringstream ss(data);
                    string temp;
                    ss>>temp;
                    h.insertWord(temp);

                }
            }
        }
        if(input == 2){
            int num;
            cout << "How many top words do you want?:" << endl;
            getline(cin,temp);
            num = atoi(temp.c_str());
            h.commonWords(num);

        }
        if(input == 3){
            cout << "What word are you looking for?:" << endl;
            getline(cin,temp);
            h.findWord(temp);

        }
        if(input == 4){
            h.printTableContents();
        }
        if(input == 5){
            cout << "What word do you want to remove?:" << endl;
            getline(cin,temp);
            h.deleteWord(temp);
        }
        if(input == 6){
            int count = h.wordcount();
            cout << "Individual words: "<< count << endl;
            count = h.totalwords();
            cout << "Total words: "<< count << endl;
        }

    }
    cout<<"Goodbye!"<<endl;

    return 0;
}
