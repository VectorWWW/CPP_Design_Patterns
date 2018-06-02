#include <iostream>
using namespace std;
// 基类 存放数据
class COperation{
public:
    int m_nFirst;
    int m_nSecond;
    virtual double GetResult(){
        double dResult = 0;
        return dResult;
    }
};
// 派生类存放操作
// 加法
class AddOperation : public COperation{
public:
    virtual double GetResult(){
        return m_nFirst + m_nSecond;
    }
};
// 减法
class SubOperation : public COperation{
public:
    virtual double GetResult(){
        return m_nFirst - m_nSecond;
    }
};
// 工厂类
class CCalculatorFactory{
public:
    static COperation* Create(char cOperator);
};

COperation *CCalculatorFactory::Create(char cOperator) {
    COperation *oper;
    switch (cOperator){
        case '+':
            oper = new AddOperation();
            break;
        case '-':
            oper = new SubOperation();
        default:
            oper = new AddOperation();
            break;
    }
    return oper;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    int a, b;
    cin >> a >> b;
    COperation* op = CCalculatorFactory::Create('-');
    op->m_nFirst = a;
    op->m_nSecond = b;
    cout << op->GetResult() << endl;
    return 0;
}