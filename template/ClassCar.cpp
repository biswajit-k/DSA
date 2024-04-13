#include<bits/stdc++.h>
using namespace std;


class A {

    public:
    void f1() {
        cout << "As f1 \n";
    }

};

class B: public A {

    public:
    void f1() {
        cout << "Bs f1 \n";
    }

};

// how to overload f1 in A and B

int main(){

    A obj = B();

    obj.f1();

    return 0;
}
