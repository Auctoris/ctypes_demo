#include <iostream>
#include <cstring>
#include <cstdlib>

// A simple class with a constuctor and some methods...

class Foo
{
    public:
        Foo(int);
        const char* bar();
        int foobar(int);
    private:
        int val;
};

Foo::Foo(int n)
{
    val = n;
}

const char* Foo::bar()
{
    int i;
    std::string s;
    std::string msg;
    
    s = std::to_string(val);
    msg = "The value is " + s;
    i = msg.length();
    const char* rv = msg.c_str();
    return rv;
}

int Foo::foobar(int n)
{
    return val + n;
}

// Define C functions for the C++ class - as ctypes can only talk to C...

extern "C"
{
    Foo* Foo_new(int n) {return new Foo(n);}
    const char* Foo_bar(Foo* foo) {return foo->bar();}
    int Foo_foobar(Foo* foo, int n) {return foo->foobar(n);}
}

