#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    vector<int64_t> diffs;
    for(int i=1;i<N;i++) {
        diffs.push_back(A[i - 1] - A[i]);
    }

    sort(diffs.begin(), diffs.end());

    int64_t ans = A[N - 1] - A[0];

    for(int i=0;i<K - 1;i++) {
        ans += diffs[i];
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}