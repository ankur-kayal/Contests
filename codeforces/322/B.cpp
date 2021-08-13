#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int r, g, b;
    cin >> r >> g >> b;

    int equal = min({r, g, b});
    r -= equal;
    g -= equal;
    b -= equal;

    int ans = equal + (r / 3 + g / 3 + b / 3);
    for(int i = 1; i < min(3, equal); i++) {
        ans = max(ans, equal - i + (r + i) / 3 + (g + i) / 3 + (b + i) / 3);
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