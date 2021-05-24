#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    vector<string> A(2);
    cin >> A[0] >> A[1];

    int N = A[0].length();

    int turn = 0;
    string ans = "";

    for(int i=0;i<N;i++) {
        if(A[0][i] == A[1][i]) {
            ans += A[0][i];
        } else {
            ans += A[turn][i];
            turn ^= 1;
        }
    }

    if(turn == 1) {
        cout << "impossible";
    } else {
        cout << ans << '\n';
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