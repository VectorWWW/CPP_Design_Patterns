#include <iostream>
using namespace std;

class Target{
public:
    virtual void Request(){
        cout << "normal request" << endl;
    }
};

class Adaptee{
public:
    void SpecificalRequest(){
        cout << "special request" << endl;
    }
};

class Adapter : public Target{
private:
    Adaptee* ada;
public:
    virtual void Request(){
        ada->SpecificalRequest();
        Target::Request();
    }
    Adapter(){
        ada = new Adaptee();
    }
    ~Adapter(){
        delete ada;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    Adapter* ada = new Adapter();
    ada->Request();
    delete ada;

    return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Player{
//protected:
//    string name;
//public:
//    Player(string strName) { name = strName; }
//    virtual void Attack() = 0;
//    virtual void Defense() = 0;
//};
//
//class Forwards : public Player{
//public:
//    Forwards(string strName) : Player(strName){}
//
//public:
//    virtual void Attack(){
//        cout << name << "Forwards attack" << endl;
//    }
//    virtual void Defense(){
//        cout << name << "Forwards defense" << endl;
//    }
//};
//
//class Center : public Player{
//public:
//    Center(string strName) : Player(strName){}
//
//public:
//    virtual void Attack(){
//        cout << name << "Center Attack" << endl;
//    }
//    virtual void Defense(){
//        cout << name << "Center defense" << endl;
//    }
//};
//
//class TransLater : public Player{
//private:
//    Center* player;
//public:
//    TransLater(string strName) : Player(strName) {
//        player = new Center(strName);
//    }
//    virtual void Attack(){
//        player->Attack();
//    }
//    virtual void Defense(){
//        player->Defense();
//    }
//};
//
//int main(){
//    Player*p = new TransLater("Lee ");
//    p->Attack();
//
//    return 0;
//}