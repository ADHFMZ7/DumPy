import dumpy as dp
import numpy as np
from time import perf_counter as pf

SIZE = 4096 


dpstart = pf()
A = dp.rand(SIZE)
dpend = pf()

print(f"dp time to create {SIZE ** 2} elements: {dpend - dpstart}")

B = dp.rand(SIZE)

npstart = pf()
C = np.random.rand(SIZE, SIZE)
npend = pf()

D = np.random.rand(SIZE, SIZE)

print(f"np time to create {SIZE ** 2} elements: {npend - npstart}")


dpstart = pf()
A @ B
dpend = pf()

print(f"dp time to multiply: {dpend - dpstart}")

npstart = pf()
C @ D
npend = pf()

print(f"np time to multiply: {npend - npstart}")
