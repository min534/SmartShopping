#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

// 기본 상품 클래스
class Item {
protected:
    string name;
    double price;

public:
    Item(string name, double price);
    virtual void displayInfo() const;
    double getPrice() const;
    virtual ~Item() {}
};

#endif
