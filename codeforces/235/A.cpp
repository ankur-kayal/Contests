#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int64_t unity = 1;

int64_t get_lcm(int64_t i, int64_t j, int64_t k) {
    int64_t ans = lcm(lcm(i, j), k);
    return ans;
}

void run_cases() {
    int64_t N;
    cin >> N;

    int64_t ans = 1;
    for(int i = N; i >= max(unity, N - 100); i--) {
        for(int j = N; j >= max(unity, N - 100); j--) {
            for(int k = N; k >= max(unity, N - 100); k--) {
                ans = max(ans, get_lcm(i, j, k));
            }
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