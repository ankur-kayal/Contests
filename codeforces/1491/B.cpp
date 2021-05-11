#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t n, u, v;
    cin >> n >> u >> v;
    vector<int64_t> a(n);
    for(auto &u: a)
        cin >> u;

    int64_t cost = 1e18;;
    for(int i=0;i+1<n;i++) {
        if(abs(a[i] - a[i+1]) == 1) {
            cost  = min({cost, u, v});
        } else if(a[i] == a[i + 1]) {
            cost = min({cost, u + v, v + v});
        } else {
            cost = 0;
        }
    }
    cout << cost << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}