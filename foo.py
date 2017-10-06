"""foo.py – a simple demo of importing a calss from C++"""
import ctypes

lib = ctypes.cdll.LoadLibrary('./libfoo.so')

class Foo(object):
    """The Foo class supports two methods, bar, and foobar..."""
    def __init__(self, val):
        lib.Foo_new.argtypes = [ctypes.c_int]
        lib.Foo_new.restype = ctypes.c_void_p

        lib.Foo_bar.argtypes = [ctypes.c_void_p]
        lib.Foo_bar.restype = ctypes.c_char_p

        lib.Foo_foobar.argtypes = [ctypes.c_void_p, ctypes.c_int]
        lib.Foo_foobar.restype = ctypes.c_int

        self.obj = lib.Foo_new(val)


    def bar(self):
        """bar returns a string continaing the value"""
        return (lib.Foo_bar(self.obj)).decode()


    def foobar(self, val):
        """foobar takes an integer, and adds it to the value in the Foo class
        - returning the result"""
        return lib.Foo_foobar(self.obj, val)
