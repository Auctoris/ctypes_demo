#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

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
    std::string s;
    std::string msg;
    
    s = std::to_string(val);
    msg = "The value is " + s;
    const char* rv = msg.c_str();
    // return rv;
    return "Something that isn't deallocated";
}

int Foo::foobar(int n)
{
    return val + n;
}

// Define C functions for the C++ class - as ctypes can only talk to C...

extern "C"
{
    __declspec(dllexport) Foo* Foo_new(int n) {return new Foo(n);}
    __declspec(dllexport) const char* Foo_bar(Foo* foo) {return foo->bar();}
    __declspec(dllexport) int Foo_foobar(Foo* foo, int n) {return foo->foobar(n);}
    __declspec(dllexport) void Foo_delete(Foo* foo)
    {
        if (foo)
        {
            delete foo;
            foo = nullptr;
        }
    }
}
