#include <iostream>
#include <string>
using namespace std;

// 实例基类,相当于product(为了方便, 没用抽象)
class LeiFeng{
public:
    virtual void Sweep(){
        cout << "leifeng saodi" << endl;
    }
};
// 学雷锋的大学生, 相当于ConcreteProduct
class Student : public LeiFeng{
public:
    virtual void Sweep(){
        cout << "大学生扫地" << endl;
    }
};
// 学雷锋的志愿者, 相当于ConcreteProduct
class Volunteer : public LeiFeng{
    virtual void Sweep(){
        cout << "志愿者" << endl;
    }
};
// 工厂基类 Creator
class LeiFengFactory{
public:
    virtual LeiFeng* CreateLeiFeng(){
        return new LeiFeng();
    }
};
// 工厂具体类
class StudentFactory : public LeiFengFactory{
public:
    virtual LeiFeng* CreateLeiFeng(){
        return new Student();
    }
};
class VolunteerFactory : public LeiFengFactory{
public:
    virtual LeiFeng* CreateLeiFeng(){
        return new Volunteer();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

//    auto *sf = new LeiFengFactory();
    auto *sf = new StudentFactory();
    auto * s = sf->CreateLeiFeng();
    s->Sweep();
    delete s;
    delete sf;
    return 0;
}