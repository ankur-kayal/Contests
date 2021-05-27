#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &u: A) {
        cin >> u;
    }   

    int l = 0, r = N + 100;

    auto good = [&](int m) -> bool {
        int base = 0, steps = 0;
        for(int i=0;i<N;i++) {
            if(A[i] >= m + 1 && base < 2) {
                base++;
            } else if(A[i] >= 1) {
                steps++;
            }
        }
        return base == 2 && steps >= m;
    };

    while(r > l + 1) {
        int m = (r + l) / 2;

        if(good(m)) {
            l = m;
        } else {
            r = m;
        }
    } 
    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}