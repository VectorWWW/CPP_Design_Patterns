//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Component{
//public:
//    string m_strName;
//    Component(string strName){
//        m_strName = strName;
//    }
//    virtual void Add(Component* com) = 0;
//    virtual void Display(int nDepth) = 0;
//};
//
//class Leaf : public Component{
//public:
//    Leaf(string strName) : Component(strName){}
//
//    virtual void Add(Component* com){
//        cout << "leaf can't add" << endl;
//    }
//
//    virtual void Display(int nDepth){
//        string strTemp;
//        for (int i = 0; i < nDepth; i++){
//            strTemp += "-";
//        }
//        strTemp += m_strName;
//        cout << strTemp << endl;
//    }
//};
//
//class Composite : public Component{
//private:
//    vector<Component*> m_component;
//public:
//    Composite(string strName) : Component(strName){}
//    virtual void Add(Component* com){
//        m_component.push_back(com);
//    }
//    virtual void Display(int nDepth){
//        string strTemp;
//        for(int i = 0; i < nDepth; i++){
//            strTemp += "-";
//        }
//        strTemp += m_strName;
//        cout << strTemp <<endl;
//        vector<Component*>::iterator p = m_component.begin();
//        while(p != m_component.end()){
//            (*p)->Display(nDepth + 2);
//            p++;
//        }
//    }
//};
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//
//    Composite* p = new Composite("Wang");
//    p->Add(new Leaf("Lee"));
//    p->Add(new Leaf("Zhao"));
//
//    Composite* p1 = new Composite("Wu");
//    p1->Add(new Leaf("San"));
//
//    p->Add(p1);
//    p->Display(1);
//
//    return 0;
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Company{
protected:
    string m_strName;
public:
    Company(string strName){
        m_strName = strName;
    }
    virtual void Add(Company* c) = 0;
    virtual void Display(int nDepth) = 0;
    virtual void LineOfDuty() = 0;
};

class ConcreteCompany : public Company{
private:
    vector<Company*> m_company;
public:
    ConcreteCompany(string strName) : Company(strName) {}
    virtual void Add(Company* c){
        m_company.push_back(c);
    }
    virtual void Display(int nDepth) {
        string strTemp;
        for(int i = 0; i < nDepth; i++){
            strTemp += "-";
        }
        strTemp += m_strName;
        cout << strTemp << endl;

        vector<Company*>::iterator p = m_company.begin();
        while(p != m_company.end()){
            (*p)->Display(nDepth + 2);
            p++;
        }
    }
    virtual void LineOfDuty(){
        vector<Company*>::iterator p = m_company.begin();
        while(p != m_company.end()){
            (*p)->LineOfDuty();
            p++;
        }
    }
};

class HrDepartment : public Company{
public:
    HrDepartment(string strName) : Company(strName){}
    virtual void Display(int nDepth){
        string strTemp;
        for (int i = 0; i < nDepth ; ++i) {
            strTemp += "-";
        }
        strTemp += m_strName;
        cout << strTemp << endl;
    }
    virtual void Add(Company* c){
        cout << "error" << endl;
    }
    virtual void LineOfDuty(){
        cout << m_strName << ": hr" << endl;
    }
};

int main(){
    ConcreteCompany* p = new ConcreteCompany("Tsinghua University");
    p->Add(new HrDepartment("Tsinghua University Hr"));

    ConcreteCompany* p1 = new ConcreteCompany("Department of Mathematics");
    p1->Add(new HrDepartment("Mathematics Hr"));

    ConcreteCompany* p2 = new ConcreteCompany("Department of Physics");
    p2->Add(new HrDepartment("Physics Hr"));

    p->Add(p1);
    p->Add(p2);

    p->Display(1);
    p->LineOfDuty();

    return 0;
}