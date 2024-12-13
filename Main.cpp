//
컴퓨터 프로그래밍 및 실습 평가과제
학과:컴퓨터공학과
학번:202302977
이름: 조민영
과제주제: 현재 기술의 발달로 인해 사진을 올리면 해당 상품을 찾아주는 어플이 많이 생겨났습니다. 이는 소비자들에게
    많은 편리함을 가져다주었습니다. 이를 넘어서 미래에는 소비자들이 다양한 상품 중에서 예산 내에 최적의 조합을
    찾을 수 있도록 도와주는 어플이 생긴다면 많은 도움을 줄 것이라 생각했습니다. 그래서 사용자의 예산과 선호도를 고려하여
    추천조합을 추천해주는 프로그램을 만들어보았습니다.
//

#include "SmartShopping.h"
#include "DiscountItem.h"
#include <fstream>

int main() {
    try {
        double budget;
        cout << "예산을 입력하세요: ";
        cin >> budget;
// 객체 생성
        SmartShopping shopping(budget);
        
// 파일 열어서 상품 정보 확인
        ifstream file("items.txt");
        if (!file) throw runtime_error("items.txt 파일을 열 수 없습니다.");

        string name;
        double price, discountRate;
// 파일 데이터 읽어서 객체 생성 및 추가
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
