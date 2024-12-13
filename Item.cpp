#include "Item.h"

Item::Item(string name, double price) : name(name), price(price) {}

void Item::displayInfo() const {
    cout << "상품명: " << name << ", 가격: " << price << "원" << endl;
}

double Item::getPrice() const {
    return price;
}
