# Each digit in n must be less than or equal to floor(9 / k)
# for k * n not to carry over
MOD = int(1e9 + 7)
t = int(input())
for _ in range(t):
    l, r, k = map(int, input().split())
    print((((pow( 9 // k + 1, r, MOD) - pow(9 // k + 1, l, MOD)) + MOD) % MOD))