import numpy as np

S = input()
T = input()
N = len(S)
M = len(T)

S1 = np.array(list(map(int, S)))
S2 = 1 - S1
T1 = np.array(list(map(int, reversed(T))))
T2 = 1 - T1

def conv(f, g):
    siz = len(f) + len(g) - 1
    siz = 1 << (siz - 1).bit_length()
    f = np.fft.rfft(f, siz)
    g = np.fft.rfft(g, siz)
    f *= g
    f = np.fft.irfft(f, siz)
    return np.rint(f).astype(np.int32)

A = conv(S1, T2) + conv(S2, T1)
print(np.min(A[M - 1 : N]))
