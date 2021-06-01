#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    int max_bits = 22;
    vector<int> A(N);
    vector<int> cnt(1 << max_bits);
    int rev = (1 << max_bits) - 1;
    for(int i=0;i<N;i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    vector<int> ans(1 << max_bits, -1);

    for(int mask = 0; mask < (1 << max_bits); mask++) {
        if(cnt[mask]) {
            ans[mask] = mask;
        }
    }

    for(int i=0;i<max_bits;i++) {
        for(int mask = 0; mask < (1 << max_bits); mask++) {
            if((mask & (1 << i))) {
                int submask = mask ^ (1 << i);
                ans[mask] = max(ans[mask], ans[submask]);
            }
        }
    }

    for(auto element : A) {
        cout << ans[element^rev] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}