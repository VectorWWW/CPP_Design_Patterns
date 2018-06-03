#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AbstractClass{
public:
    void Show(){
        cout << "I am " << GetName() << endl;
    }

protected:
    virtual string GetName() = 0;
};

class Naruto : public AbstractClass{
protected:
    virtual string GetName(){
        return "Naruto";
    }
};

class OnePice : public AbstractClass{
protected:
    virtual string GetName(){
        return "Luffy";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Naruto* man = new Naruto();
    man->Show();

    OnePice* man2 = new OnePice();
    man2->Show();

    return 0;
}