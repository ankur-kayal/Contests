#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n, m;
    cin >> n >> m;
    string A, B;
    cin >> A >> B;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = max(dp[i-1][j-1] + 2, dp[i][j]);
            } else {
                dp[i][j] = max(0, max(dp[i-1][j], dp[i][j-1]) - 1);

            }
        }
    }

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}