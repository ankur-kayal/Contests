import math
n = int(input())
n = n//2 - 1

print(math.factorial(2*n+1) // (n+1))