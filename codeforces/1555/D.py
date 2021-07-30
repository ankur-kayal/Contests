from sys import stdin, stdout

def getP(j):
    if j>=3:
        l = j-3
        return 3 + (l+1)%3
    else:
        return (j+1)%3

def solve(st, n, m):
    ## preprocess
    ## type ab, bc, ca, ac, cb, ba
    pref = [[0]*(n+1) for i in range(6)]
    match = 'abcacb'
    for j in range(n-1, -1, -1):
        for i in range(6):
            pref[i][j] = 1 + pref[getP(i)][j+1]
            if match[i] == st[j]:
                pref[i][j] -= 1

    def get(ind, l, r):
        ln = r-l+1
        p = None
        if ind >= 3: p =  3 + (ind + ln) % 3
        else       : p = (ind + ln)%3
        #print("ind and partner", ind, p)
        change = pref[ind][l-1] - pref[p][r]
        #print("for", ind, l, r, change)
        return change

    for q in range(m):
        l, r = map(int, input().split())
        ans = float("inf")
        for i in range(6):
            ans = min(ans, get(i, l, r))
        stdout.write(str(ans) + '\n')
input = stdin.readline
n, m = map(int, input().split())
st = input()
solve(st, n, m)