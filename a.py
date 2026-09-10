def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

def exp(a, b):
    if b == 0: return 1
    if b & 1: return min(int(1e18) + 1, exp(a, b - 1) * a)
    z = exp(a, b//2)
    return min(int(1e18) + 1, z * z)

def solve():
    ...
    
t = 1
# t = int(input())
for c in range(t): solve()