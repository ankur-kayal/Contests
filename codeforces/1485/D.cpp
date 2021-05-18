#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int magic = 720720;

void run_cases() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0)), B(N, vector<int>(M, 0));
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> A[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if((i + j) % 2 == 0) {
                B[i][j] = magic;
            } else {
                B[i][j] = magic + A[i][j] * A[i][j] * A[i][j] * A[i][j];
            }
        }
    }


    for(auto u: B) {
        for(auto v: u) {
            cout << v << " ";
        }
        cout << '\n';
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