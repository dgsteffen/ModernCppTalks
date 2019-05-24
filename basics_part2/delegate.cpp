#include <iostream>
#include <string>

using namespace std;

struct X {
    int a;
    void validate(int i) { a=i; }
public:

    X(int x)  { validate(x); throw 2; }
    X()         : X{42} {}
    X(string s) : X{s.size()} { }


    ~X() { cout <<"dtor" << endl;}

};

int main() {
    try 
    {
        X a("ai");

    } 
    catch (int i) 
    {
        cout << "Caught " << i << endl;
    }
}
