from ctypes import cdll
lib = cdll.LoadLibrary('./libfoo.so')

class Foo(object):
    def __init__(self, val):
        self.obj = lib.Foo_new(val)

    def bar(self):
        lib.Foo_bar(self.obj)

