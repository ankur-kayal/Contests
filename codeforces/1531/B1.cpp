#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    map<int64_t, int64_t> cnt;
    map<pair<int64_t, int64_t>, int> uq;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int64_t h, w;
        cin >> h >> w;
        if(h > w) {
            swap(h, w);
        }
        ans += cnt[h];
        cnt[h]++;
        if(w != h) {
            ans += cnt[w];
            cnt[w]++;
            ans -= uq[{h, w}];
        }
        uq[{h, w}]++;
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