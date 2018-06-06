#include <iostream>
#include <string>
using namespace std;

class Memo;

class Originator{
public:
    string state;
    Memo* CreateMemo();
    void SetMemo(Memo* memo);
    void Show(){
        cout << "state: " << state << endl;
    }
};

class Memo{
public:
    string state;
    Memo(string strState){
        state = strState;
    }
};

Memo* Originator::CreateMemo() {
    return new Memo(state);
}

void Originator::SetMemo(Memo *memo) {
    state = memo->state;
}

class Caretaker{
public:
    Memo* memo;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Originator* on = new Originator();
    on->state = "on";
    on->Show();

    Caretaker* c = new Caretaker();
    c->memo = on->CreateMemo();

    on->state = "off";
    on->Show();

    on->SetMemo(c->memo);
    on->Show();

    return 0;
}