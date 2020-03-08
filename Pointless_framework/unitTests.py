''' Placeholder for Unit Testing in C '''
from ctypes import *

def ASSERT_EQUAL(var1, var2) -> bool:
    if var1 == var2:
        return True
    else:
        return False

def ASSERT_NOT_EQUAL(var1, var2) -> bool:
    if var1 != var2:
        return True
    else:
        return False

