#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t X;
    cin >> X;

    int64_t a = 1e18;
    for(int64_t i=1;i*i<=X;i++) {
        if(X % i == 0) {
            if(lcm(i, X / i) == X) {
                a = i;
            }
        }
    }
    cout << a << " " << X / a << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}