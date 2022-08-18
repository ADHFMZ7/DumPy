import dumpy as dp
import numpy as np
from time import perf_counter as pf

SIZE = 10


dpstart = pf()
A = dp.rand(SIZE)
dpend = pf()
B = dp.rand(SIZE)
print(f"dp time to create {SIZE ** 2} elements: {dpend - dpstart}")


npstart = pf()
C = np.random.rand(SIZE, SIZE)
npend = pf()
D = np.random.rand(SIZE, SIZE)
print(f"np time to create {SIZE ** 2} elements: {npend - npstart}")


for i, row in enumerate(C):
    for j, val in enumerate(row):
        A[i, j] = val

for i, row in enumerate(D):
    for j, val in enumerate(row):
        B[i, j] = val



npstart = pf()
E = C @ D
npend = pf()

print(f"np time to multiply: {npend - npstart}")
dpstart = pf()
F = A @ B
dpend = pf()

print(E)

#print(E)

print(F)

print(f"dp time to multiply: {dpend - dpstart}")

