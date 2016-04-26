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

    while(input != 6){
        cout << "======Main Menu======" << endl;
        cout << "1. Build Table" << endl;
        cout << "2. Most Common Word" << endl;
        cout << "3. Find Frequency" << endl;
        cout << "4. Remove Common Words"<<endl;
        cout << "5. Specs" << endl;
        cout << "6. Quit" << endl;
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
            h.printTableContents();
        }
        if(input == 3){

        }
        if(input == 4){

        }


    }
    cout<<"Goodbye!"<<endl;

    return 0;
}
