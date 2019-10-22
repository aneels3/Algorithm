# N represents victims
# K represents hitmen
N, K = map(int, input().split())
cost = []

MASK = 2<<K
INF = 10**8-1

for i in range(K):
    prices = [int(i) for i in input().split()]
    prices.reverse()
    cost.append(prices)

# dp stores possibilities
dp = []
for i in range(MASK):
    dp.append([INF] * (N + 1))

dp[0][0] = 0

def hitman_available(hitman, mask):
    return not (2 << hitman) & mask

def use_hitman(hitman, mask):
    return mask | (2 << hitman)

for already_killed in range(0, N):
    for mask in range(0, MASK):
        for hitman in range(0, K):
            if hitman_available(hitman, mask):
                mask_after = use_hitman(hitman, mask)
                for num_to_kill in range(1, N - already_killed+1):
                    dp[mask_after][num_to_kill + already_killed] = min(
                        dp[mask_after][num_to_kill + already_killed],
                        dp[mask][already_killed] + sum(cost[hitman][already_killed:already_killed+num_to_kill]))

print(min(dp[i][N] for i in range(MASK)))
