#include <iostream>

// A simple class with a constuctor and one method...

class Foo
{
    public:
        Foo(int);
        void bar();
    private:
        int val;
};

Foo::Foo(int n)
{
    val = n;
}

void Foo::bar()
{
    std::cout << "Value is " << val << std::endl;
}

// Define C functions for the C++ class - as ctypes can only talk to C...

extern "C"
{
    Foo* Foo_new(int n) {return new Foo(n);}
    void Foo_bar(Foo* foo) {foo->bar();}
}

