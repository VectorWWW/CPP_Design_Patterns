/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Secretary;
// 看股票的同事类
class StockObserver{
private:
    string name;
    Secretary* sub;
public:
    StockObserver(string strname, Secretary* strsub){
        name = strname;
        sub = strsub;
    }
    void Update();
};

// 秘书类（主题对象，通职者）
class Secretary{
private:
    vector<StockObserver> observers;
public:
    string action;
    void Add(StockObserver ob){
        observers.push_back(ob);
    }
    void Notify(){
        vector<StockObserver>::iterator p = observers.begin();
        while (p!=observers.end()){
            (*p).Update();
            p++;
        }
    }
};

void StockObserver::Update() {
    cout << name << ":" << sub->action << ", no stock, start working" << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    Secretary *p = new Secretary();

    StockObserver *s1 = new StockObserver("xiaoli", p);
    auto* s2 = new StockObserver("xiao zhao", p);

    p->Add(*s1);
    p->Add(*s2);

    p->action = "boss coming";

    p->Notify();
    return 0;
}
 */

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class SecretaryBase;
// 抽象观察者
class CObserverBase{
protected:
    string name;
    SecretaryBase* sub;
public:
    CObserverBase(string strname, SecretaryBase* strsub){
        name = strname;
        sub = strsub;
    }
    virtual void Update() = 0;
};
// 具体观察者，看股票的
class StockObserver : public CObserverBase{
public:
    StockObserver(string strname, SecretaryBase* strsub) : CObserverBase(strname, strsub){}
    virtual void Update();
};
// 具体观察者，看NBA的
class NBAObserver : public CObserverBase{
public:
    NBAObserver(string strname, SecretaryBase* strsub) : CObserverBase(strname, strsub){}
    virtual void Update();
};
// 抽象通知者
class SecretaryBase{
public:
    string action;
    vector<CObserverBase* > observers;
public:
    virtual void Attach(CObserverBase* observer) = 0;
    virtual void Notify() = 0;
};
// 具体通知者
class Secretary : public SecretaryBase{
public:
    void Attach(CObserverBase* ob){
        observers.push_back(ob);
    }
    void Notify(){
        vector<CObserverBase*>::iterator p = observers.begin();
        while(p != observers.end()){
            (*p)->Update();
            p++;
        }
    }
};

void StockObserver::Update(){
    cout << name << ":" << sub->action << ", no stock, start working" << endl;
}

void NBAObserver::Update() {
    cout << name << ":" << sub->action << ", no NBA, start working" << endl;
}

int main(){
    // 创建观察者
    SecretaryBase* p = new Secretary();
    // 被观察的对象
    CObserverBase* s1 = new NBAObserver("xiao li", p);
    CObserverBase* s2 = new StockObserver("xiao zhao", p);
    // 加入观察者队列
    p->Attach(s1);
    p->Attach(s2);
    // 事件
    p->action = "boss coming";
    // 通知
    p->Notify();

    return 0;
}