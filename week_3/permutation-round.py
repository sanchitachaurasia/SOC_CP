import sys
from math import gcd
sys.setrecursionlimit(1 << 25)

MOD = int(1e9 + 7)

def lcm(a, b):
    return (a // gcd(a, b)) * b 

def main():
    n = int(input())
    given = list(map(int, input().split()))
    already_calculated = [False] * n
    ans = 1

    for i in range(n):
        if not already_calculated[i]:
            find = given[i]
            k = 1
            already_calculated[i] = True
            
            idx = given[i]
            while find != given[idx - 1]:
                k += 1
                already_calculated[idx - 1] = True
                idx = given[idx - 1]
            ans = lcm(k, ans)

    print(ans%MOD)

if __name__ == "__main__":
    main()

