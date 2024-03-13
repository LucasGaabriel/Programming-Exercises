def longest_common_subsequence(s, t):
    m, n = len(s), len(t)
    dp = [[0]*(n+1) for i in range(m+1)]
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s[i - 1] == t[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    lcs = ""
    i, j = m, n
    while i > 0 and j > 0:
        if s[i - 1] == t[j - 1]:
            lcs = (s[i - 1] + lcs)
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    
    return lcs

s = input()
t = input()
print(longest_common_subsequence(s, t))
