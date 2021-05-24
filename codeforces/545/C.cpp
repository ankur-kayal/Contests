#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int64_t INF = 1e17;

void run_cases() {
    int N;
    cin >> N;
    vector<array<int64_t, 2>> vals(N + 2); // x_i, h_i
    for(int i=1;i<=N;i++) {
        cin >> vals[i][0] >> vals[i][1];
    }
    vals[0] = {-INF, 0};
    vals[N + 1] = {INF, 0};

    vector<vector<int64_t>> dp(N + 2, vector<int64_t>(3, 0)); // 0->left, 1->right, 2->still
    
    for(int i=1;i<=N;i++) {
        // fall left
        if(vals[i][0] - vals[i][1] > vals[i-1][0]) {
            dp[i][0] = max({dp[i][0], dp[i-1][2] + 1, dp[i-1][0] + 1});
        }
        if(vals[i][0] - vals[i][1] > vals[i-1][0] + vals[i-1][1]) {
            dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
        }

        // fall right
        if(vals[i][0] + vals[i][1] < vals[i+1][0]) {
            dp[i][1] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
        }

        // do nothing
        dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
    }


    cout << *max_element(dp[N].begin(), dp[N].end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}