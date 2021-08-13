#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int l = 0, r = 1e9+7;
    int position1 = 1, position2 = N;

    continue_binary_search: while(r > l + 1) {
        int m = (r + l) / 2;

        vector<bool> masks(1 << M);
        vector<int> pos(1 << M, -1);

        for(int i = 0; i < N; i++) {
            int mask = 0;
            for(int j = 0; j < M; j++) {
                if(A[i][j] >= m) {
                    mask += (1 << j);
                }
            }
            masks[mask] = true;
            pos[mask] = i + 1;
        }

        for(int i = 0; i < (1 << M); i++) {
            for(int j = i; j < (1 << M); j++) {
                if(masks[i] && masks[j] && ((i | j) == (1 << M) - 1)) {
                    position1 = pos[i], position2 = pos[j];
                    l = m;
                    goto continue_binary_search;
                }
            }
        }

        r = m;
    }

    cout << position1 << " " << position2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}