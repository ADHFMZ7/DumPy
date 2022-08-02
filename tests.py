from dumpy import dumpy as dp


A = dp(10, identity=True)

B = dp(10, identity=True)

C = A + B  @ (dp(10, identity=True) + 20) * 105

print(C)