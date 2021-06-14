def main():
    def input(): return sys.stdin.readline().strip("\n")
    def I():    return (input())
    def II():    return (int(input()))
    def MI():    return (map(int,input().split()))
    def LI():    return (list(map(int,input().split())))
    def isPerfectSquare(x): return (int(math.sqrt(x))**2 == x)
    sys.setrecursionlimit(500000)
    from collections import OrderedDict
    MOD = 10**9 + 7
    def dfs(x):
        if not visited[x]:
            visited[x] = 1
            dfs(graph[x])
    for _ in range(II()):
        n = II()
        a = LI()
        b = LI()
        graph = {}
        visited = [0]*(n+1)
        for i in range(n):
            graph[a[i]] = b[i]
        ans = 1
        for i in range(n):
            if visited[a[i]] == 0:
                dfs(a[i])
                ans = (ans * 2) % MOD
        print(ans)


if __name__ == "__main__":
    import sys, threading
    import bisect
    import math
    import itertools
    from sys import stdout
 
    ############  Sorted Containers  ######################
    import heapq
    from queue import PriorityQueue
 
    ############ Tree Problems ( Use Python 3) ###########
    sys.setrecursionlimit(2 ** 32 // 2 - 1)
    threading.stack_size(1 << 27)
 
    input = sys.stdin.readline
    thread = threading.Thread(target=main)
    thread.start()
    thread.join()