#include "SmartShopping.h"
#include "DiscountItem.h"
#include <fstream>

int main() {
    try {
        double budget;
        cout << "예산을 입력하세요: ";
        cin >> budget;

        SmartShopping shopping(budget);

        ifstream file("items.txt");
        if (!file) throw runtime_error("items.txt 파일을 열 수 없습니다.");

        string name;
        double price, discountRate;
        while (file >> name >> price >> discountRate) {
            if (discountRate > 0) {
                shopping.addItem(new DiscountItem(name, price, discountRate));
            } else {
                shopping.addItem(new Item(name, price));
            }
        }

        shopping.recommendItems();
    } catch (const exception& e) {
        cout << "오류: " << e.what() << endl;
    }

    return 0;
}
