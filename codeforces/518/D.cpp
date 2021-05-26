#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, T;
    double P;
    cin >> N >> P >> T;

    vector<vector<double>> dp(N + 1, vector<double>(T + 1));
    dp[0][0] = 1;

    for(int time = 1; time <= T; time++) {
        for(int person = 0; person <= N; person++) {
            if(person != 0)
                dp[person][time] += dp[person - 1][time - 1] * P;
            if(person != N)
                dp[person][time] += dp[person][time - 1] * (1 - P);
            else 
                dp[person][time] += dp[person][time - 1];
        }
    }
    
    double expected_value = 0;
    for(int i=0;i<=N;i++) {
        expected_value += i * dp[i][T];
    }

    cout << setprecision(15) << fixed << expected_value;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}