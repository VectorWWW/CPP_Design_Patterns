#include <iostream>
#include <string>
using namespace std;
// 人
class Person{
private:
    string m_strName;
public:
    Person(string strName){
        m_strName = strName;
    }
    Person(){}
    virtual void show(){
        cout << "what is decotrated is :" << m_strName << endl;
    }
};
// 装饰类
class Finery : public Person{
protected:
    Person* m_component;
public:
    void Decorate(Person* component){
        m_component = component;
    }
    virtual void show(){
        m_component->show();
    }
};
// T恤
class Tshirts : public Finery{
public:
    virtual void show(){
        cout << "T shirts" << endl;
        m_component->show();
    }
};
// 裤子
class BigTrousers : public Finery{
public:
    virtual void show(){
        cout << "Big Trouser" << endl;
        m_component->show();
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    auto p = new Person("xiao li");
    auto bt = new BigTrousers();
    auto ts = new Tshirts();

    bt->Decorate(p);
    ts->Decorate(bt);
    ts->show();
    return 0;
}