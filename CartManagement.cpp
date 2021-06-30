//
// Created by user on 6/28/2021.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#include "CartManagement.h"
#include "StorageManagement.h"
#include "MainMenuManagement.h"
#include "ConvertionsSystem.h"

vector<string> Customers = {"s"};

vector<string> filter(string filename) {
    int val;
    ifstream myFile(filename);
    string line="";
    vector<string> words;
    string word;

    while(getline(myFile, line)){
        bool _reading = false /*switch between reading word or not if there (") or (,)*/ , first = false;

        for(int i = 0; i < line.size(); i++){
            if(line[i] == '"' and !first){ // make _reading true if there (") in another char excpet first char
                _reading = true;
                first = true;
                continue;//jump to next char
            }else if(line[i] == '"' and first){ // make _reading false if there (") in first char
                _reading = false;
                first = false;
                continue;//jump to next char
            }



            if(_reading){
                word += line[i];
            }else{
                bool reading = false /*switch between reading word or not if there (") and (,)*/;

                if(line[i] != '"' and line[i] != ',') // make reading true unless there (") and (,)
                    reading = true;

                if(line[i] == ','){
                    words.push_back(word);
                    word = "";
                }

                if(reading == true){
                    word += line[i];
                    reading = false;
                    if(i+1 == line.size()){
                        words.push_back(word);
                        word = "";
                    }
                }
            }
        }

    }

    return words;
}

int fillCustomers(){
    vector<string> customers = filter("Customers.csv");
    for(auto s:customers){
        Customers.push_back(s);
    }
}

/*UnUsefull*/string getFileNameId(string Id){
    string id;
    for(int i=0;i<Id.size();i++){
        for(char c:"1234567890"){
            if(Id[i] == c){
                id += Id[i];
            }else if(Id[i] == '.'){
                break;
            }
        }
    }

    for (char c : "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") {
        id.erase(remove(id.begin(), id.end(), c), id.end());
    }
    return id;
}

bool isCartExist(string filename){
    ifstream file(filename);
    if(file.is_open()){
        return true;
    }else{
        return false;
    }
    return false;
}

int pickNewCart(){
    fillCustomers();
    string name;
    string filename;
    f:
    cout << "Please Enter Customer Name: ";
    cin >> name;

    for(char c:"\/:*?\"<>|"){
        for(char f:name){
            if(f == c){
                cout << "Please Don't But These Char (\/:*?\"<>|)" << endl;
                goto f;
            }
        }
    }

    filename = name + ".csv";

    for(auto s:Customers){
        if(name != s){
            Customers.push_back(name);
            addCartToCustomersList(filename);
        }
    }

    ofstream myFile(filename);
    myFile << name;

    myFile.close();

    return 1;
}

int addToCartById(vector<int> Ides, vector<int> Quantities){
    string toCart;
    for(int i=0; i<Ides.size();i++){
        toCart += trim(get<0>(getProductNameById(Ides[i]))) + ',' + trim(numToStr(get<1>(getProductNameById(Ides[i])) * Quantities[i])) + ',' + trim(numToStr(Quantities[i])) + '\n';
    }
}

int addCartToCustomersList(string Name){
    ofstream CustomersList("Customers.csv", ios::app);
    CustomersList << Name+',';
    CustomersList.close();
}



