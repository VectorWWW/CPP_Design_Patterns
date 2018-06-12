#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Singleton{
private:
    Singleton(){}
    static Singleton* single;
public:
    static Singleton* GetInstance(){
        if(single == NULL){
            single = new Singleton();
        }
        return single;
    }
};
Singleton* Singleton::single = NULL; // 注意静态变量类外部初始化

int main() {
    std::cout << "Hello, World!" << std::endl;
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();
    if (s1 == s2)
        cout << "OK" << endl;
    else
        cout << "NO" << endl;
    return 0;
}