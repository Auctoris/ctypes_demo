"""test.py - demo of using a c++ class from within Python"""
from foo import Foo

# We'll create a Foo object with a value of 5...
f = Foo(5)

# Calling f.bar() will print a message including the value...
print('f=Foo(5)')
print('f.bar() = {}'.format(f.bar()))

# Now we'll use foobar to add a value to that stored in our Foo object, f
print("f.foobar(7) = {}".format(f.foobar(7)))

# Now we'll do the same thing - but this time demonstrate that it's a normal
# Python integer...

x = f.foobar(2)
print("Type of x; where x = f.foobar(2) is {}".format(type(x)))
