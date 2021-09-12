#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n, m;
    cin >> n >> m;

    int inconvenience = 0;

    vector<int> a(m);

    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<pair<int,int>> order;

    for(int i = 0; i < m; i++) {
        order.emplace_back(a[i], -i);
    }

    sort(order.begin(), order.end());

    vector<bool> seats(m, false);

    for(auto [_, seat_id]: order) {
        for(int i = 0; i < -seat_id; i++) {
            if(seats[i]) {
                inconvenience++;
            }
        }
        seats[-seat_id] = true;
    }

    cout << inconvenience << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}