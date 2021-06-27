//
// Created by user on 6/24/2021.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <tuple>
#include <map>

using namespace std;

#include "StorageManagement.h"
#include "ConvertionsSystem.h"

string filename = "Product-Price.csv";
int val;
ifstream myFile(filename);

vector<string> filter() {
    string line;
    vector<string> words;
    string word;

    while(getline(myFile, line)){
        bool read=false, _read=false, First=false;
        //cout << "Line Size: " << line.size() << endl;

        for(int i = 0; i < line.size(); i++){
            if(line[i] == '"' and !First){
                _read = true;
                First = true;
                continue;
            }else if(line[i] == '"' and First){
                _read = false;
                First = false;
                continue;
            }



            if(_read){
                word += line[i];
            }else{
                if(line[i] != '"' and line[i] != ',')
                    read = true;

                if(line[i] == ','){ //"ahmed,",abdo
                    words.push_back(word);
                    word = "";
                }

                if(read == true){
                    word += line[i];
                    read = false;
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

vector<tuple<int, string, double, int>> products(){

    vector<tuple<int, string, double, int>> output;
    vector<string> words = filter();

    for(int i = 0; i < words.size();){
        output.push_back(make_tuple(strToInt(words[i]), words[i+1], strToDouble(words[i+2]), strToInt(words[i+3])));
        i += 4;
    }

    return output;
}

map<int, tuple<string, double, int>> storage;

void fillStorage(){
    for(auto tp : products()){
        storage.insert({get<0>(tp), make_tuple(get<1>(tp), get<2>(tp), get<3>(tp))});
    }
}

vector<string> getProductsName(){
    vector<string> names;

    for(auto x : products()){
        names.push_back(get<1>(x));
    }

    return names;
}

vector<double> getProductsPrice(){
    vector<double> prices;

    for(auto x : products()){
        //cout << get<2>(x) << endl;
        prices.push_back(get<2>(x));
    }

    return prices;
}

vector<int> getProductsQuantity(){
    vector<int> quantities;

    for(auto x : products()){
        quantities.push_back(get<3>(x));
    }
    return quantities;
}

void printProducts(){
    //fillStorage();
    /*for(auto product : storage){
        //cout << "Id: " << product.first << " | Product: " << get<0>(product.second) << " | Price: " << get<1>(product.second) << " | Quantity: " << get<2>(product.second) << endl;
    }*/

    vector<tuple<int, string, double, int>> product = products();

    for(auto x : product){
        cout << get<1>(x) << endl;
    }
}

/*void InsertProduct(string Name, double Price, int Quantity){
    int Id=0;
// TODO (user#1#06/25/21): Complete this funcation

    storage.insert(make_pair(Id, make_tuple(Name, Price, Quantity)));
}*/











