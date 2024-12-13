#include "Item.h"

Item::Item(string name, double price) : name(name), price(price) {}
//상품의 정보 출력
void Item::displayInfo() const {
    cout << "상품명: " << name << ", 가격: " << price << "원" << endl;
}
// 상품의 가격 반환
double Item::getPrice() const {
    return price;
}
