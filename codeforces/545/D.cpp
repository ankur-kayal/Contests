#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;
    sort(A.begin(), A.end());

    int64_t sum = 0;
    int served = 0;
    for(int i=0;i<N;i++) {
        if(sum <= A[i]) {
            served++;
            sum += A[i];
        }
    }
    cout << served << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}