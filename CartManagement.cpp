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

vector<int> Customers;

bool checkCustomer(string Id){
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

    cout << id<<endl;
    return false;
}

int pickNewCart(){
    string filename="CustomerId1.csv";
    //Customers.push_back(filename);

    ofstream myFile(filename);

    string cartIdes="-----------------------StartOfMenu-----------------------";

    myFile << cartIdes;
    myFile.close();
    // FIXME (user#1#06/29/21): doesn't create file

    return 1;
}

int addToCartById(vector<int> Ides, vector<int> Quantities){
    string toCart;
    for(int i=0; i<Ides.size();i++){
        toCart += trim(get<0>(getProductNameById(Ides[i]))) + ',' + trim(numToStr(get<1>(getProductNameById(Ides[i])) * Quantities[i])) + ',' + trim(numToStr(Quantities[i])) + '\n';
    }
}





