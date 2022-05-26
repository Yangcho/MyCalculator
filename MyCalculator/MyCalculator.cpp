#include <iostream>
#include <fstream>
using namespace std;

int err = 0;

class MainCalc {
public:
    //자식 클래스가 상속할 기본 클래스
    //사칙 연산자를 가상함수로 여기서 선언

    virtual void operator+(const MainCalc) {}
    virtual void operator-(const MainCalc) {}
    virtual void operator*(const MainCalc) {}
    virtual void operator/(const MainCalc) {}
    //virtual MainCalc& operator-(const MainCalc&) { }
    //virtual MainCalc& operator*(const MainCalc&) { }
    //virtual MainCalc& operator/(const MainCalc&) { }
    //virtual MainCalc operator-(int a) {};
    //virtual MainCalc operator*(int a) {};
    //virtual MainCalc operator/(int a) {};

    //사칙연산 : 연산자로 구현
    //피연산자 : int, double 가능 ok
    //피연산자에 따라 서로 다른 연산하도록 동일연산자 중복작성-연산자 오버로딩 ok
};

template <typename T>
class MyCalc : public MainCalc {
    T Data;
public:
    MyCalc(T Data = 0) {
        this->Data = Data;
    }
    double show() { if (err != 1)cout << Data << endl; return Data; };
    MyCalc operator+(MyCalc op2) {
        MyCalc tmp;
        tmp.Data = Data + op2.Data;
        return tmp;
    }
    MyCalc operator-(MyCalc op2) {
        MyCalc tmp;
        tmp.Data = Data - op2.Data;
        return tmp;
    }
    MyCalc operator*(MyCalc op2) {
        MyCalc tmp;
        tmp.Data = Data * op2.Data;
        return tmp;
    }
    MyCalc operator/(MyCalc op2) {
        MyCalc tmp;
        try {
            if (op2.Data == 0)throw op2.Data;
            else tmp.Data = Data / op2.Data;
        }
        catch (T n) { cout << "0으로 나누는 오류 !!" << endl; err = 1; }
        return tmp;
    }
    //파생된 계산기 클래스 ok
    //template 클래스로 작성해야 함 template <typename T> ok
    //여기서 class MainCalc의 가상함수를 재정의overriding ?????
};



int main() {
    MyCalc<double> op1(1), op2(12), op3(0), op4(1.2), op5(1.02);
    op1 = op1 + op2 / op4 * op5;
    op1.show();

    double data = op1.show();
    ofstream fout("\DATA.txt");
    fout << data << endl;
    fout.close();
}