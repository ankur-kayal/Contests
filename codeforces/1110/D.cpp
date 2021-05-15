#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int64_t INF = 1e9+5;

void run_cases() {
    int N, M;
    cin >> N >> M;

    vector<int64_t> tiles(M + 10);
    for(int i=0;i<N;i++) {
        int foo;
        cin >> foo;
        tiles[foo]++;
    }

    vector<vector<int64_t>> dp(3, vector<int64_t>(3, -INF));
    vector<vector<int64_t>> next_dp(3, vector<int64_t>(3, 0));

    dp[0][0] = 0;

    for (int a = 1; a <= M; a++) {
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                next_dp[x][y] = -INF;
 
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                for (int z = 0; z < 3; z++)
                    if (tiles[a] >= x + y + z && tiles[a + 1] >= y + z && tiles[a + 2] >= z) {
                        int remaining = tiles[a] - (x + y + z);
                        next_dp[y][z] = max(next_dp[y][z], dp[x][y] + z + remaining / 3);
                    }
 
        dp = next_dp;
    }


    int64_t answer = 0;
 
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            answer = max(answer, dp[x][y]);
 
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}