# DumPy

A C matrix library with a python wrapper class. 

Next Steps

- implement cache efficient transpose
- add blocking to speed up matmul

# Code Example

```
import dumpy as dp

# creates two 100 x 100 sized matrices with random values
A = dp.rand(100)
B = dp.rand(100)

# multiplies A and B and stores the value into C
C = A @ B

```