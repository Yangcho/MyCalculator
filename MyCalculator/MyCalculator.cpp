#include <iostream>
using namespace std;

class MainCalc {
public:
    //자식 클래스가 상속할 기본 클래스
    //사칙 연산자를 가상함수로 여기서 선언
    //사칙연산 : 연산자로 구현
    //피연산자 : int, double 가능
    //피연산자에 따라 서로 다른 연산하도록 동일연산자 중복작성-연산자 오버로딩
};

class MyCalc : public MainCalc {
public:
    //파생된 계산기 클래스
    //여기서 class MainCalc의 가상함수를 재정의overriding
};

void main() {
    MyCalc();
}