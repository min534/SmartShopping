#include "SmartShopping.h"
#include "DiscountItem.h"

SmartShopping::SmartShopping(double budget) {
    if (budget <= 0) throw runtime_error("예산은 0보다 커야 합니다.");
    this->budget = budget;
}

void SmartShopping::addItem(Item* item) {
    items.push_back(item);
}

void SmartShopping::recommendItems() const {
    cout << "=== 추천 상품 목록 ===" << endl;
    double totalCost = 0;

    for (const auto& item : items) {
        if (totalCost + item->getPrice() <= budget) {
            item->displayInfo();
            totalCost += item->getPrice();
        }
    }

    cout << "총 비용: " << totalCost << "원 / 예산: " << budget << "원" << endl;
}

SmartShopping::~SmartShopping() {
    for (auto& item : items) {
        delete item;
    }
}
