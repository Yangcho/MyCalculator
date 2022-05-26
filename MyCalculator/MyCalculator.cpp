#include <iostream>
#include <fstream>
using namespace std;

int err = 0;

class MainCalc {
public:
    //�ڽ� Ŭ������ ����� �⺻ Ŭ����
    //��Ģ �����ڸ� �����Լ��� ���⼭ ����

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

    //��Ģ���� : �����ڷ� ����
    //�ǿ����� : int, double ���� ok
    //�ǿ����ڿ� ���� ���� �ٸ� �����ϵ��� ���Ͽ����� �ߺ��ۼ�-������ �����ε� ok
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
        catch (T n) { cout << "0���� ������ ���� !!" << endl; err = 1; }
        return tmp;
    }
    //�Ļ��� ���� Ŭ���� ok
    //template Ŭ������ �ۼ��ؾ� �� template <typename T> ok
    //���⼭ class MainCalc�� �����Լ��� ������overriding ?????
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