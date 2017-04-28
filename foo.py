import ctypes

lib = ctypes.cdll.LoadLibrary('./libfoo.so')

class Foo(object):
    def __init__(self, val):
        lib.Foo_new.argtypes = [ctypes.c_int]
        lib.Foo_new.restype = ctypes.c_void_p

        lib.Foo_bar.argtypes = [ctypes.c_void_p]
        lib.Foo_bar.restype = ctypes.c_void_p

        self.obj = lib.Foo_new(val)

    def bar(self):
        lib.Foo_bar(self.obj)

