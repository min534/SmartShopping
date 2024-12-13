#ifndef SMARTSHOPPING_H
#define SMARTSHOPPING_H

#include "Item.h"
#include <vector>
#include <stdexcept>
using namespace std;

class SmartShopping {
private:
    vector<Item*> items;
    double budget;

public:
    SmartShopping(double budget);
    void addItem(Item* item);
    void recommendItems() const;
    ~SmartShopping();
};

#endif
