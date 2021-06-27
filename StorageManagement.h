//
// Created by user on 6/21/2021.
//

#ifndef SUPERMARKET_WITHOUT_OOP__STORAGEMANAGEMENT_H
#define SUPERMARKET_WITHOUT_OOP__STORAGEMANAGEMENT_H

vector<string> filter();
vector<tuple<int, string, double, int>> products();
vector<string> getProductsName();
vector<double> getProductsPrice();
vector<int> getProductsQuantity();
void printProducts();
//void InsertProduct(string Name, double Price, int Quantity); //Uncompleted

#endif //SUPERMARKET_WITHOUT_OOP__STORAGEMANAGEMENT_H
