#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 用户抽象接口
class IUser{
public:
    virtual void GetUser() = 0;
    virtual void InsertUser() = 0;
};

// 部门抽象接口
class IDepartment{
public:
    virtual void GetDepartment() = 0;
    virtual void InsertDepartment() = 0;
};

// ACCESS 用户
class CAccessUser : public IUser{
public:
    virtual void GetUser(){
        cout << "Access GetUser" << endl;
    }
    virtual void InsertUser(){
        cout << "Access InsertUser" << endl;
    }
};

// ACCESS 部门
class CAccessDepartment : public IDepartment{
public:
    virtual void GetDepartment(){
        cout << "Access GetDepartment" << endl;
    }
    virtual void InsertDepartment(){
        cout << "Access InsertDepartment" << endl;
    }
};

// SQL 用户
class CSqlUser : public IUser{
public:
    virtual void GetUser(){
        cout << "sql GetUser" << endl;
    }
    virtual void InsertUser(){
        cout << "sql InserUser" << endl;
    }
};

// SQL 部门类
class CSqlDepartment : public IDepartment{
public:
    virtual void GetDepartment(){
        cout << "sql GetDepartment" << endl;
    }
    virtual void InsertDepartment(){
        cout << "sql InserDepartment" << endl;
    }
};

// 抽象工厂
class IFactory{
public:
    virtual IUser* CreateUser() = 0;
    virtual IDepartment* CreateDepartment() = 0;
};

// ACCESS 工厂
class AccessFactory : public IFactory{
public:
    virtual IUser* CreateUser(){
        return new CAccessUser();
    }
    virtual IDepartment* CreateDepartment(){
        return new CAccessDepartment();
    }
};

// SQL 工厂
class SqlFactory : public IFactory{
public:
    virtual IUser* CreateUser(){
        return new CSqlUser();
    }
    virtual IDepartment* CreateDepartment(){
        return new CSqlDepartment();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    IFactory* factory = new SqlFactory();
    IUser* user = factory->CreateUser();
    IDepartment* department = factory->CreateDepartment();
    user->GetUser();
    department->GetDepartment();

    return 0;
}