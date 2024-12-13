#include "DiscountItem.h"

DiscountItem::DiscountItem(string name, double price, double discountRate)
    : Item(name, price), discountRate(discountRate) {}

void DiscountItem::displayInfo() const {
    cout << "상품명: " << name << ", 원래 가격: " << price << "원"
         << ", 할인율: " << discountRate * 100 << "%, 할인 가격: " << getDiscountedPrice() << "원" << endl;
}

double DiscountItem::getDiscountedPrice() const {
    return price * (1 - discountRate);
}
