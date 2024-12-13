#ifndef DISCOUNTITEM_H
#define DISCOUNTITEM_H

#include "Item.h"

class DiscountItem : public Item {
private:
    double discountRate;

public:
    DiscountItem(string name, double price, double discountRate);
    void displayInfo() const override;
    double getDiscountedPrice() const;
};

#endif
