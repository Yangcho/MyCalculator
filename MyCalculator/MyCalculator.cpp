#include <iostream>
using namespace std;

class MainCalc {
public:
    //�ڽ� Ŭ������ ����� �⺻ Ŭ����
    //��Ģ �����ڸ� �����Լ��� ���⼭ ����
    //��Ģ���� : �����ڷ� ����
    //�ǿ����� : int, double ����
    //�ǿ����ڿ� ���� ���� �ٸ� �����ϵ��� ���Ͽ����� �ߺ��ۼ�-������ �����ε�
};

class MyCalc : public MainCalc {
public:
    //�Ļ��� ���� Ŭ����
    //���⼭ class MainCalc�� �����Լ��� ������overriding
};

void main() {
    MyCalc();
}