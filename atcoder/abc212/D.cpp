#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define nl '\n'

void run_cases() {
    int Q;
    cin >> Q;

    int64_t to_add = 0;

    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;

    for(int i = 0; i < Q; i++) {
        int ch;
        cin >> ch;

        if(ch == 1) {
            int64_t X;
            cin >> X;
            X -= to_add;
            pq.push(X);
        } else if(ch == 2) {
            int64_t X;
            cin >> X;
            to_add += X;
        } else {
            cout << pq.top() + to_add << '\n';
            pq.pop();
        }
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