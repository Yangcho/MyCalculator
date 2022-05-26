#include <iostream>

using namespace std;

class calculator
{
public:
    double val;//필요없음... 아래 템플릿에서 선언하면.

    calculator() : val(0)
    {}

    virtual calculator operator + (calculator) const;
    virtual calculator operator - (calculator) const;
    virtual calculator operator * (calculator) const;
    virtual calculator operator / (calculator) const;//기본 클래스의 사칙연산자를 가상함수로 선언
};

template <typename T>
class MyCalc : public calculator {
    void getdata()
    {
        cout << "enter number: ";
        cin >> val;
    }

    void showdata()
    {
        cout << "value: " << val << endl;
    }
};

//기본클래스를 상속받고 template 클래스로 작성하려고 고치는 중...


calculator calculator::operator + (calculator arg2) const
{
    calculator temp;
    temp.val = val + arg2.val;
    return temp;
}

calculator calculator::operator - (calculator arg2) const
{
    calculator temp;
    temp.val = val - arg2.val;
    return temp;
}

calculator calculator::operator * (calculator arg2) const
{
    calculator temp;
    temp.val = val * arg2.val;
    return temp;
}

calculator calculator::operator / (calculator arg2) const
{
    calculator temp;
    temp.val = val / arg2.val;
    return temp;
}

void main()
{
    calculator obj1, obj2, obj3;
    char ch;
    int choice;

    obj1.getdata();
    cout << "1st value entered: ";
    obj1.showdata();
    cout << endl;

    obj2.getdata();
    cout << "2nd value entered: ";
    obj2.showdata();
    cout << endl;

    cout << "Input choice as integer: 1: +,   2: -,   3: *,   4:/     ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        obj3 = obj1 + obj2;
        break;
    case 2:
        obj3 = obj1 - obj2;
        break;
    case 3:
        obj3 = obj1 * obj2;
        break;
    case 4:
        obj3 = obj1 / obj2;
        break;
    default:
        cout << "Invalid choice! " << endl;
    }

    cout << "Result ";
    obj3.showdata();
    cout << endl;

}


