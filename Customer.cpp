#include "Customer.h"

Customer::Customer() {
    shoppingList = nullptr;
    numberOfItems = 0;
    counter = 0;
}

Customer::Customer(int numberOfItems) {
    this->numberOfItems = numberOfItems;
    shoppingList = new std::string [numberOfItems];
    counter = 0;
}

void Customer::generateRandomList() {
    numberOfItems = rand() % 30 + 1;
    shoppingList = new std::string [numberOfItems];

    int num;
    for (int i = 0; i < numberOfItems; ++i) {
        num = rand() % 2;
        if (num == 0) {
            shoppingList[i] = "fruit";
        } else {
            shoppingList[i] = "vegetable";
        }
    }
}

Customer::~Customer() {
    delete[] shoppingList;
}
