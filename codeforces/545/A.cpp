#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> A[i][j];
        }
    }

    vector<bool> mark(n, true);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(A[i][j] == -1) {
                continue;
            }
            if(A[i][j] == 1) {
                mark[i] = false;
            } else if(A[i][j] == 2) {
                mark[j] = false;
            } else if(A[i][j] == 3) {
                mark[i] = false;
                mark[j] = false;
            }
        }
    }

    cout << count(mark.begin(), mark.end(), true) << '\n';
    for(int i=0;i<n;i++) {
        if(mark[i]) cout << i + 1 << " ";
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