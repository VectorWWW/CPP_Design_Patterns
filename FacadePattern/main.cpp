#include <iostream>
#include <string>
using namespace std;

class SubSysOne{
public:
    void MethodOne(){
        cout << "method one" << endl;
    }
};

class SubSysTwo{
public:
    void MethodTwo(){
        cout << "method two" << endl;
    }
};

class SubSysThree{
public:
    void MethodThree(){
        cout << "method three" << endl;
    }
};

class Facade{
private:
    SubSysOne* sub1;
    SubSysTwo* sub2;
    SubSysThree* sub3;
public:
    Facade(){
        sub1 = new SubSysOne();
        sub2 = new SubSysTwo();
        sub3 = new SubSysThree();
    }
    ~Facade(){
        delete sub1;
        delete sub2;
        delete sub3;
    }
    void FacadeMethod(){
        sub1->MethodOne();
        sub2->MethodTwo();
        sub3->MethodThree();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto * test = new Facade();
    test->FacadeMethod();
    return 0;
}