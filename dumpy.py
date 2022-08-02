from ctypes import *
from random import random 


#    TODO: 
# - Implement 
#
# 
# 

lib = CDLL('./matrix.so')

class Matrix(Structure):
    _field_ = [
        ("N", c_int),
        ("entries", POINTER(POINTER(c_float)))
               ]
    
    def __repr__(self):
        print('\n')
        lib.print(self)
        return ''
    
eye = lib.eye
eye.argtypes = [c_int]    
eye.restype = POINTER(Matrix)

create = lib.create
create.argtypes = [c_int]
create.restype = POINTER(Matrix)

matmul = lib.matmul
matmul.argtypes = [POINTER(Matrix), POINTER(Matrix)]
matmul.restype = POINTER(Matrix)

floatmul = lib.floatmul
floatmul.argtypes = [POINTER(Matrix), c_float]
floatmul.restype = POINTER(Matrix)

matadd = lib.matadd
matadd.argtypes = [POINTER(Matrix), POINTER(Matrix)]
matadd.restype = POINTER(Matrix)

floatadd = lib.floatadd
floatadd.argtypes = [POINTER(Matrix), c_float]
floatadd.restype = POINTER(Matrix)

getn = lib.getn
getn.argtypes = [POINTER(Matrix)]
getn.restype = c_int

at = lib.at
at.argtypes = [POINTER(Matrix), c_int, c_int]
at.restype = c_float


class dumpy:

    def __init__(self, N, identity=False, mat=None):
        if mat:
            self.Mat = pointer(mat)
            self.N = getn(mat)
        elif identity:
            self.Mat = eye(N) 
            self.N = N
        else:
            self.Mat = create(N)
            self.N = N
          
    def __repr__(self):
        print('\n')
        lib.print(self.Mat)
        return ''
     
    def __matmul__(self, B):
        if type(B) != type(self):
            raise TypeError
        C = matmul(self.Mat, B.Mat)
        return matrix(C.contents)
         
    def __add__(self, B):
        if isinstance(B, dumpy):
            C = matadd(self.Mat, B.Mat)
        elif isinstance(B, int) or isinstance(B, float):
            C = floatadd(self.Mat, B)
        elif isinstance(B, Matrix):  
            C = matadd(self.mat, B)  
        else:  
            raise TypeError
        return matrix(C.contents)
     
    def __radd__(self, B):
        C = self + B 
        return C

    def __mul__(self, B):
        if isinstance(B, dumpy):
            C = matmul(self.Mat, B.Mat)
        elif isinstance(B, int) or isinstance(B, float):
            C = floatmul(self.Mat, B)
        elif isinstance(B, Matrix):  
            C = matmul(self.mat, B) 
        else:
            raise TypeError
        return matrix(C.contents)
    
    def __len__(self):
        return getn(self.mat) ** 2



def matrix(Mat):
    C = dumpy(getn(Mat), mat=Mat)
    return C
    
    
    
if __name__ == '__main__': 
    # A = Matrix()
    # A = dumpy(9, identity=True)           
    # B = dumpy(9)
    # print(type(A.Mat))
    # print(B)
    # print(A@B)
    
    
    A = [[random() for i in range(10)] for j in range(10)]
    m = Matrix(10, A)
