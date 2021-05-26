#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int64_t count_multiples_in_ranges(int64_t l, int64_t r, int64_t p) {
    return r / p - (l - 1) / p;
}

void run_cases() {
    int64_t N, P;
    cin >> N >> P;
    vector<pair<int64_t, int64_t>> ranges(N + 1);

    for(int i=0;i<N;i++) {
        cin >> ranges[i].first >> ranges[i].second;
    }
    ranges[N] = ranges[0];

    double expected_value = 0;

    for(int i=0;i<N;i++) {
        double count1 = count_multiples_in_ranges(ranges[i].first, ranges[i].second, P);
        double length1 = ranges[i].second - ranges[i].first + 1;
        double count2 = count_multiples_in_ranges(ranges[i + 1].first, ranges[i + 1].second, P);
        double length2 = ranges[i + 1].second - ranges[i + 1].first + 1;
        expected_value += (count1 * length2 + count2 * length1 - count1 * count2) / (length2 * length1) * 2000;
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