#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int64_t> A(N);

    for(auto &u: A)
        cin >> u;

    auto score = [&](int index) -> int {
        if(index <= 0 || index >= N - 1) {
            return 0;
        }
        if(A[index] < A[index - 1] && A[index] < A[index + 1]) {
            return 1;
        }
        if(A[index] > A[index - 1] && A[index] > A[index + 1]) {
            return 1;
        }
        return 0;
    };

    int base = 0;
    for(int i=0;i<N;i++) {
        base += score(i);
    }

    int best = base;

    for(int i=0;i<N;i++) {
        int original = A[i];
        vector<int> candidates;

        if (i > 0) {
            candidates.push_back(A[i - 1]);
        }
 
        if (i < N - 1) {
            candidates.push_back(A[i + 1]);
        }
 
        int without = base - score(i - 1) - score(i) - score(i + 1);
 
        for (int x : candidates) {
            A[i] = x;
            best = min(best, without + score(i - 1) + score(i) + score(i + 1));
        }
 
        A[i] = original;

    }

    cout << best << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}