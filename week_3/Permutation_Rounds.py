import sys

MOD = 10**9 + 7

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return (a // gcd(a, b)) * b

def main():
    data = sys.stdin.read().strip().split()
    n = int(data[0])
    steps = list(map(int, data[1:]))

    found = [False] * n
    cycles = []

    for i in range(n):
        if not found[i]:
            count = 1
            found[i] = True
            # Move to next index in the cycle
            a = steps[i] - 1
            while a != i:
                found[a] = True
                a = steps[a] - 1
                count += 1
            cycles.append(count)

    ans = 0
    # Calculate the answer based on the cycles
    if len(cycles) == 1:
        ans = cycles[0]
    else:
        lcm_val = cycles[0]
        for cycle in cycles[1:]:
            lcm_val = lcm(lcm_val, cycle)
        ans = lcm_val

    print(ans%MOD)

if __name__ == "__main__":
    main()