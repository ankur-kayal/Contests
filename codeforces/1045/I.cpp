#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    int64_t ans = 0;

    unordered_map<int64_t, int64_t> cnt;

    vector<int> masks;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int64_t mask = 0;

        for(auto u: s) {
            mask ^= (1 << (u - 'a'));
        }

        masks.push_back(mask);
        cnt[mask]++;
    }

    sort(masks.begin(), masks.end());
    masks.erase(unique(masks.begin(), masks.end()), masks.end());

    for(auto mask: masks) {
        // find complementary masks that on xor gives atmost 1 set bit
        vector<int> used_bits, unused_bits;

        for(int bit = 0; bit < 26; bit++) {
            if(mask >> bit & 1) {
                used_bits.push_back(bit);
            } else {
                unused_bits.push_back(bit);
            }
        }

        ans += cnt[mask] * (cnt[mask] - 1);
        for(int bit : used_bits) {
            ans += cnt[mask ^ (1 << bit)] * cnt[mask];
        }
        for(int bit : unused_bits) {
            ans += cnt[mask ^ (1 << bit)] * cnt[mask];
        }

    }

    cout << ans / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}