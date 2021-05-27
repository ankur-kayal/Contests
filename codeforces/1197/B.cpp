#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int> A(N);
    multiset<pair<int,int>> order;
    for(auto &u: A)
        cin >> u;

    for(int i=0;i<N;i++) {
        order.insert({i, A[i]});
    }

    vector<int> pos(N + 1);
    for(int i=0;i<N;i++) {
        pos[A[i]] = i;
    }

    for(int i=N;i>1;i--) {
        auto it = order.find({pos[i], i});
        if(next(it) != order.end()) {
            if(next(it)->second == i - 1) {
                order.erase(order.find({pos[i], i}));
                order.erase(order.find({pos[i - 1], i - 1}));
                pos[i - 1] = pos[i];
                order.insert({pos[i - 1], i - 1});
                continue;
            }
        }
        if(it != order.begin()) {
            if(prev(it)->second == i - 1) {
                order.erase(order.find({pos[i], i}));
                order.erase(order.find({pos[i - 1], i - 1}));
                pos[i - 1] = pos[i];
                order.insert({pos[i - 1], i - 1});
                continue;
            }
        }
        cout << "NO";
        return;
    }

    cout << "YES";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}