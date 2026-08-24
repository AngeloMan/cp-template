def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

def solve():
    # a, b = map(int ,input().split())
    # print(a + b)

t = 1
t = int(input())
for c in range(t): solve()