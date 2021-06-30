//
// Created by user on 6/28/2021.
//

#ifndef SUPERMARKET_WITHOUT_OOP__CARTMANAGEMENT_H
#define SUPERMARKET_WITHOUT_OOP__CARTMANAGEMENT_H

/*UnUsefull*/string getFileNameId(string Id);
bool isCartExist(string filename);
int pickNewCart();
int addToCartById(vector<int> Ides, vector<int> Quantities);
int addCartToCustomersList(string Name);

#endif //SUPERMARKET_WITHOUT_OOP__CARTMANAGEMENT_H
