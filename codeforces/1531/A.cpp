#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    string ans = "blue";

    bool locked = false;
    
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if(s == "lock") {
            locked = true;
        } else if(s == "unlock") {
            locked = false;
        } else {
            if(!locked) {
                ans = s;
            }
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}