#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    
    for(auto &u: A) 
        cin >> u;

    int ans = 0;
    int64_t health = 0;

    vector<int64_t> pq;
    make_heap(pq.begin(), pq.end());

    for(int i=0;i<N;i++) {
        health += A[i];
        ans++;
        pq.push_back(-A[i]);
        push_heap(pq.begin(), pq.end());

        while(health < 0) {
            health += pq.front();
            pop_heap(pq.begin(), pq.end());
            pq.pop_back();
            ans--;
        }
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}