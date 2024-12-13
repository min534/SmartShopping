#include "SmartShopping.h"
#include "DiscountItem.h"
// 클래스 생성자 정의
SmartShopping::SmartShopping(double budget) {
    if (budget <= 0) throw runtime_error("예산은 0보다 커야 합니다.");
    this->budget = budget;
}
// aaditem: 새로운 상품 리스트에 추가
// Item 포인터 받아서 저장
void SmartShopping::addItem(Item* item) {
    items.push_back(item);
}
// 예산내 추가 가능한 상품 출력
void SmartShopping::recommendItems() const {
    cout << "=== 추천 상품 목록 ===" << endl;
    double totalCost = 0;
// 상품 리스트 순회하며 예산초과하지 않는 상품 추천
    for (const auto& item : items) {
        if (totalCost + item->getPrice() <= budget) {
            item->displayInfo();
            totalCost += item->getPrice();
        }
    }
// 최종 정보 출력
    cout << "총 비용: " << totalCost << "원 / 예산: " << budget << "원" << endl;
}

SmartShopping::~SmartShopping() {
    for (auto& item : items) {
        delete item;
    }
}
