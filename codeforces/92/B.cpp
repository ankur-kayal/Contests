#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s;
    cin >> s;
    int operations = 0;

    while(s.size() != 1) {
        if(s.back() == '0') {
            operations++;
            s.pop_back();
        } else {
            operations++;
            int times = 0;
            while(!s.empty() && s.back() == '1') {
                s.pop_back();
                times++;
            }
            if(!s.empty()) {
                s.pop_back();
            }
            s.push_back('1');
            s += string(times, '0');
        }
    }

    cout << operations;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}